# Easy: Toeplitz Matrix

https://leetcode.com/problems/toeplitz-matrix/description/

### Approach

A matrix A (m * n) is Toeplitz if `A[i][j] == A[i+1][j+1] == A[i+2][j+2] == ... == A[m][n]`, i starting from 1 to m-1 and j starting from 1 to n-1. From that pattern, we can traverse through all cells in the matrix, from left to right and top to bottom, check whether `A[i][j] == A[i+1][j+1]` and continue or break according to the result.

### Code

```go
func isToeplitzMatrix(matrix [][]int) bool {
	for i := 0; i < len(matrix)-1; i++ {
		for j := 0; j < len(matrix[i])-1; j++ {
			if matrix[i][j] != matrix[i+1][j+1] {
				return false
			}
		}
	}
	return true
}
```

Time complexity: O(m * n).

### Submission Detail

```
483 / 483 test cases passed.
Status: Accepted
Runtime: 12 ms
Memory Usage: 4.4 MB
```

# Medium 2: Partition List

https://leetcode.com/problems/partition-list/

### Approach

This problem is very similar to [Odd Even Linked List](https://leetcode.com/problems/odd-even-linked-list/), only a slight difference in the condition.

To solve this, we create 2 linked lists: one for nodes with value less than `x`, and one for nodes with value greater than or equal to `x`. The variables `lessThanX` and `less` are the head pointer and tail pointer of the first linked list. The variables `greaterThanOrEqualToX` and `greater` are the head pointer and tail pointer of the other linked list. We will use `head` to traverse the original linked list, at each node if its value is less than `x`, we point the tail pointer of the less linked list to this node and update the less linked list's tail, or if its value is greater than or equal to `x`, we point the tail pointer of the greater linked list to this node and update the greater linked list's tail. Finally, we pointer the tail of the less linked list to the head of the greater linked list and return the head of the less linked list.

### Code

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func partition(head *ListNode, x int) *ListNode {
	lessThanX := &ListNode{}
	greaterThanOrEqualToX := &ListNode{}
	less := lessThanX
	greater := greaterThanOrEqualToX

	for head != nil {
		if head.Val < x {
			less.Next = head
			less = less.Next
		} else {
			greater.Next = head
			greater = greater.Next
		}
		head = head.Next
	}

	greater.Next = nil
	less.Next = greaterThanOrEqualToX.Next
	return lessThanX.Next
}
```

Remember that the last node of the greater linked list must point to null before connecting the two linked lists together (for when the original list is empty).

Time complexity: O(n), space complexity: O(n).

### Submission Detail

```
168 / 168 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 2.5 MB
```
