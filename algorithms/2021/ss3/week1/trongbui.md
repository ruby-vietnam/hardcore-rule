# Week 1

# Problem 1
https://leetcode.com/problems/toeplitz-matrix/

A key thing to do for this problem is to check if in any certain slot, its value should equal to previous diagonal slot.

```
matrix[i][j] == matrix[i-1][j-1]`
```

This also apply in case when memory is limited. We can even load only two slot into the memory which are `matrix[i][j]` and `matrix[i-1][j-1]` and compare them together then move on to next slot.

![wb-hardcore-week6-problem1](https://user-images.githubusercontent.com/7964573/122669924-9ad27100-d1e9-11eb-86fb-a97de095abcf.png)

```python
class Solution:
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:
        n, m = len(matrix), len(matrix[0])
        
        # compare bottom-left sub-matrix (n-1)(m-1)
        for row in range(1, n):
            for col in range(1, m):
                if matrix[row][col] != matrix[row-1][col-1]:
                    return False
        
        return True
```
```
483 / 483 test cases passed.
Status: Accepted
Runtime: 80 ms
Memory Usage: 14.3 MB
```

Time complexity is O(nm) which is best possible complexity we can have.

Space complexity: O(1).

# Problem 2
https://leetcode.com/problems/group-anagrams/

Solution for this problem is straightforward.

```python
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mem = {}
        # put each string value in correct bucket
        for s in strs:
            key = tuple(sorted(s))
            if key in mem:
                mem[key].append(s)
            else:
                mem[key] = [s]
        
        # get list of all values and return
        return list(mem.values())
```
```
114 / 114 test cases passed.
Status: Accepted
Runtime: 92 ms
Memory Usage: 18 MB
```

Time complexity is O(n\*mlogm) with m is the longest length of string in the list, we can have O(nm) (the best possible running time) running time by using counting sort because all possible values are under alphabet with 26 characters.

Space complexity is O(n).

# Problem 3
https://leetcode.com/problems/partition-list/

This problem is quite similar to *Dutch national flag partitioning* (3 way partitioning).

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        # if list is empty or contains only one element then condition is valid
        if head == None or head.next == None:
            return head
        
        # use dump head for easy linking to head node
        dump_head = ListNode(next=head)
        
        # pre-run to determine initial position of pointers
        prev, it = dump_head, dump_head.next
        while it.val < x:
            prev, it = it, it.next
            if it == None:
                # list satisfied with condition
                return head
        
        # check and swap, split list into three sub-list
        # less than x: [head, less_it]
        # greater or equal x: [less_it.next, greater_eq_it]
        # unprocessed items: [greater_eq_it.next, tail]
        less_it = prev
        greater_eq_it = it
        while greater_eq_it.next != None:
            it_next = greater_eq_it.next
            if it_next.val < x:
                # swap current value to ending of less-than-x list
                greater_eq_it.next = it_next.next
                less_it.next, it_next.next = it_next, less_it.next
                less_it = less_it.next
            else:
                greater_eq_it = greater_eq_it.next
            
        return dump_head.next
```
```
168 / 168 test cases passed.
Status: Accepted
Runtime: 28 ms
Memory Usage: 14.3 MB
```

Time complexity is O(n), space complexity is O(1).
