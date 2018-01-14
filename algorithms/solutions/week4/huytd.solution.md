# Problem 1: Jump Game II

Leetcode URL: https://leetcode.com/problems/jump-game-ii/description/

I actuallly copied the solution from anh @linxGnu, but I do it with my pride:

- At first, I copied it, convert it to JavaScript
- After accepted, I clear all the code and re implemented it, submit again
- After the second accept, I cleared all the code again and wait for 1 hours before re implemented it for the third time

That's how I copy and make it become my understanding :trollface:

```javascript
var jump = function(nums) {
  let n = nums.length - 1;
  let i = count = k = j = max = jmax = 0;

  while (i < n) {
    k = i + nums[i];
    if (k >= n) {
      return count + 1;
    }
    max = jmax = 0;
    for (j = i + 1; j <= k; j++) {
      if (max < j + nums[j]) {
        max = j + nums[j];
        jmax = j;
      }
    }

    i = jmax; count++;
  }

  return count;
};
```

**Explanation:** from anh @linxGnu

Strategy: 

 - At any point i, we could chose next point in range (i + 1, i + nums[i])
 - How to choose next point: select j in (i + 1, i + nums[i]) where j + nums[j] is maximum

Prove:

 - Suppose we that we are only able to reach any point from 0 to N within minimum S steps using the strategy.
 - Our strategy is wrong if and only if there is also a solution to jump to any point M > N within S steps.

Then:

- Step S - 1: we may be at M1 where M > M_1 > N
- Step S - 2: we may be at M1 where M > M_1 > M_2 > N
- ...
- Step S - k: we may be at Mk where M > N > M_k
- ...

Look at Step (S - k), it means that M > M_k-1 > N > M_k

=> we could jump to a point > N from M_k within S steps. 

Our strategy did that because its chosen of next point with furthest.

Actually, our strategy give better optimization by jump to M_k then M_k-1 with < S steps.

_**Side note:** This solution will definitelly blow up (ended up in infinite loop) if there are no possible path to the top, for example, `[3, 2, 1, 0, 4]`, but we don't have to worry about it because the problem assumed that you can always reach the top._

# Problem 2: Sort Colors

Leetcode URL: https://leetcode.com/problems/sort-colors/description/

```javascript
var sortColors = function(nums) {
  let left = 0; let right = nums.length - 1;
  for (let i = 0; i <= right;) {
    if (nums[i] == 0) {
      [nums[i], nums[left]] = [nums[left], nums[i]];
      i++;
      left++;
    } else if (nums[i] == 2) {
      [nums[i], nums[right]] = [nums[right], nums[i]];
      right--;
    } else {
      i++;
    }
  }
};
```

Do you see how I swap two numbers? What a smart solution! right?

It works just like tuples, but sadly, JavaScript do not have tuples, so I use array instead:

```javascript
let a = 10; let b = 5;
[a, b] = [b, a];
// now a = 5
// and b = 10
```

**Explanation:**

My approach for this solution is to partition each color into each different zone.

Because of the small input range (only three colors, say, 3 numbers), and all of the colors are
sorted, I'll move all of the number `0` to the left of the array, move all number `2` to the right
of the array.

Moving elements in an array will lead to a more complex solution, we need to shift the other elements!

In order to do it in just one pass looping, I need to maintain the left-most and right-most boundaries, telling 
us where is the last `0` number, and the first `2` number.

Each time we need to shift a number to its position, we just swap it with the nearest number from the boundaries, then move
the boundaries.

# Problem 3

Leetcode URL: https://leetcode.com/problems/word-frequency/description/

I don't like it so I don't do it
