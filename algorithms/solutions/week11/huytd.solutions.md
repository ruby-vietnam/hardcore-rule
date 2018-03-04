# Problem 1: Linked List Cycle

URL: https://leetcode.com/problems/linked-list-cycle/description/

Status:
```
  ✔ Accepted
  ✔ 16/16 cases passed (68 ms)
  ✔ Your runtime beats 100 % of javascript submissions
```

Approach: We create two pointer to run through the list, the later one run faster than the first, if there is a cycle, so eventually the slow one and fast one will always meet at some point (you need to learn basic physics to prove this, probably elementary physics).

A.k.a Floyd's circle finding algorithm (https://en.wikipedia.org/wiki/Cycle_detection#Tortoise_and_hare)

```javascript
var hasCycle = function(head) {
    if (!head) return false;
    let slow = head; let fast = head;
    while (fast && fast.next) {
        slow = slow.next;
        fast = fast.next.next;
        if (slow == fast) return true;
    }
    return false;
};
```

# Problem 3: Odd Even Linked List

URL: https://leetcode.com/problems/odd-even-linked-list/description/

Status:
```
  ✔ Accepted
  ✔ 70/70 cases passed (72 ms)
  ✔ Your runtime beats 100 % of javascript submissions
```

Approach: The idea is start iterating from two position, the first node for odd items, and second node for even items. At each node, we replace it's next pointer with the item after it. Eventually, we connect the two half into one.

```javascript
var oddEvenList = function(head) {
    if (!head) return null;
    let odd = head;
    let oddhead = odd;
    let even = head.next;
    let headeven = even;
    while (odd.next && odd.next.next) {
        odd.next = odd.next.next;
        odd = odd.next;
        even.next = even.next.next;
        even = even.next;
    }
    odd.next = headeven;
    if (even) even.next = null;
    return oddhead;
};
```

# Problem 4: Range Sum Query

URL: https://leetcode.com/problems/range-sum-query-mutable/description/

Status:
```
  ✔ Accepted
  ✔ 10/10 cases passed (128 ms)
  ✔ Your runtime beats 94.45 % of javascript submissions
```

What the hell is this?

```javascript
/**
 * @param {number[]} nums
 */
var NumArray = function(nums) {
    this.nums = nums;
};

/** 
 * @param {number} i 
 * @param {number} val
 * @return {void}
 */
NumArray.prototype.update = function(i, val) {
    this.nums[i] = val;
};

/** 
 * @param {number} i 
 * @param {number} j
 * @return {number}
 */
NumArray.prototype.sumRange = function(i, j) {
    let sum = 0;
    for (let x = i; x <= j; x++) {
        sum += this.nums[x];
    }
    return sum;
};

/** 
 * Your NumArray object will be instantiated and called as such:
 * var obj = Object.create(NumArray).createNew(nums)
 * obj.update(i,val)
 * var param_2 = obj.sumRange(i,j)
 */
```
