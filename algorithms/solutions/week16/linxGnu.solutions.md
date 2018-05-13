## Problem 1 - [Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii/description/)

```go
func containsNearbyDuplicate(nums []int, k int) bool {
    if nums == nil || len(nums) <= 1 {
        return false
    }
    
    m := make(map[int]int)
    for i, v := range nums {
        if j, ok := m[v]; ok && i - j <= k {
            return true
        }
        m[v] = i
    }
    
    return false
}
```

## Problem 2 - [Find Peak Element](https://leetcode.com/problems/find-peak-element/description/)

```go
// Gradient descent solution
func findPeakElement(nums []int) int {
    if nums == nil || len(nums) <= 1 {
        return 0
    }
    
    left, right, mid := 0, len(nums) - 1, 0
    if nums[left] > nums[left+1] {
        return left
    }
    if nums[right] > nums[right-1] {
        return right
    }
    
    for left <= right {
        if mid = (left + right) >> 1; mid == left {
            if nums[right] > nums[left] {
                return right
            }
            
            return left
        }
        
        if nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1] {
            return mid
        }
        
        if nums[mid] > nums[mid-1] || (nums[mid] < nums[mid+1] && nums[mid] < nums[mid-1]) {
            left = mid
        } else {
            right = mid
        }
    }
    
    return 0
}
```

### Problem Bonus - [Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/description/)

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

// Stacking solution
func reverseKGroup(head *ListNode, k int) (result *ListNode) {
    if head == nil || k <= 0 {
        return head
    }
    
    result = head
    
    start, end, counter := head, head, 0
    
    var prev, next *ListNode
    for end != nil {
        if counter++; counter == k { // found a group
            next = end.Next
            reverse(start, end)
            
            start.Next = next
            if prev != nil {
                prev.Next = end
            } else { // first group
                result = end
            }
            
            prev = start
            start, end = next, next
            counter = 0
        } else {
            end = end.Next
        }
    }
    
    return
}

func reverse(head, tail *ListNode) {
    cur := head
    
    var next, newHead *ListNode
    for {
        next = cur.Next
        cur.Next = newHead
        newHead = cur
        if cur == tail {
            return
        }
        cur = next
    }
}
```