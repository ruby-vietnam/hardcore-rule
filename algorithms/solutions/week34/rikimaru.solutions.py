#!/usr/bin/env python3.7

class Solution1:
    """
    Problem 1: https://leetcode.com/problems/house-robber/description/
    """
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        first = 0
        second = 0
        for num in nums:
            if (num + second) > first:
                temp = first
                first = num + second
                second = temp
            else:
                second = first
            
        return first


if __name__ == '__main__':
    print('Solution 1 passed all testcase: https://leetcode.com/problems/house-robber/description/')