Problem 1:

https://leetcode.com/problems/count-and-say/description/

```
func countAndSay(n int) string {
    current := "1"
    for n > 1 {
        i := 0
        temp := ""
        for i < len(current) {
            j := i + 1
            for j < len(current) && current[j] == current[j-1] {
                j++
            }
            temp += strconv.Itoa(j-i) + string(current[i])
            i = j
        }
        current = temp
        n--
    }
    return current
}
```
