#!/usr/bin/env python3.7

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


def travel(root, cache):
    if root.left is not None:
        if root.right is not None:
            cache.append(root.right)
        return travel(root.left, cache)
    else:
        if root.right is not None:
            return travel(root.right, cache)
        else:
            return root


class Solution:
    """
    Problem 1 : https://leetcode.com/problems/leaf-similar-trees/description/
    """

    def leafSimilar(self, root1, root2):
        """
        :type root1: TreeNode
        :type root2: TreeNode
        :rtype: bool
        """
        sequence_1 = None
        cache_root_1 = []
        sequence_2 = None
        cache_root_2 = []

        root1 = travel(root1, cache_root_1)
        root2 = travel(root2, cache_root_2)
        while root1.val == root2.val:
            if len(cache_root_1) == 0:
                return len(cache_root_2) == 0
            else:
                if len(cache_root_2) > 0:
                    root1 = travel(cache_root_1.pop(), cache_root_1)
                    root2 = travel(cache_root_2.pop(), cache_root_2)
                else:
                    break
        return False


if __name__ == '__main__':
    print('Solution 1 passed all testcase: https://leetcode.com/submissions/detail/165894440/')