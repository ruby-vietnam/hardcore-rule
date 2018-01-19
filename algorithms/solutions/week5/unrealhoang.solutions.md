## Problem 1

```ruby
def get_row(row_index)
  cur_row = Array.new(row_index + 1, 0)
  cur_row[0] = 1

  (row_index + 1).times.each do |i|
    row = i + 1
    t = 0
    row.times.each do |j|
      tt = cur_row[j]
      cur_row[j] = cur_row[j] + t
      t = tt
    end
  end
  cur_row
end
```


## Problem 2

```ruby
def check_valid_string(s)
  count = 0
  count_star = 0
  s.chars.each do |c|
    if c == '(' then
      count += 1
    elsif c == ')' then
      count -= 1
    elsif c == "*" then
      count_star += 1
    end
    if count + count_star < 0 then
      return false
    end
  end
  count = 0
  count_star = 0
  s.chars.reverse.each do |c|
    if c == '(' then
      count += 1
    elsif c == ')' then
      count -= 1
    elsif c == "*" then
      count_star += 1
    end
    if count - count_star > 0 then
      return false
    end
  end
  return true
end
```

## Problem 3

```rust
fn max_envelopes(mut envelopes: Vec<(i32, i32)>) -> i32 {
    envelopes.sort_by(|a, b| b.0.cmp(&a.0));
    let l = envelopes.len();
    let mut d = vec![1i32; l];

    for i in 1..l {
        for j in 0..i {
            if envelopes[j].0 > envelopes[i].0 && envelopes[j].1 > envelopes[i].1 {
                d[i] = std::cmp::max(d[i], d[j] + 1);
            }
        }
    }

    *d.iter().max().unwrap_or(&0)
}

fn main() {
    println!("Test: {:?}", max_envelopes(vec![ (1,3),(3,5),(6,7),(6,8),(8,4),(9,5) ]));
}
```
