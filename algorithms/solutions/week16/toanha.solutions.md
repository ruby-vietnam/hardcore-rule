## Problem 1

```golang
func containsNearbyDuplicate(nums []int, k int) bool {
    var m = map[int]int{}

    for i:=0; i<len(nums); i++ {
        if value, ok := m[nums[i]]; ok && i - value <= k {
            return true
        }
        m[nums[i]] = i
    }

    return false
}

```

## Problem 2

```golang
func findPeakElement(nums []int) int {
    var index = -1
    var max = -2147483648

    for i := 0; i < len(nums); i++ {
        if nums[i] >= max {
            index = i
            max = nums[i]
        }
    }

    return index
}
```
