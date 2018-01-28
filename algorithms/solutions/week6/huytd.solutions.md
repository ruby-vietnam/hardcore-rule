# Problem 1: Degree of an Array

URL: https://leetcode.com/problems/degree-of-an-array/description/

Status:
```
  ✔ Accepted
  ✔ 89/89 cases passed (137 ms)
  ✔ Your runtime beats 74.55 % of javascript submissions
```

<details>
  <summary><b>Naive Solution</b>: O(n^2) - TLE</summary>

The naive solution is truthly naive, and it's not acceped due to TLE (time limit exceeded).

In this solution, I created a `findDegree` function to calculate the degree of a given array, then use it to find the initinal degree of an input array, let call this 'deg`.

We then try generate every possible subarray `arr` to see if the degree of this subarray matched the input array's degree or not.

Since we're finding the shortest possible subarray, the subarray should have the minimum length of `deg`, so we can save some time by starting generating subarray of length `k = deg`.

```javascript
const findDegree = (n) => {
  let freq = {}; let max = 0;
  for (let i = 0; i < n.length; i++) {
    let s = n[i];
    if (!freq[s]) freq[s] = 0;
    freq[s]++;
    if (freq[s] > max) max = freq[s];
  }
  return max;
};

var findShortestSubArray = function(nums) {
  let deg = findDegree(nums);
  let k = deg;
  while (k <= nums.length) {
    for (let i = 0; i <= k; i++) {
      let arr = nums.slice(i, i + k);
      let dega = findDegree(arr);
      if (dega == deg) return k;
    }
    k++;
  }
  return n;
};
```
</details>

<details open>
  <summary><b>Counting Solution:</b> O(n) - Accepted</summary>

The better approach only required one loop.

Because the subarrays should be contiguous, we only have to loop through the input array once, for each digit, we do the following things:

- Count the occurrence of that digit (_by doing this, we can find the highest frequence digit in the array._)
- Calculate the distance between the first index where we found it and the current position (_by doing this, we can find the minimum length of the subarray_)

The final step is to find out which one has the highest frequence and shortest length of subarray. This can be done in a separate `for` loop, which still have O(n) time complexity, but we can just do it in the same loop, so here's the code:

```javascript
var findShortestSubArray = function(nums) {
  let count = {}; let maxFreq = 0; let minDistance = 0;
  for (let i = 0; i < nums.length; i++) {
    let n = nums[i];
    if (!count[n]) count[n] = { val: 0, start: i, end: i, distance: 0 };
    count[n].val += 1;
    count[n].end = i;
    count[n].distance = count[n].end - count[n].start + 1;
    if (maxFreq <= count[n].val) {
      if (maxFreq < count[n].val) {
        minDistance = count[n].distance;
      }
      maxFreq = count[n].val;
      if (minDistance > count[n].distance) {
        minDistance = count[n].distance;
      }
    }
  }
  return minDistance;
};
```
</details>

# Problem 2: 01 Matrix

URL: https://leetcode.com/problems/01-matrix/description/

Status:
```
  ✔ Accepted
  ✔ 48/48 cases passed (674 ms)
  ✔ Your runtime beats 16 % of javascript submissions
```

Approach: Start from `0` cells, use BFS to traverse the array, like a virus, at each cell, if the value is `1`, we replace it with the distance count.

It's a must to track visited cells, and when counting the distance, you must only count from visited cells

```javascript
// px, py: previous cells
// x, y: current cells
if (visited[y][x] === 0 && visited[py][px] === 1 && matrix[y][x] !== 0) {
  let distance = matrix[py][px] + 1;
  if (minDistance > distance) minDistance = distance;
}
```

Implementation:

```javascript
const directions = [[0, -1], [0, 1], [-1, 0], [1, 0]];

var updateMatrix = function(matrix) {
  let h = matrix.length; let w = matrix[0].length;
  let queue = []; let minDistance;
  let visited = Array.from(Array(h)).map(row => Array.from(Array(w)).map(col => 0));
  let y = x = py = px = ny = nx = 0;

  for (y = 0; y < h; y++) {
    for (x = 0; x < w; x++) {
      if (matrix[y][x] === 0) {
        queue.push([y,x]);
        visited[y][x] = 1;
      }
    }
  }

  while (queue.length) {
    [y, x] = queue.shift(); 
    minDistance = 0x7FFFFFFF;

    for (dir of directions) { 
      py = y - dir[0]; px = x - dir[1];
      if (py < h && py >= 0 && px < w && px >= 0) {
        if (visited[y][x] === 0 && visited[py][px] === 1 && matrix[y][x] !== 0) {
          let distance = matrix[py][px] + 1;
          if (minDistance > distance) minDistance = distance;
        }
      }
    }

    if (minDistance != 0x7FFFFFFF) {
      matrix[y][x] = minDistance;
      visited[y][x] = 1;
    }

    for (dir of directions) { 
      ny = y + dir[0]; nx = x + dir[1]; 
      if (ny < h && ny >= 0 && nx < w && nx >= 0) {
        if (matrix[ny][nx] !== 0 && visited[ny][nx] === 0) {
          queue.push([ny, nx]);
        }
      }
    }
  }

  return matrix;
};
```

Guess what!? `0x7FFFFFFF` is `MAX_INT32`.

# Problem 3: Rotate Image

URL: https://leetcode.com/problems/rotate-image/description/

Status:
```
  ✔ Accepted
  ✔ 21/21 cases passed (105 ms)
  ✔ Your runtime beats 30.66 % of javascript submissions
```

The approach is simple:

- First, we transpose the input matrix
- Then reverse the columns of the transposed matrix

```javascript
var rotate = function(matrix) {
  let n = matrix.length;
  // transpose
  for (let i = 0; i < n; i++) {
    for (let j = i; j < n; j++) {
      [ matrix[i][j], matrix[j][i] ] = [ matrix[j][i], matrix[i][j] ];
    }
  }
  // reverse columns
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n/2; j++) {
      [ matrix[i][j], matrix[i][n-j-1] ] = [ matrix[i][n-j-1], matrix[i][j] ];
    }
  }
};
```
