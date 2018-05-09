use std::collections::HashMap;
use std::fmt::Debug;

#[derive(Debug, Clone)]
enum Value {
    Integer(i64),
    // String(String),
    Symbol(String),
    List(Vec<Value>),
}

#[derive(Debug)]
enum Bounded {
    Value(Value),
    Function(&'static Callable),
    Form(&'static Callable)
}

#[derive(Debug)]
struct ContextFrame<'a> {
    bindings: HashMap<String, Bounded>,
    parent: Option<&'a ContextFrame<'a>>,
}

impl<'a> ContextFrame<'a> {
    fn lookup(&self, key: &String) -> Option<&Bounded> {
        let mut cur_frame = self;
        loop {
            if let Some(b) = cur_frame.bindings.get(key) {
                return Some(b);
            } else {
                if let Some(frame) = cur_frame.parent {
                    cur_frame = &frame;
                } else {
                    return None;
                }
            }
        }

    }

    fn new(parent: Option<&'a ContextFrame>) -> ContextFrame<'a> {
        ContextFrame {
            bindings: HashMap::new(),
            parent: parent
        }
    }

    fn insert(&mut self, s: String, v: Bounded) {
        self.bindings.insert(s, v);
    }
}

trait Callable:Debug {
    fn call(&self, params: Vec<Value>, context: &ContextFrame) -> Value;
}

#[derive(Debug)]
struct Add;
#[derive(Debug)]
struct Mult;
#[derive(Debug)]
struct Binding;
use Value::*;

impl Callable for Binding {
    fn call(&self, mut params: Vec<Value>, context: &ContextFrame) -> Value {
        if params.len() != 2 { panic!("let form must have 3 elements") };
        if let List(mut bindings) = params.remove(0) {
            if bindings.len() % 2 == 1 { panic!("Binding must have even number of elements") }
            let mut new_frame = ContextFrame::new(Some(context));

            while let Some(expr) = bindings.pop() {
                if let Value::Symbol(ref s) = bindings.pop().unwrap() {
                    let value = eval(expr, context);
                    new_frame.insert(s.clone(), Bounded::Value(value));
                } else {
                    panic!("binding must be symbol");
                }
            }
            let expr = params.remove(0);
            let result = eval(expr, &new_frame);
            return result;
        } else {
            panic!("2nd element of let form must be list");
        }
    }
}

impl Callable for Add {
    fn call(&self, params: Vec<Value>, _context: &ContextFrame) -> Value {
        let mut sum = 0i64;
        for param in params {
            match param {
                Integer(i) => {
                    sum += i;
                },
                _ => { panic!("Cannot add non-Integer"); }
            }
        }

        Value::Integer(sum)
    }
}


impl Callable for Mult {
    fn call(&self, params: Vec<Value>, _context: &ContextFrame) -> Value {
        let mut product = 1i64;
        for param in params {
            match param {
                Integer(i) => {
                    product *= i;
                },
                _ => { panic!("Cannot mult non-Integer"); }
            }
        }

        Value::Integer(product)
    }
}

impl Value {
    fn parsable(s: &str) -> bool {
        s.parse::<i64>().is_ok()
    }

    fn parse(s: &str) -> Value {
        let i = s.parse::<i64>().unwrap();
        Value::Integer(i)
    }
}

fn unwrap_list(ast: Value) -> Value {
    match ast {
        List(mut list) => list.pop().expect("unwrapping empty list"),
        _ => { panic!("Unwrap list only works on list") }
    }
}

fn parse_list(s: &mut Iterator<Item=&str>) -> Value {
    let mut list = Vec::new();
    while let Some(token) = s.next() {
        if token == ")" { break }
        if token == "(" {
            let sub_list = parse_list(s);
            list.push(sub_list);
        } else {
            list.push(parse_token(token));
        }
    }
    return Value::List(list);
}

fn parse_token(token_str: &str) -> Value {
    if Value::parsable(token_str) {
        return Value::parse(token_str);
    }
    return Value::Symbol(token_str.to_owned());
}

fn eval(ast: Value, context: &ContextFrame) -> Value {
    match ast {
        Symbol(symbol) => {
            println!("Evaluating {:?}", symbol);
            let bounded = context.lookup(&symbol).expect("symbol not found");
            if let &Bounded::Value(ref v) = bounded {
                v.clone()
            } else {
                Symbol(symbol)
            }
        },
        List(mut list) => {
            if list.is_empty() {
                panic!("empty list");
            } else {
                let mut drain = list.drain(..);
                if let Value::Symbol(ref symbol) = drain.next().unwrap() {
                    println!("Evaluating {:?}", symbol);
                    let callable = context.lookup(symbol).expect("symbol not found");
                    match *callable {
                        Bounded::Value(_) => { panic!("first element in list not callable") },
                        Bounded::Form(callable) => {
                            let mut params = Vec::new();
                            for param in drain {
                                params.push(param);
                            }
                            callable.call(params, context)
                        },
                        Bounded::Function(callable) => {
                            let mut params = Vec::new();
                            for param in drain {
                                params.push(eval(param, context));
                            }
                            callable.call(params, context)
                        }
                    }
                } else {
                    panic!("first element must be symbol");
                }
            }
        },
        // if not list, return as is
        _ => ast,
    }

}

fn main() {
    let s = "( let ( x 2 ) ( mult x ( let ( x 3 y 4 ) ( add x y ) ) )";
    let mut tokens = s.split(" ");
    let raw_ast = parse_list(&mut tokens);
    let ast = unwrap_list(raw_ast);

    println!("parsed: {:?}", ast);
    let mut global_frame = ContextFrame::new(None);
    global_frame.insert(String::from("add"),  Bounded::Function(&Add));
    global_frame.insert(String::from("mult"), Bounded::Function(&Mult));
    global_frame.insert(String::from("let"),  Bounded::Form(&Binding));
    let result = eval(ast, &global_frame);
    println!("evaluated to: {:?}", result);

}
