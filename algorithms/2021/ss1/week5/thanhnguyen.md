# Easy
> [653. Two Sum IV - Input is a BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/)

**Approach 1:**

Explanation:
- [Binary Search Tree](https://en.wikipedia.org/wiki/Binary_search_tree)
- Dùng một list để lưu các giá trị đã duyệt qua
- (*) Nếu giá trị của node duyệt đến, có k trừ giá trị này trong list đã duyệt qua thì đó là cặp giá trị có tổng bằng k. Vì k = val + (k - val)
- Duyệt qua cây BST:
  - Nếu đã duyệt đến lá mà vẫn không tìm ra thì return False
  - Nếu thoả điều kiện (*) trên
  - Nếu không thoả điều kiện, lưu giá trị đã duyệt vào list đã duyệt qua, gọi đệ quy cho cây bên trái hoặc cây bên phải. Chỉ cần một trong hai cây trả về giá trị True là được

Analysis:
- Time complexity:
- Space complexity:

Submission Detail
```
Status:
x / x test cases passed.
Runtime: x ms
Memory Usage: x MB
```

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution(object):
    def findTarget(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: bool
        """
        searched_list = []
        return self.binary_tree_search_node(root, k, searched_list)

    def binary_tree_search_node(self, node, k, searched_list):
        if node is None:
            return False
        # val + (k - val) = k
        if k - node.val in searched_list:
            return True
        # save search value to searched list
        searched_list.append(node.val)

        check_right = self.binary_tree_search_node(node.left, k, searched_list)
        check_left = self.binary_tree_search_node(node.right, k, searched_list)

        # return true if left or right return True
        return check_right  or check_left
```

# Medium
> [437. Path Sum III](https://leetcode.com/problems/path-sum-iii/)

**Approach 1:**

Explanation:


Analysis:
- Time complexity:
- Space complexity:

Submission Detail
```
Status:
x / x test cases passed.
Runtime: x ms
Memory Usage: x MB
```

```python
```

# Hard
> [124. Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/)

**Approach 1:**

Explanation:


Analysis:
- Time complexity:
- Space complexity:

Submission Detail
```
Status:
x / x test cases passed.
Runtime: x ms
Memory Usage: x MB
```

```python
```