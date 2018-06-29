Problem 1:

https://leetcode.com/problems/non-decreasing-array/description/

```go
func checkPossibility(nums []int) bool {
    if len(nums) < 3 {
        return true
    }
    
    isFirst := false
    for index := 0; index < len(nums); index++ {
        if index >= len(nums) - 1 || nums[index] <= nums[index + 1] {
            continue
        }
        if isFirst {
            return false
        }
        isFirst = true
        if (index < len(nums) - 2 && nums[index] > nums[index + 2]) && 
            (index > 0 && nums[index - 1] > nums[index + 1]) {
            return false
        }
    }
    return true
}
```

Problem 2:

https://leetcode.com/problems/permutations/description/

```go
func permute(nums []int) [][]int {
    return permuteP([][]int{[]int{}}, nums) 
}

func permuteP(current [][]int, rest []int) (result [][]int) {
    if len(rest) == 0 {
        return current
    }
    for cIndex, _ := range current {
        for rIndex, _ := range rest {
            temp := append(current[cIndex], rest[rIndex])
            newRest := append([]int{}, rest[:rIndex]...)
            newRest = append(newRest, rest[rIndex+1:]...)
            result = append(result, permuteP([][]int{temp}, newRest)...)
        }
    }
    
    return result
}
```
