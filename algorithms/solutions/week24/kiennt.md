## Problem 2

```golang
package main

import (
	"fmt"
	"sort"
	"strings"
)

type Num []string

func (n Num) Len() int      { return len(n) }
func (n Num) Swap(i, j int) { n[i], n[j] = n[j], n[i] }
func (n Num) Less(i, j int) bool {
	vi := fmt.Sprintf("%s%s", n[i], n[j])
	vj := fmt.Sprintf("%s%s", n[j], n[i])
	return vi > vj
}

func largestNumber(nums []int) string {
	isZero := true
	numStr := make(Num, len(nums))
	for i := 0; i < len(nums); i++ {
		if nums[i] != 0 {
			isZero = false
		}
		numStr[i] = fmt.Sprintf("%d", nums[i])
	}
	if isZero {
		return "0"
	}
	sort.Sort(Num(numStr))
	return strings.Join(numStr, "")
}

func main() {
	fmt.Println(largestNumber([]int{10, 2}))
	fmt.Println(largestNumber([]int{22, 221}))
	fmt.Println(largestNumber([]int{3, 30, 34, 5, 9}))
	fmt.Println(largestNumber([]int{0, 0}))
}
```