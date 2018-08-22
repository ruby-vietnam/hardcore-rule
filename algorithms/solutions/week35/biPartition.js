// https://leetcode.com/contest/weekly-contest-97/problems/possible-bipartition/

/**
 * @param {number} N
 * @param {number[][]} dislikes
 * @return {boolean}
 */
var possibleBipartition = function(N, dislikes) {
  const visited = {};
  const graph = buildGraph(dislikes);
  return traverseGraph(N, graph, visited);
};

function buildGraph(dislikes) {
  const graph = {};
  for (let i = 0; i < dislikes.length; i++) {
    const [x, y] = dislikes[i];
    if (!graph[x]) graph[x] = {};
    if (!graph[y]) graph[y] = {};
    graph[x][y] = true;
    graph[y][x] = true;
  }
  return graph;
}

function traverseGraph(N, graph, visited) {
  // select next unvisited graph
  let startingNode = null;
  for (let i = 1; i <= N; i++) {
    if (!visited[i]) {
      startingNode = i;
      break;
    }
  }
  if (!startingNode) return true;

  // traverse and mark node to group 1 || group 2
  // using BFS
  visited[startingNode] = 1;
  const queue = [startingNode];
  while (queue.length > 0) {
    const node = queue.shift();
    const neighbours = graph[node] ? Object.keys(graph[node]) : [];
    const nodeGroup = visited[node];
    for (let i = 0; i < neighbours.length; i++) {
      const neighbour = neighbours[i];
      if (visited[neighbour] === nodeGroup) return false;
      if (visited[neighbour] === undefined) {
        visited[neighbour] = 3 - nodeGroup;
        queue.push(neighbour);
      }
    }
  }

  // There might still have disconnected graph
  return traverseGraph(N, graph, visited);
}
