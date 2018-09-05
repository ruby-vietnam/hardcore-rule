# Week 36

### Climbing Stairs (easy)

- Fibonacci problems using dynamic programming

```js
// https://leetcode.com/problems/climbing-stairs/description/

/**
 * @param {number} n
 * @return {number}
 */
function climbStairs(n) {
  if (n === 1) return 1;
  if (n === 2) return 2;
  const dynamicArray = { 1: 1, 2: 2 };
  for (let i = 3; i <= n; i++) {
    dynamicArray[i] = dynamicArray[i - 1] + dynamicArray[i - 2];
  }
  return dynamicArray[n];
}
```

### Longest Substring Without Repeating Characters (medium)

- Derived from sliding window problem

```js
// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

/**
 * @param {string} s
 * @return {number}
 */
function lengthOfLongestSubstring(s) {
  if (s === "") return 0;
  const charIndexMap = {};
  const dynamicArray = Array(s.length).fill(0);
  for (let i = 0; i < s.length; i++) {
    const c = s[i];
    if (charIndexMap[c] === undefined) {
      dynamicArray[i] = (dynamicArray[i - 1] || 0) + 1;
    } else {
      dynamicArray[i] = Math.min(i - charIndexMap[c], dynamicArray[i - 1] + 1);
    }
    charIndexMap[c] = i;
  }

  let longest = 0;
  for (let i = 0; i < dynamicArray.length; i++) {
    longest = Math.max(longest, dynamicArray[i]);
  }
  return longest;
}
```

### Course Schedule (medium)

```js
/**
 * @param {number} numCourses
 * @param {number[][]} prerequisites
 * @return {boolean}
 */
function canFinish(numCourses, prerequisites) {
  if (prerequisites.length === 0) return true;
  if (numCourses === 0) return true;
  const graph = buildGraph(prerequisites);
  // memoized table
  const finishable = {};
  for (let node = 0; node < numCourses; node++) {
    if (!isFinishable(node, graph, finishable, {})) return false;
  }
  return true;
}

// check if single course can be finished
function isFinishable(node, graph, finishable = {}, visited = {}) {
  if (graph[node] === undefined) return true;
  if (finishable[node]) return finishable[node];
  if (visited[node]) return false;
  const prerequisites = Object.keys(graph[node]);
  const newVisited = Object.assign({}, visited, { [node]: true });

  // course can be finished === all prerequiste can be finished
  for (let i = 0; i < prerequisites.length; i++) {
    const prerequiste = prerequisites[i];
    if (!isFinishable(prerequiste, graph, finishable, newVisited)) {
      finishable[node] = false;
      return false;
    }
  }

  finishable[node] = true;
  return true;
}

function buildGraph(prerequisites) {
  const graph = {};
  for (let i = 0; i < prerequisites.length; i++) {
    const [course, prerequisite] = prerequisites[i];
    if (!graph[course]) graph[course] = {};
    graph[course][prerequisite] = true;
  }
  return graph;
}
```
