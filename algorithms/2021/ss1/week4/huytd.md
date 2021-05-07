# Easy: Determine color of a Chess Square

Submission Details:

```
203 / 203 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 2 MB
```

Stare at the chessboard, you'll notice a pattern, no it's not a zebra or a finish line.

Let the rank be a number between 1 and 8. We can convert the file into a number in the range of 1 (a) and 8 (h) too.

Then, if the sum of (rank + file) is an even number, it's a black cell, otherwise, it's a white cell.

```
func squareIsWhite(coordinates string) bool {
    file := coordinates[0] - 'a' + 1
    rank := coordinates[1] - '1' + 1
    return (file + rank) % 2 != 0 
}
```

O(1) space and O(1) time

# Medium: Knight Dialer

Submission Details:

```
121 / 121 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 1.9 MB
```

Let's say, when a Knight stand at a square (x, y) on a normal size board (8x8), there are 8 possible moves for it:

- (x-1, y-2)
- (x+1, y-2)
- (x-2, y-1)
- (x-2, y+1)
- (x+2, y-1)
- (x+2, y+1)
- (x-1, y+2)
- (x+1, y+2)

So the total number of possible move at any square (x, y) could be calculated as:

```
moves(x,y) = moves(x-1, y-2) + moves(x+1, y-2) + moves(x-2, y-1) +
             moves(x-2, y+1) + moves(x+2, y-1) + moves(x+2, y+1) +
             moves(x-1, y+2) + moves(x+1, y+2)
```

Calculating the number of possible phone number of length `n` could be dialed is the same as calculating the total number of possible moves `n` times, so, we just need to loop `n` time and get the sum.

```
func knightDialer(n int) int {
    m := 1000000007
    c := make([]int, 10)
    for i := 0; i < 10; i++  {
        c[i] = 1
    }
    for i := n; i > 1; i-- {
        c[1], c[2], c[3], c[4], c[5], c[6], c[7], c[8], c[9], c[0] = 
        (c[6] + c[8]) % m, (c[7] + c[9]) % m, (c[4] + c[8]) % m, (c[3] + c[9] + c[0]) % m, 0,
        (c[1] + c[7] + c[0]) % m, (c[2] + c[6]) % m, (c[1] + c[3]) % m, (c[4] + c[2]) % m, (c[4] + c[6]) % m
    }
    ret := 0
    for _, x := range c {
        ret += x
    }
    return ret % m
}
```
