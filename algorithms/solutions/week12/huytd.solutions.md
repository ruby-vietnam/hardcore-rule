Leetcode's beating tracker is broken, so I'll not paste the submission status here anymore.

# Problem 1: Nim Game

URL: https://leetcode.com/problems/nim-game/description/

Status: Accepted

Copy pasted proof:

Theorem: The first one who got the number that is multiple of 4 (i.e. n % 4 == 0) will lost, otherwise he/she will win.

- the base case: when n = 4, as suggested by the hint from the problem, no matter which number that that first player, the second player would always be able to pick the remaining number.

- For 1* 4 < n < 2 * 4, (n = 5, 6, 7), the first player can reduce the initial number into 4 accordingly, which will leave the death number 4 to the second player. i.e. The numbers 5, 6, 7 are winning numbers for any player who got it first.

- Now to the beginning of the next cycle, n = 8, no matter which number that the first player picks, it would always leave the winning numbers (5, 6, 7) to the second player. Therefore, 8 % 4 == 0, again is a death number.

- Following the second case, for numbers between (2*4 = 8) and (3*4=12), which are 9, 10, 11, are winning numbers for the first player again, because the first player can always reduce the number into the death number 8.

```javascript
var canWinNim = function(n) {
    return !!(n % 4);
};
```

# Problem 2: Teemo attacking

URL: https://leetcode.com/problems/teemo-attacking/description/

Status: Accepted

The first attack will always be affected, so we start the `damageTime` with `duration`.

Later on, we have something more interesting. If the time between the previous attack and next attack is overlapped with the duration of previous attack, so we just need to add the overlapped time to the duration. Therefore, we should find the minimum between the two possible add up values: `duration` and `time of the current attack - time of the previous attack`.

```javascript
var findPoisonedDuration = function(timeSeries, duration) {
    if (!duration || !timeSeries.length) return 0;
    let damageTime = duration;
    for (let i = 1; i < timeSeries.length; i++) {
        damageTime += Math.min(duration, timeSeries[i] - timeSeries[i-1]);
    }
    return damageTime;
};
```
