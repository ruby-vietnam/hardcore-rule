# Easy

```swift
class Solution {
    func merge(_ nums1: inout [Int], _ m: Int, _ nums2: [Int], _ n: Int) {
        var k = m + n - 1
        var i = m-1
        var j = n-1
        while k >= 0 && j >= 0 {
            if i>= 0 && nums1[i] > nums2[j] {
                nums1[k] = nums1[i]
                i-=1
            } else {
                nums1[k] = nums2[j]
                j-=1
            }
            k-=1
        }
    }
}
```
```
Runtime: 8 ms, faster than 93.27% of Swift online submissions for Merge Sorted Array.
Memory Usage: 14.3 MB, less than 18.05% of Swift online submissions for Merge Sorted Array.
```

# Medium
```swift
class Solution {

    private let nums: [Int]

    init(_ nums: [Int]) {
        self.nums = nums
    }

    func reset() -> [Int] {
        return original
    }

    func shuffle() -> [Int] {
        var copy = nums
        for index in stride(from: nums.count - 1, through: 1, by: -1) {
            let randomIndex = Int.random(in: 0...index)
            if index != randomIndex {
                copy.swapAt(index, randomIndex)
            }
        }
        return copy
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * let obj = Solution(nums)
 * let ret_1: [Int] = obj.reset()
 * let ret_2: [Int] = obj.shuffle()
 */
```
```
Runtime: 392 ms, faster than 43.48% of Swift online submissions for Shuffle an Array.
Memory Usage: 16.6 MB, less than 43.48% of Swift online submissions for Shuffle an Array.
```