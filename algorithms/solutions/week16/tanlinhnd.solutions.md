## Problem 1: [Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii/description/)

Dùng map để lưu lại index của mỗi value. Với mỗi vòng lặp kiểm tra điều kiện `difference between i & j <= k` là đủ

```go
func containsNearbyDuplicate(nums []int, k int) bool {
    if len(nums) < 2 || nums == nil || k == 0 {
        return false
    }
    tmp := make(map[int]int)
    for index, value := range nums {
        if _, ok := tmp[value]; ok && index - tmp[value] <= k {
            return true
        }
        tmp[value] = index
    }
    return false
}
```
