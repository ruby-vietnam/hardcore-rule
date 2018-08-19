# Problem 1

URL: https://leetcode.com/problems/middle-of-the-linked-list/description/

```javascript
var middleNode = function(head) {
    let slow = head;
    let fast = head;
    while (fast !== null && fast.next !== null) {
        slow = slow.next;
        fast = fast.next.next;
    }
    return slow;
};
```

# Problem 2

URL: https://www.codewars.com/kata/scheduling-shortest-job-first-or-sjf

```rust
fn sjf(jobs: &[usize], index: usize) -> usize {
    let cost = jobs[index];
    jobs.iter().enumerate()
        .filter(|(i, t)| (t < &&cost) || (t == &&cost && i <= &&index))
        .map(|(_, t)| t)
        .sum()
}
```
