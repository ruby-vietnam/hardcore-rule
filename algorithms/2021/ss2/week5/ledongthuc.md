# 1. Number of Good Pairs

https://leetcode.com/problems/number-of-good-pairs/

## 1.1. Summary

 - With each item in the array, we increase `item's value counter`. Each item's value has a different counter.
 - We need a `total counter` that use to count pairs.
 If we found an existing item's value, we will increase the `total counter` = number of the existing item's value. The number of existed item's value is stored in `item's value counter`.

## 1.2. Code

```go
func numIdenticalPairs(nums []int) int {
    if len(nums) < 2 {
        return 0
    }
    
    m := make([]int, 101, 101)
    count := 0
    for _, num := range nums {
        cNum := m[num]
        count += cNum
        m[num]++
    }
    return count
}
```

# 2. Partition Array for Maximum Sum

https://leetcode.com/problems/partition-array-for-maximum-sum/

## 2.1. Summary

 - We use dynamic programming to solve this problem.
 - With each item in the original array, we store a maximum sum calculated from the beginning of the original array to that item. So, we need another array to store the maximum sums.

![](https://raw.githubusercontent.com/ledongthuc/notes/master/leetcode/partition-array-for-maximum-sum/partition-array-for-maximum-sum-array_sum.png)

 - To calculate the maximum sum at item `i`, we have to calculate the maximum sum of every case of `sub` that has a value in from 1 -> k.

![](https://raw.githubusercontent.com/ledongthuc/notes/master/leetcode/partition-array-for-maximum-sum/partition-array-for-maximum-sum-max_sum_of_every_case_of_k.png)

 - Calculate the maximum sum of every case of `sub` that has the value from 1 -> k; we have to know which item value of each item in range sub. We will use maximum item value in range `sub`

![](https://raw.githubusercontent.com/ledongthuc/notes/master/leetcode/partition-array-for-maximum-sum/partition-array-for-maximum-sum-max_item_in_sub.png)

## 2.2. Code

```go
func maxSumAfterPartitioning(arr []int, k int) int {
    l := len(arr)
    if l == 1 {
        return arr[0]
    }
    
    maxResults := make([]int, l + 1)
    for i := 1; i <= l; i++ {
        maxItemValueInSub, maxResultAtI := 0, 0
        
        for sub := 1; sub <= k && i - sub >= 0; sub ++ {
                maxItemValueInSub = max(maxItemValueInSub, arr[i - sub])
                maxSumValueInSub = maxItemValueInSub * sub
                maxResultAtI = max(maxResultAtI, maxSumValueInSub + maxResults[i - sub])
        }
        
        maxResults[i] = maxResultAtI
    }
    
    return maxResults[l]
}

func max(i1, i2 int) int {
    if i1 > i2 {
        return i1
    }
    return i2
}
```
