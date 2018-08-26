Problem 1:

https://leetcode.com/problems/house-robber/description/

```
class Solution {
    fun rob(nums: IntArray): Int {
        if (nums.size == 0) return 0
        
        val s = IntArray(nums.size + 1)
        
        s[0] = nums[0]
        s[1] = s[0]
        
        for (i in 1..nums.size-1) {
            s[i] = maxOf(nums[i] + s.getOrElse(i-2){0}, s[i-1])
        }
        
        return s.getOrElse(nums.size - 1) {0}
    }
}```
