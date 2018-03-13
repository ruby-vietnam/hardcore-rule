## Problem 1

```
import (
	"fmt"
	"sort"
)

func maximumProduct(nums []int) int {
    // NOTE: this is not the most optimize solution, since sort is O(NlogN)
    // we could make it O(N) by only select 3 maximum numbers and 2 mininum numbers
	sort.Ints(nums)
	size := len(nums)
	val1 := nums[size-1] * nums[size-2] * nums[size-3]
	val2 := nums[0] * nums[1] * nums[size-1]
	if val1 < val2 {
		return val2
	} else {
		return val1
	}
}
```