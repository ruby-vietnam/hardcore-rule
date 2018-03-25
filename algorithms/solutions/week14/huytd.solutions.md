# Problem 1: Power of Four

URL: https://leetcode.com/problems/power-of-four/description/

Status:

```
  ✔ Accepted
  ✔ 1060/1060 cases passed (128 ms)
  ✔ Your runtime beats 32.81 % of javascript submissions
```

Approach: If a number is a power of four, the logarithm base 4 of this number should be an integer.

In JavaScript, we don't have any built in function to calculate logarithm of any base, we only have logarithm of base 2, 10 and e.

There's a math trick that can do the job, is to change the base:

![](https://wikimedia.org/api/rest_v1/media/math/render/svg/2501990f5b076a3985574629027fff0e71e73e4d)

We can generalize it to calculate logarithm of any base:

![](http://www.purplemath.com/modules/logs/logrul09.gif)

See more details [here](http://www.purplemath.com/modules/logrules5.htm) and [here](https://en.wikipedia.org/wiki/Common_logarithm#Numeric_value)

To check if a number is integer or not, we use the nature of JavaScript, that it will convert any type of number into Int32 when we apply a bitwise operator on that number.

```javascript
var isPowerOfFour = function(num) {
    let lg4 = Math.log(num) / Math.log(4);
    return lg4 === (~~lg4);
};
```

# Problem 2: Number of Islands

URL: https://leetcode.com/problems/number-of-islands/

Status:
```
  ✔ Accepted
  ✔ 47/47 cases passed (72 ms)
  ✔ Your runtime beats 88.43 % of javascript submissions
```

Solution: [Seek and Destroy](https://www.youtube.com/watch?v=NUAdgt5Glk0), we use BFS to traversal the map, for every island cell we reach, we destroy it (change it into water cell `0`), so in the next visit, we don't repeat ourself. And each time we decided to start a tour (start BFS), we landed on an island, so increase the counter.

```javascript
var numIslands = function(grid) {
    let h = grid && grid.length || 0;
    let w = grid[0] && grid[0].length || 0;
    let count = 0;
    for (let y = 0; y < h; y++) {
        for (let x = 0; x < w; x++) {
            if (~~grid[y][x] === 1) {
                BFS(y, x, grid, w, h);
                count++;
            }
        }
    }
    return count;
};

const BFS = (y, x, grid, w, h) => {
    if (y < 0 || y >= h || x < 0 || x >= w || ~~grid[y][x] !== 1) {
        return;
    }

    grid[y][x] = 0;

    BFS(y-1, x, grid, w, h);
    BFS(y+1, x, grid, w, h);
    BFS(y, x-1, grid, w, h);
    BFS(y, x+1, grid, w, h);
};
```
