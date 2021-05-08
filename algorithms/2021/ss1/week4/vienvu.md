# 1. Easy: determine-color-of-a-chessboard-square
https://leetcode.com/problems/determine-color-of-a-chessboard-square/


Submission Details
```
203 / 203 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 1.9 MB
```

Implementation:
```go
func squareIsWhite(coordinates string) bool {
	n, m := coordinates[0], coordinates[1]

	return  n % 2 != m % 2
}
```

# 2. Medium: knight-dialer
https://leetcode.com/problems/knight-dialer/