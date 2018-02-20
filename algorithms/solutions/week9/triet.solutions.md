## Problem 1

```
func findLHS(nums []int) int {
    result := 0
    for i, num := range nums {
        countMax:=1
        countMin:=1
        max := num
        min := num
        for j := i+1; j < len(nums); j++ {
            if nums[j]-num == 1 || 
            nums[j]-num == 0 {
                countMin++
                if max < nums[j] {
                    max = nums[j]
                }
            }
            if nums[j]-num == -1 || 
            nums[j]-num == 0 {
                countMax++
                if min > nums[j] {
                    min = nums[j]
                }
            }
        }
        if max > min {
            if countMax > result {
                result = countMax
            }
            if countMin > result {
                result = countMin
            }
        }
    }
    return result
}
```
