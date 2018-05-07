Problem 1:

https://leetcode.com/problems/plus-one/description/#

```go
// Reuse array
func plusOne(digits []int) ( []int) {
    digits = append(digits, 1)
    for i := len(digits) - 1; i > 0 ; i-- {
        newDigit := digits[i] + digits[i-1]
        if newDigit < 10 {
            digits[i-1] = newDigit
            digits[i] = 0
            return digits[:len(digits)-1]
        } else {
            digits[i-1] = newDigit / 10
            digits[i] =  newDigit % 10
        }
    }
    return digits
}
```

```go
// cloned array
func plusOne(digits []int) ( []int) {
    nextAdding, newDigit := 1, 0 // quotient
    for i := len(digits) - 1; i >= 0 ; i-- {
        newDigit = digits[i] + nextAdding
        if newDigit < 10 {
            result = append(result, newDigit)
            nextAdding = 0
        } else {
            result = append(result, newDigit % 10)
            nextAdding = newDigit / 10
        }
        
    }
    if nextAdding > 0 {
        result = append(result, nextAdding)
    }
    reverse(result)
    return result
}

func reverse(a []int) {
    last := len(a) - 1
    for i := 0; i < len(a)/2; i++ {
        a[i], a[last-i] = a[last-i], a[i]
    }
}
```

Problem 2:

https://leetcode.com/problems/string-to-integer-atoi/description

```go
func myAtoi(str string) int {
    var result string
    for _, r := range str {
        if ((r == '-' || r == '+') && len(result) == 0) ||
            unicode.IsDigit(r){
            result += string(r)
            continue
        }
        if r == ' ' && len(result) == 0 {
            continue
        }
        if len(result) == 0 {
            return 0
        } else {
            break
        }
    }
    if result == "-" || result == "+" {
        return 0
    }
    i, _ := strconv.ParseInt(result, 10, 32)
    return int(i)
}
```
