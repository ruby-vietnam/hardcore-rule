## Problem 1 - [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/description/)

```go
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *fast, *slow;
    fast = slow = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast) return true;
    }
    return false;
}
```

## Problem 3 - [Odd Even Linked List](https://leetcode.com/problems/odd-even-linked-list/description/)

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func oddEvenList(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }
    
    odd, even := head, head.Next
    headOfEven := even
    
    for even != nil && even.Next != nil {
        odd.Next, even.Next = even.Next, even.Next.Next
        odd, even = odd.Next, even.Next
    }
    odd.Next = headOfEven
    
    return head
}
```

## Problem 4 - [Range Sum Query - Mutable](https://leetcode.com/problems/range-sum-query-mutable/description/)

A typical problem using Fenwick Tree

```go
type NumArray struct {
    fenwickTree []int
    nums []int
    size int
}

func Constructor(nums []int) NumArray {
    arr := NumArray{
        fenwickTree: make([]int, len(nums) + 1),
        size: len(nums),
        nums: make([]int, len(nums)),
    }
    for i := range nums {
        arr.Update(i, nums[i])
    }
    
    return arr
}

func (this *NumArray) Update(i int, val int)  {
    if i++; i <= 0 || i > this.size {
        return
    }
    
    n, variant := this.size, val - this.nums[i-1]
    this.nums[i-1] = val
    
    for i <= n {
        this.fenwickTree[i] += variant
        i += i & -i
    }
}

func (this *NumArray) SumRange(i int, j int) int {
    return this.sum(j + 1) - this.sum(i)
}

func (this *NumArray) sum(i int) (sum int) {
    if i <= 0 {
        return
    }
    
    if i >= this.size {
        i = this.size
    }
    
    for i > 0 {
        sum += this.fenwickTree[i]
        i -= i & -i
    }
    
    return
}
```