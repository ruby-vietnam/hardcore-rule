Problem 1:

https://leetcode.com/problems/nim-game/description/

 - The last turn who dealt with 4 stones always loose the game
 - Both players will try to push the opportunity to handle last 4 stones.
 - If analyzing a little bit, you will see:
 
 + n = 1,2,3 => we remove 1,2,3 to win => we win
 + n = 4 => we remove 1,2,3 => remaining 3,2,1 and opportunity will remove them to win => we loose
 + n = 5,6,7 => we remove 1,2,3 => remaining 4 stones, back to case n=4 but opportunity handle it => we win
 + n = 8 => we remove 1,2,3 => remaining 7,6,5. Back to case n = 5,6,7 and opportunity handle it, we always loose.
 ...
 
![](https://image.ibb.co/gKUjOS/Screen_Shot_2018_03_06_at_10_09_34_PM.png)
 
 - when n increase more, it will come back to previous case. So we will recognize a pattern, if n % 4, we start the game first -> we loose the game.
 
 

```
numberOfStone % 4
```

Problem 2:

https://leetcode.com/problems/teemo-attacking/description/

 - We track the longest end time of poision status. Set its value when Temo attacks with normal status victim. Poison duration is full.
 - The longest end time of poison status will be extended if Temo attack during poison duration. Extended poison duration is added instead of full one.

![](https://image.ibb.co/eayNTS/Screen_Shot_2018_03_07_at_12_05_16_AM.png)

```
func findPoisonedDuration(timeSeries []int, duration int) int {
    var totalDuration int
    lastTimeEnd := -1
    for _, time := range timeSeries {
        var extendedDuration int
        if time > lastTimeEnd {
            lastTimeEnd = time+duration-1
            extendedDuration = duration
        } else if extendedDuration = (time+duration -1 - lastTimeEnd); extendedDuration > 0 {
            lastTimeEnd += extendedDuration
        }
        
        totalDuration += extendedDuration
    }
    return totalDuration
}
```
