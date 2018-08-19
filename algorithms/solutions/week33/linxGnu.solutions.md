## Problem 1 - [Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/description/)

```go
func middleNode(head *ListNode) *ListNode {
    slow, fast := head, head
    for fast != nil && fast.Next != nil {
        slow = slow.Next
        fast = fast.Next.Next
    }
    return slow
}
```

## Problem 2 - [Scheduling (Shortest Job First or SJF)](https://www.codewars.com/kata/scheduling-shortest-job-first-or-sjf)

```rust
fn sjf(jobs: &[usize], index: usize) -> usize {
    let duration = jobs[index];
    jobs.iter().enumerate()
        .filter(|&(i, d)| (*d < duration) || (*d == duration && i <= index))
        .map(|(_, d)| d)
        .sum()
}
```