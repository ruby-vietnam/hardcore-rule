Problem1: https://leetcode.com/problems/nim-game/description/

If we have n = 5, then we can select 1 stone to win
If we have n = 6, then we can select 2 stone to win
If we have n = 7, then we can select 3 stone to win
If we have n = 8, then we will loose
so we can see the rule is if we call the number of stone we can select in one time is k, if n % (k+1) == 0, then we will lose the game

```java
public boolean canWinNim(int n) {
        return (n % 4 != 0);
    }
```
