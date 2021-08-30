# Easy: Number of 1 Bits

https://leetcode.com/problems/number-of-1-bits/

### Code

```go
func hammingWeight(num uint32) int {
	res := 0
	for num > 0 {
		res = res + int(num & 1)
		num = num >> 1
	}
	return res
}
```

### Submission Detail

```
601 / 601 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 2.1 MB
```

# Medium: Container With Most Water

https://leetcode.com/problems/container-with-most-water/

### Code

```go
func maxArea(height []int) int {
	max, i, j := 0, 0, len(height)-1
	for i < j {
		area := (j-i)*min(height[i], height[j])
		if max < area {
			max = area
		}
		if height[i] < height[j] {
			i++
		} else {
			j--
		}
	}
	return max
}

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}
```

### Submission Detail

```
60 / 60 test cases passed.
Status: Accepted
Runtime: 111 ms
Memory Usage: 8.6 MB
```
