# Easy: Determine Color of a Chessboard Square

https://leetcode.com/problems/determine-color-of-a-chessboard-square/

### Approach

Each square of the chessboard is identified by a unique coordinate pair—a letter (file) and a number (rank)—from White's point of view.

- Files: from a to h
- Ranks: from 1 to 8

By taking a closer look at the chessboard, there is a pattern to determine which square is black:
1. If the file of a square is in an odd position, and the rank of that square is an odd number, then that square is black
2. If the file of a square is in an even position, and the rank of that square is an even number, then that square is black

We can see that if `square.file + square.rank` is an even number, that square is definitely a black square, or if the sum is an even number, then it's a white square. So we just have to convert the files from (a..h) to (1..8) and find out if `square.file + square.rank` is odd or even.

### Code (Go)

```go
import "strconv"

func squareIsWhite(coordinates string) bool {
	m := map[string]int{
		"a": 1,
		"b": 2,
		"c": 3,
		"d": 4,
		"e": 5,
		"f": 6,
		"g": 7,
		"h": 8,
	}
	file := m[string(coordinates[0])]
	rank, _ := strconv.Atoi(string(coordinates[1]))
	return (rank+file)%2 == 1
}
```

### Submission Detail

```
203 / 203 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 1.9 MB
```

# Medium: Knight Dialer

https://leetcode.com/problems/knight-dialer/

### Approach

Let's simulate the process of hopping a knight 3 times, starting at cell 1, to find distinct phone numbers of length 3:
```
1. At cell 1, n = 1, distinct phone numbers of length 1: 1 ("1")
2. From 1, we can make 2 different hops to either 6 or 8, n = 2, distinct phone number of length 2: 2 ("16", "18")
  2a. From 6, we can make 3 different hops to 1, 7 or 0, n = 3, distinct phone number of length 3: 3 ("161", "167", "170")
  2b. From 8, we can make 2 different hops to 1 or 3, n = 3, distinct phone number of length 3: 3 ("181", "183")
```

The number of distinct phone numbers of length 3, starting at cell 1, is 5 ("161", "167", "170", "181", "183"). We have 10 cells, so we just need to do the above process for the other 9 cells. When adding the result of all of them, we have the number of distinct phone numbers of length 3. Converting this simulation into a formula is simple enough:

```
1. Let cell[x] be the number of distinct phone numbers when the knight is at cell x
2. Then for 10 cells, we have
cell[0] = cell[4] + cell[6]
cell[1] = cell[6] + cell[8]
cell[2] = cell[7] + cell[9]
cell[3] = cell[4] + cell[8]
cell[4] = cell[3] + cell[9] + cell[0]
cell[5] = 0
cell[6] = cell[1] + cell[7] + cell[0]
cell[7] = cell[2] + cell[6]
cell[8] = cell[1] + cell[3]
cell[9] = cell[2] + cell[4]
```

With `n` hops remaining, we can do the simulation `n` times, calculating the value of all 10 cells following the formula above. There is an exception when `n = 1`, then `cell[x] = 1` because we only have 1 hop and can't move anywhere but `x`.

### Code (Go)

```go
func knightDialer(n int) int {
	if n == 1 {
		return 10
	}
	mod := 1000000007
	c := []int{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	for i := 0; i < n-1; i++ {
		c[0], c[1], c[2], c[3], c[4], c[5], c[6], c[7], c[8], c[9] =
		(c[4]+c[6])%mod, (c[6]+c[8])%mod, (c[7]+c[9])%mod, (c[4]+c[8])%mod, (c[3]+c[9]+c[0])%mod, 0, (c[1]+c[7]+c[0])%mod, (c[2]+c[6])%mod, (c[1]+c[3])%mod, (c[2]+c[4])%mod
	}
	sum := 0
	for _, v := range c {
		sum += v
	}
	return sum % mod
}
```

Time complexity: O(n), space complexity: O(10).

### Submission Detail

```
121 / 121 test cases passed.
Status: Accepted
Runtime: 4 ms
Memory Usage: 1.9 MB
```
