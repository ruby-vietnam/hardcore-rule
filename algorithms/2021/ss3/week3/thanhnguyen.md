# 1. (Easy) [257. Binary Tree Paths](https://leetcode.com/problems/binary-tree-paths/)
## 1.1 First approach: Recursion
- Go through the tree
  - If get a leaf then update the paths in
  - If not a leaf, call function recursion for left and right node to get the path

## 1.2 First approach: Code
```python
class Solution(object):
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """

        def get_paths(root, path):
            path = path[:]

            if root:
                path.append(root.val)
                # path += str(root.val)

                if not root.left and not root.right:
                    paths.append(
                        "->".join(str(i) for i in path)
                    )
                else:
                    get_paths(root.left, path)
                    get_paths(root.right, path)

        paths = []
        get_paths(root, [])
        return paths
```

# 2. (Medium)[1415. The k-th Lexicographical String of All Happy Strings of Length n](https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/)

## 2.1. First approach: Recursion
- Similar to above one, do sum all the number in each path

## 2.2 First approach: Code
```python
class Solution(object):
    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def get_paths(root, path):
            path = path[:]

            if root:
                path.append(root.val)

                if not root.left and not root.right:
                    number = get_number(path)
                    paths.append(number)
                else:
                    get_paths(root.left, path)
                    get_paths(root.right, path)

        def get_number(path):
            """
            find number from a path list
            example: [1, 2, 3] -> 123
            """
            number = 0
            for i, x in enumerate(reversed(path)):
                number += (10 ** i) * x
            return number

        paths = []
        # update all path to the paths list by call recursion
        get_paths(root, [])

        return sum(paths)

```

## 2.1. Second approach: Use Stack
- SUM = 0
- init stack with (root, 0) -> current_number is 0
- Khi vẫn còn giá trị trong stack thì lấy ra và kiểm tra:
  - if it is not a leaf, add to stack new value (root, current_number)
    - with current_number is the before one + current node value
  - if root is a leaf, update the sum with current number

Example: root = [4,9,0,5,1]
---
stack = [(4, 0)]
while stack:
  # Lấy ra khỏi stack (4, 0), stack = []
  root = 4,
  current_number = 0

  current_number = 0 * 10 + 4 = 4
  # Số 4 không phải là leaf:
  # Thêm vào stack node bên phải
  stack = [(0, 4)]
  # Thêm vào stack node bên trái
  stack = [(0, 4), (9, 4)]

---
stack = [(0, 4), (9, 4)]
while stack:
  # Lấy ra khỏi stack (9, 4), stack = [(0, 4)]
  root = 9,
  current_number = 4

  current_number = 4 * 10 + 9 = 49
  # Số 9 không phải là leaf:
  # Thêm vào stack node bên phải
  stack = [(0, 4), (1, 49)]
  # Thêm vào stack node bên trái
  stack = [(0, 4), (1, 49), (5, 49)]

---
stack = [(0, 4), (1, 49), (5, 49)]
while stack:
  # Lấy ra khỏi stack (5, 49), stack = [(0, 4), (1, 49)]
  root = 5,
  current_number = 49

  current_number = 49 * 10 + 5 = 495

  # Số 5 là leaf: cập nhật SUM
  SUM = 495

---
stack = [(0, 4), (1, 49)]
while stack:
  # Lấy ra khỏi stack (1, 49), stack = [(0, 4)]
  root = 1,
  current_number = 49

  current_number = 49 * 10 + 1 = 491

  # Số 1 là leaf: cập nhật SUM
  SUM = SUM + 491 = 495 + 491 = 986

---
stack = [(0, 4)]
while stack:
  # Lấy ra khỏi stack (0, 4), stack = []
  root = 0,
  current_number = 4

  current_number = 4 * 10 + 0 = 40

  # Số 0 là leaf: cập nhật SUM
  SUM = SUM + 40 = 986 + 40 = 1026

## 2.2 Second approach: Code
```python
class Solution(object):
    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        sum = 0
        stack = [(root, 0)]

        while stack:
            root, curr_number = stack.pop()

            if root is not None:
                curr_number = curr_number * 10 + root.val

                if root.left is None and root.right is None:
                    sum += curr_number
                else:
                    stack.append((root.right, curr_number))
                    stack.append((root.left, curr_number))

        return sum
```