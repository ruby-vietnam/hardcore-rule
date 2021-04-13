## Easy
> [234. Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/)

My solution:
- Save all value of linked list to an array
- Reverse array and compare with the original
- If true, it is a palindrome

Complexity: O(n)

Space:
```python
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        node = head
        stack = [head.val]

        while node.next:
            stack.append(node.next.val)
            node = node.next

        stack_reversed = stack[::-1]

        if stack_reversed == stack:
            return True

        return False
```


## Medium
> [46. Permutations](https://leetcode.com/problems/permutations/)

My solution:

```python
class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        results = []

        self.find_permutation([], nums, results)

        return results

    def find_permutation(self, permutation, choices, results):
        for j, m in enumerate(choices):
            choices_copy = choices[::]
            permutation_copy = permutation[::]
            choices_copy.pop(j)
            permutation_copy.append(m)

            if len(choices_copy) == 0:
                results = results.append(permutation_copy)
                return results
            else:
                self.find_permutation(permutation_copy, choices_copy, results)
```

## Hard

> [336. Palindrome Pairs](https://leetcode.com/problems/palindrome-pairs/)

