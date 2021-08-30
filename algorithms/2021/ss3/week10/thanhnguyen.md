# 1. (Ease) [190. Reverse Bits](https://leetcode.com/problems/reverse-bits)
## Approach:
### 1.1 Solution
- Python built-in function to convert to binary, and reverse with slice

### 1.2 Code
```python
class Solution:
    def reverseBits(self, n: int) -> int:
        # chuyển số nguyên về số nhị phân
        # n_binary_str = bin(n).replace("0b", "")
        n_binary_str = "{0:b}".format(n)

        # thêm số 0 cho đủ 32 bit
        while len(n_binary_str) < 32:
            n_binary_str = "0" + n_binary_str

        # đảo ngược thứ tự
        n_binary_str = n_binary_str[::-1]

        # chuyển nhị phân về số nguyên
        return int(n_binary_str, 2)
```

# 2. (Medium) [191. Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits)
## Approach:
### 2.1 Solution


### 2.2 Code
```python
class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        return "{0:b}".format(n).count("1")
```


# 3. (Medium) [11. Container With Most Water](https://leetcode.com/problems/container-with-most-water/)
## Approach: Brute Force (TLE)
### 3.1 Solution
- Check all pair, calculate the area then compare to get the max
- The area of (x1, x2) and (y1, y2) with x is the value on x-axis and y is the value on the y-axis is:
    area = (x2 - x1) * min(y2, y1)

### 3.2 Code
```python
class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        max_area = 0
        for i, x in enumerate(height):
            for j, y  in enumerate(height[1:]):
                max_area = max(max_area, min(x, y) * ((j+1) - i))

        return max_area
```

## Approach: Two Pointer
### 3.1 Solution
- The area of (x1, x2) and (y1, y2) with x is the value on x-axis and y is the value on the y-axis is:
    area = (x2 - x1) * min(y2, y1)
- So, to get the biggest area, we need to find the biggest of (x2 - x1) alternative with the min(y2, y1) also get the biggest value
- Use 2 pointer: left, right
  - Since the x order increase already the to get the biggest of (x2 - x1), mean we need to get the smallest on the left and the biggest on the right. Then init value of the left is 0 and the right is the last value of the list
  - To find the the biggest of the min of y2, y1 then we could ignore the smaller y and move the left pointer to the right, or the right pointer to the left, until we go all item in the list(l >= r)

### 3.2 Code
```python
class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        max_area = 0
        l = 0
        r = len(height) - 1

        while l < r:
            max_area = max(
                max_area, min(height[l], height[r]) * (r - l)
            )
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1

        return max_area
```
