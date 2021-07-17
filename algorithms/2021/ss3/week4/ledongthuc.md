# 1. Two Sum

 - With each item in `nums`,  check if any existing number equals `target-num`. They are pair number of result.

```go
func twoSum(nums []int, target int) []int {
    m := make(map[int]int)
    for index, value := range nums {
        m[value] = index
    }
    for index, value := range nums {
        remaining := target - value
        if index2, ok := m[remaining]; ok {
            if index == index2 {
                continue
            }
            return []int{index, index2}
        }
    }
    
    return []int{0, 0}
}
```

# 2. Valid Parentheses

 - Use stack to store closing characters "(, [, {" each we see any opening characters "), ], }"
 - After going through input string, if the stack is not empty, it's mean the string's invalid Parentheses

```go
func isValid(s string) bool {
    starts := map[string]struct{}{
        "(":struct{}{}, 
        "[":struct{}{}, 
        "{":struct{}{}, 
    }
    ends := map[string]struct{}{
        ")": struct{}{},
        "]": struct{}{},
        "}": struct{}{},
    }
    maps := map[string]string {
        ")":"(", 
        "]":"[", 
        "}":"{",
    }
    
    var stack StackString 
    for _, c := range s {
        _, ok := starts[string(c)]
        if ok {
            stack.Push(string(c))
        }
        _, ok = ends[string(c)]
        if ok {
            if stack.Length() == 0 || stack.Pop() != maps[string(c)] {
                return false
            }
        }
    }
    
    return stack.Length() == 0
}

type StackString struct {
    innerList []string
}

func (s *StackString) Length() int {
    return len(s.innerList)
}

func (s *StackString) Push(item string) {
    s.innerList = append(s.innerList, item)
}

func (s *StackString) Pop() string {
    v := s.innerList[len(s.innerList) - 1]
    s.innerList = s.innerList[0: len(s.innerList) -1]
    return v
}
```



# 3. Generate Parentheses

 - With any `n` is greater than 1, we can generate cases:
   - () + generate(n-1)
   - generate(n-1) + ()
   - ( generate(n-1) )
 - Use the recursion until n = 1.
 - Use hash map to avoid duplicated results

```go
func generateParenthesis(n int) []string {
    if n == 1 {
        return  []string{"()"}
    }
    
    m := map[string]struct{}{}
    for leftN := 1; leftN < n; leftN++ {
        leftResults := generateParenthesis(leftN)
        
        rightN := n - leftN
        rightResults := generateParenthesis(rightN)
        
        for _, leftResult := range leftResults {
            for _, rightResult := range rightResults {
                m[leftResult+rightResult] = struct{}{}
            }
        }
    }
    
    for _, subResult := range generateParenthesis(n-1) {
        m["(" + subResult + ")"] = struct{}{}
        
    }
    
    result := []string{}
    for r := range m {
        result = append(result, r)
    }
    
    return result
}
```

# 4. Sum of Two Integers

 - Use bitwise https://en.wikipedia.org/wiki/Adder_%28electronics%29#Half_adder

```go
// https://en.wikipedia.org/wiki/Adder_%28electronics%29#Half_adder
func getSum(a int, b int) int {
    var carry int
    for b != 0 {
        carry = a & b
        a = a ^ b
        b = carry << 1  
    }
    return a;
}
```
