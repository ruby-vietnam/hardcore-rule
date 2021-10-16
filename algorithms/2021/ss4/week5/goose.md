# 1. Triangle
https://leetcode.com/problems/triangle/

## 1.1. Approach
DFS with dynamic programming. Sub problem is: from this index of this row, what is the minimum step to reach bottom. Reaching the bottom is like traversing a graph where each node has only two edges (two neighbor directly below it).

## 1.2. Code
```js
/**
 * @param {number[][]} triangle
 * @return {number}
 */
var minimumTotal = function (triangle) {
  let memo = {};

  // What is the total minimum to reach bottom from this index in this row
  function subProblem(row, index) {
    const key = `${row}_${index}`;
    if (key in memo) {
      return memo[key];
    }

    if (row === triangle.length - 1) {
      return (memo[key] = triangle[row][index]);
    }

    const right = subProblem(row + 1, index + 1);
    const left = subProblem(row + 1, index);
    const result = triangle[row][index] + Math.min(right, left);
    memo[key] = result;
    return result;
  }

  subProblem(0, 0);
  return memo['0_0'];
};
```

# 2 Palindrome Partitioning
https://leetcode.com/problems/palindrome-partitioning/

## 2.1. Approach
We do it in two phase
- Phase 1: Find out all palindrome substring and store them in a map
- Phase 2: Construct all the substring array. Imagine construct the array like traversing a graph where we start at index 0 and target is the final index. For every substring palindrome we found at Phase 1, we have an edge from start index node to (end index + 1) node. For example:
String: "abac"
Graph: {
  0: [1, 3],
  1: [2],
  2: [3],
  3: [4]
}
Remember, a node will have at least one edge because in single letter substring is a palindrome.

## 2.2. Code
```js
/**
 * @param {string} s
 * @return {string[][]}
 */
var partition = function (s) {
  // Find out all palimdrome substring
  let record = {};
  for (let i = 0; i < s.length; i = i + 0.5) {
    let j = i % 1 === 0 ? 1 : 0.5;
    while (s[i - j] === s[i + j] && i - j >= 0 && i + j < s.length) {
      const start = i - j;
      const end = i + j;
      if (start in record) record[start].push(end);
      else record[start] = [end];
      j++;
    }
  }

  let result = [];

  function dfs(array, currentIndex) {
    if (currentIndex === s.length - 1) return result.push([...array]);
    const start = currentIndex + 1;
    let edges = [start];
    if (start in record) edges = edges.concat(record[start]);
    for (let end of edges) {
      array.push(s.slice(start, end + 1));
      dfs(array, end);
      array.pop();
    }
  }

  dfs([], -1);
  return result;
};
```