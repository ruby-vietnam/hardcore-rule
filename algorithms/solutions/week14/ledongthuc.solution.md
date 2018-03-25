Problem 1:

https://leetcode.com/problems/power-of-four

 Troll solution
  - Step 1: Run following code to get the condition:
```go
package main

import (
	"fmt"
	"math"
	"strings"
)

func main() {
	var conditionBuilder strings.Builder
	checking := 4
	power := 0
	for true {
		result := math.Pow(float64(checking), float64(power))
		resultAsInt := int32(result)
		if resultAsInt < 0 { // If it's over signed int 32bit, it will be < 0
			break
		}
		conditionBuilder.WriteString(fmt.Sprintf("num == %d || ", resultAsInt))
		power = power + 1
		
	}
	fmt.Println(conditionBuilder.String())
  // num == 1 || num == 4 || num == 16 || num == 64 || num == 256 || num == 1024 || num == 4096 || num == 16384 || num == 65536 || num == 262144 || num == 1048576 || num == 4194304 || num == 16777216 || num == 67108864 || num == 268435456 || num == 1073741824 || 
}

```

 - Step 2: Run condition in leetcode
```
func isPowerOfFour(num int) bool {
    switch num {
case 1: return true
case 4: return true
case 16: return true
case 64: return true
case 256: return true
case 1024: return true
case 4096: return true
case 16384: return true
case 65536: return true
case 262144: return true
case 1048576: return true
case 4194304: return true
case 16777216: return true
case 67108864: return true
case 268435456: return true
case 1073741824: return true
    }
    return false
}
```
