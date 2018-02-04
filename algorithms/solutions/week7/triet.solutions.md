## Problem 1
User hashmap

```
func firstUniqChar(s string) int {
    if len (s) == 0 {
        return -1
    }
    m := map[rune]int{}
    for _, r := range s {
        if _, exists := m[r]; exists {
            m[r] = 2
        } else {
            m[r] = 1
        }
    }

    for i, r := range s {
        if m[r] == 1 {
            return i
        }
    }
    return -1
}
```


User array char

```
func firstUniqChar(s string) int {
    if len (s) == 0 {
        return -1
    }
    arrIndex := make([]int, 26)
    for _, c := range s {
        arrIndex[int(c)-97] += 1
    }

    for i, c := range s {
        if arrIndex[int(c)-97] == 1 {
            return i
        }
    }
    return -1
}
```
