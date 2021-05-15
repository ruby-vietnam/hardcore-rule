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
- Example:
```
          10
        /    \
      5       -3
    /  \        \
   3    2        11
  / \    \
3    -2   1
```

- Use a list to save the path. Go from root then if node have left/right node, append them in, left first
  - As above, we will have first list is [10, 5, 3, 3] (all left first)
- use a temp_sum to store sum value want to find
  - Loop through the list by reverse order:
    - set temp_sum to temp_sum - x, with x is the value
    - if temp_sum is 0 then we find a path, adding count!
    - -> [10, 5, 3, 3] not have temp_sum is 0 then not count here
- Pop last value of the list out then continue within recursive
-> Check and not count here, pop 3 out, list become [10, 5, 3]

-> Next list is [10, 5, 3, -2] with -2 is the left node, since the right already handle before
-> Check and not count here, pop -2 out

-> Next list is [10, 5, 3]
-> Check and count here, pop 3 out, , list become [10, 5]

-> Next list is [10, 5, 2]
-> Check and not count here, pop 3 out, , list become [10, 5]

Analysis:
- Time complexity:
- Space complexity:

Submission Detail
```
Status:
126 / 126 test cases passed.
Runtime: 160 ms
Memory Usage: 14.3 MB
```

```python
class Solution(object):
    def pathSum(self, root, targetSum):
        """
        :type root: TreeNode
        :type targetSum: int
        :rtype: int
        """
        searched_list = []
        count = 0
        return self.count_path_sum(root, targetSum, searched_list, count)

    def count_path_sum(self, node, targetSum, searched_list, count):
        if node is None:
            return count

        searched_list.append(node.val)

        count = self.count_path_sum(
            node.left, targetSum, searched_list, count)
        count = self.count_path_sum(
            node.right, targetSum, searched_list, count)


        temp_sum = targetSum
        for x in reversed(searched_list):
            if x:
                temp_sum = temp_sum - x
            if temp_sum == 0:
                count += 1

        if len(searched_list) > 0:
            searched_list.pop()

        return count
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