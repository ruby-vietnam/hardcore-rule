## Easy([234. Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/))

**Solution:**

Explanation:
- Save all value of linked list to an array
- Reverse array and compare with the original
- If true, it is a palindrome

Analysis:
- Time complexity: O(n)
- Space complexity: O(n)

Submission Detail
```
Status: Accepted
85 / 85 test cases passed.
Runtime: 1152 ms
Memory Usage: 85.2 MB
```

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

## Medium([46. Permutations](https://leetcode.com/problems/permutations/))

**Solution:**

Explanation:
- With n is length of the list, will have n! permutation
  n! = n * (n-1) * (n-2) * ... * 1
By example: [1, 2, 3]

We want permution with length is length of the list, is 3, then we have 3 positions to put value on: _  _  _

- At position 1, permutation = _ _ _ ; choices = [1, 2, 3]
  - If select 1, -> permutation = 1 _ _ ; choices = [2, 3]
    - If select 2 -> permutation = 1 2 _ ; choices = [3]
        - If select 3 -> permutation = 1 2 3 ; choices = [] -> no more choice
            > append permutation [1, 2, 3] to result
    - If select 3 -> permutation = 1 3 _ ; choices = [2]
        - If select 2 -> permutation = 1 3 2 ; choices = [] -> no more choice
            > append permutation [1, 3, 2] to result
  - If select 2, the choices will reduce to [1, 3]
    - If select 1 -> permutation = 2 1 _ ; choices = [3]
        - If select 3 -> permutation = 2 1 3 ; choices = [] -> no more choice
            > append permutation [2, 1, 3] to result
    - If select 3 -> permutation = 2 3 _ ; choices = [1]
        - If select 1 -> permutation = 2 3 1 ; choices = [] -> no more choice
            > append permutation [2, 3, 1] to result
  - If select 3, the choices will reduce to [1, 2]
    - If select 1 -> permutation = 3 1 _ ; choices = [2]
        - If select 2 -> permutation = 3 1 2 ; choices = [] -> no more choice
            > append permutation [3, 1, 2] to result
    - If select 2 -> permutation = 3 2 _ ; choices = [1]
        - If select 1 -> permutation = 3 2 1 ; choices = [] -> no more choice
            > Second permutation is [3, 2, 1]


> If still have choice, get next value and put to permutation, then pop them out of the choices
>
> If no more choice, append permutation to results.


Analysis:
- Time complexity:
- Space complexity:

Submission Detail
```
Status: Accepted
25 / 25 test cases passed.
Runtime: 24 ms
Memory Usage: 13.4 MB
```

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
            else:****
                self.find_permutation(permutation_copy, choices_copy, results)
```

## Hard([336. Palindrome Pairs](https://leetcode.com/problems/palindrome-pairs/))

*Issue: TLE*

Explanation:

- Step 1: get index list
- Step 2: find all permutations of index list with pair [a, b]
  - use solution in the medium one
- Step 3: check if concat string in permutations is palindrome pairs, if yes put to result
  - use solution in the easy one

Analysis:
- Time complexity:
- Space complexity:


Submission Detail
```
Status: Time Limit Exceeded
47 / 134 test cases passed.
```

```python
class Solution(object):
    def palindromePairs(self, words):
        """
        :type words: List[str]
        :rtype: List[List[int]]
        """
        # Step 1: get index list
        index_list = list(range(0, len(words)))

        # Step 2: find all permutations of index list with pair [a, b]
        # expect results: [[0, 1], [0, 2], [1, 0], [1, 2], [2, 0], [2, 1]]
        permutations = self.all_permutations_with_length(index_list, 2)

        # Step 3: check if concat string in permutations is palindrome pairs
        results = []
        for p in permutations:
            word = words[p[0]] + words[p[1]]
            # check is word is palindrome
            if self.is_palindrome(word):
                results.append(p)

        return results

    def all_permutations_with_length(self, index_list, length):
        # permutation = []
        results = []
        self.find_permutation([], index_list, results, length)
        return results

    def find_permutation(self, permutation, choices, results, length):
        for i, num in enumerate(choices):
            choices_copy = choices[::]
            permutation_copy = permutation[::]
            choices_copy.pop(i)
            permutation_copy.append(num)

            if len(permutation_copy) == length:
                results.append(permutation_copy)
            elif len(choices_copy) > 0:
                self.find_permutation(permutation_copy, choices_copy, results, length)

    def is_palindrome(self, word):
        return word == word[::-1]

```

> Make it shorter, and still TLE

Submission Detail
```
Status: Time Limit Exceeded
62 / 134 test cases passed.
```

```python
class Solution(object):
    def palindromePairs(self, words):
        """
        :type words: List[str]
        :rtype: List[List[int]]
        """
        index_list = list(range(0, len(words)))


        result_permutations_palindrome = []
        self.find_permutation(
            [], index_list,
            result_permutations_palindrome,
            2, words
        )

        return result_permutations_palindrome

    def find_permutation(
        self, permutation, choices,
        result_permutations_palindrome,
        length, words
    ):
        for i, num in enumerate(choices):
            choices_copy = choices[::]
            permutation_copy = permutation[::]
            choices_copy.pop(i)
            permutation_copy.append(num)

            if len(permutation_copy) == length:
                word = words[
                    permutation_copy[0]] + words[permutation_copy[1]
                ]
                if word == word[::-1]:
                    result_permutations_palindrome.append(permutation_copy)

            elif len(choices_copy) > 0:
                self.find_permutation(
                    permutation_copy,
                    choices_copy,
                    result_permutations_palindrome,
                    length,
                    words
                )
```
