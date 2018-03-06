Problem 1:

https://leetcode.com/problems/nim-game/description/

 - The last turn who dealt with 4 stones always loose the game
 - Both players will try to push the opportunity to handle last 4 stones.
 - If analyzing a little bit, you will see:
 
 + n = 1,2,3 => we remove 1,2,3 to win
 + n = 4 => we remove 1,2,3 => remaining 3,2,1 and opportunity will remove them to win
 + n = 5,6,7 => we remove 1,2,3 to push last 4 stones to opportunity => who handle last 4 stones loose the game
 + n = 8 => we remove 1,2,3 => remaining 7,6,5. Back to case n = 5,6,7 and opportunity handle it, we always loose.
 ...
 
 - when n increase more, it will come back to previous case. So we will recognize a pattern, if n % 4, we start the game first -> we loose the game.

```
numberOfStone % 4
```
