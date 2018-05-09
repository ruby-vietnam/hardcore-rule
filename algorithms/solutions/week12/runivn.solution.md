# Problem 1: Nim Game

https://leetcode.com/problems/nim-game/description/

We can realize that, the player will definitely lose in case of number of nim is multiply of 4. No matter what their next move, the remain player still can chose (1, 2, 3) nim and finish the game or back to the first status (multiply of 4)

So, if you are the first mover, you will be lose if nim is 4*n.

```go
func canWinNim(n int) {
        return !(n%4)
}
```

