# 1. Binary Tree Paths

## 1.1 Problem

https://leetcode.com/problems/binary-tree-paths/


## 1.2. Solution 

- start with Root
  - update the path with node value
  - if it is leaf node. yield the path as a result
  - if it has left node. build the path of left node with prefix is current path. Then yield the output as a result
  - do the same with right node.

## 1.3. Implement

```python
from typing import List, Optional, Any


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def binaryTreePaths(self, root: TreeNode) -> List[str]:
        def find_paths(node: TreeNode, is_root: bool, prefix: Optional[str]) -> Any:
            new_prefix = str(node.val) if is_root else prefix + "->" + str(node.val)
            if not bool(node.left) and not bool(node.right):
                yield new_prefix
            if node.left:
                yield from find_paths(node.left, False, new_prefix)
            if node.right:
                yield from find_paths(node.right, False, new_prefix)

        return list(find_paths(root, True, None))
```

```text

208 / 208 test cases passed.
Status: Accepted
Runtime: 48 ms
Memory Usage: 14.3 MB

```

# 2.  Find K Closest Elements

## 2.1. Problem

https://leetcode.com/problems/find-k-closest-elements

## 2.2. Solution

- Find the first element which equals or greater than `x`, let's say has index `idx`
- Start with k elements from `idx - k` to `idx`
    - while abs(left-most element - `x`) > abs(right-most element - x), shift the range to right 1 step.

## 2.3. Implement
```python
from typing import List


class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        if x < arr[0]:
            return arr[:k]
        if x >= arr[-1]:
            return arr[-k:]
        for idx in range(0, len(arr)):
            if arr[idx] >= x:
                left_index = max(0, idx - k)
                right_index = min(len(arr), left_index + k) - 1
                # shift
                while right_index + 1 < len(arr) and abs(arr[left_index] - x) > abs(x - arr[right_index + 1]):
                    right_index = right_index + 1
                    left_index = left_index + 1
                return arr[left_index: right_index + 1]

```

Result
```text
63 / 63 test cases passed.
Status: Accepted
Runtime: 292 ms
Memory Usage: 15.4 MB
```