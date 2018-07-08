## Problem 1

```go
import (
    "fmt"
    "bytes"
)

func countAndSay(n int) string {
    ret := "1"
    
    for i := 1; i < n; i++ {
        var buf bytes.Buffer
        l := len(ret)
        for j := 0; j < l; j++ {
            count := 1
            for (j + 1 < l) && (ret[j] == ret[j+1]) {
                count++
                j++
            }
            buf.WriteString(fmt.Sprintf("%d", count))
            buf.WriteString(fmt.Sprintf("%d", ret[j] - '0'))
        }
        ret = buf.String()
        buf.Reset()
    }
    return ret
}
```
