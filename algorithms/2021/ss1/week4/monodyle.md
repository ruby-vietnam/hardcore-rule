# Determine Color of a Chessboard Square [Easy]

Problem: https://leetcode.com/problems/determine-color-of-a-chessboard-square/

## Idea

I have to discussion with my friends and founded esiest solution is switch case:

```rust
match coordinates {
  "a1" => false,
  "a2" => true,
  "a3" => false,
  ...
  "h3" => true,
  ...
}
```

LOL, jk. I can quickly see that the rule of chessboard is `a1` always a black
square. So if we mapping alphabet char to number start from 1, a position have
sum of row and col is even number is a black one.

e.g:

- b5: b = 2; b + 5 = 7 (odd) => white square
- e7: e = 5; e + 7 = 12 (even) => black square

## Example

```go
func squareIsWhite(coordinates string) bool {
	return (int(coordinates[0])-96-int(coordinates[1]))%2 != 0
}
```

## Submission Detail

```
203 / 203 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 1.9 MB
```

# Knight Dialer [Medium]

Problem: https://leetcode.com/problems/knight-dialer/

## Idea

Following problem, I think about recursive. But honestly I dont know how to do
with recursive, lol. So I just do simple way.

First, understanding how knight move. At position `(i, j)` without any blocking
around, knight can move to 8 difference positions: `(i-1, j-2)`, `(i-1, j+2)`,
`(i-1, j-1)`, `(i-1, j+1)`, `(i-2, j-2)`, `(i-2, j+2)`, `(i-2, j-1)`,
`(i-2, j+1)`.

Secondly, this look like a summary of all case. So we can do it quickly by a
loop. Initial the first case: `n = 1`. We have 10 way to make a distinct number.
So from `n = 2` to 5000 (problem constraints). We keep sum up the way we can
move the Knight.

![Explain](https://raw.githubusercontent.com/monodyle/algorithms-adventure/master/leetcode-problems/935-knight-dialer/knight-dealer.png)

## Example

```go
const m = 1_000_000_007

func knightDialer(n int) int {
	c := []int{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	for i := 1; i < n; i++ {
		n := make([]int, 10)
		n[0] = (c[4] + c[6]) % m
		n[1] = (c[6] + c[8]) % m
		n[2] = (c[7] + c[9]) % m
		n[3] = (c[4] + c[8]) % m
		n[4] = (c[3] + c[9] + c[0]) % m
		n[5] = 0
		n[6] = (c[1] + c[7] + c[0]) % m
		n[7] = (c[2] + c[6]) % m
		n[8] = (c[1] + c[3]) % m
		n[9] = (c[2] + c[4]) % m
		c = n
	}
	s := 0
	for _, v := range c {
		s += v
	}
	return s % m
}
```

## Submission Detail

```
121 / 121 test cases passed.
Status: Accepted
Runtime: 12 ms
Memory Usage: 6.4 MB
```
