# Problem 1:
#### [Hamming Distance](https://leetcode.com/problems/hamming-distance/)
```java
class Solution {
    public int hammingDistance(int x, int y) {
        return Integer.bitCount(x ^ y);
    }
}
```
# Problem 2:
#### [Network Delay Time](https://leetcode.com/problems/network-delay-time/)
```java
class Solution {
    public int networkDelayTime(int[][] times, int N, int K) {
        List<Edge>[] graph = new List[N];
        for (int i = 0; i < N; i++) {
            graph[i] = new ArrayList<Edge>();
        }
        for (int i = 0; i < times.length; i++) {
            graph[times[i][0] - 1].add(new Edge(times[i][1] - 1, times[i][2]));
        }
        PriorityQueue<Node> nodes = new PriorityQueue<>();
        nodes.add(new Node(K-1,0));
        int[] cost = new int[N];
        Arrays.fill(cost, Integer.MAX_VALUE);
        cost[K-1] = 0;
        boolean[] visited = new boolean[N];
        while (!nodes.isEmpty()) {
            Node current = nodes.poll();
            if(visited[current.index]) continue;
            visited[current.index] = true;
            for(Edge e : graph[current.index]) {
                int newCost = cost[current.index] + e.w;
                if(newCost < cost[e.v]) {
                    cost[e.v] = newCost;
                    nodes.add(new Node(e.v, cost[e.v]));
                }
            }
        }

        int max = 0;
        for (int i = 0; i < N; i++) {
            max = Math.max(cost[i], max);
        }

        return max == Integer.MAX_VALUE ? -1 : max;
    }
}

class Edge {
    int v;
    int w;

    public Edge(int v, int w) {
        this.v = v;
        this.w = w;
    }
}

class Node implements Comparable<Node>{
    int index;
    int cost;

    public Node(int index, int cost) {
        this.index = index;
        this.cost = cost;
    }

    @Override
    public int compareTo(Node o) {
        return this.cost - o.cost;
    }
}
```
# Problem 4:
#### [Word Ladder II](https://leetcode.com/problems/word-ladder-ii/)
```java
class Solution {
    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        List<List<String>> res = new ArrayList<>();
        int n = wordList.size() + 1;
        int target = -1;
        for (int i = 0; i < wordList.size(); i++) {
            if (endWord.endsWith(wordList.get(i))) {
                target = i + 1;
                break;
            }
        }
        if (target == -1) {
            return res;
        }
        boolean[] visited = new boolean[n];
        int[] cost = new int[n];
        Arrays.fill(cost, Integer.MAX_VALUE);
        List<Integer>[] graph = buildGraph(beginWord, wordList);
        List<Integer>[] prev = new List[n];
        for (int i = 0; i < n; i++) {
            prev[i] = new ArrayList<>();
        }
        Queue<Integer> queue = new LinkedList<>();
        queue.add(0);
        cost[0] = 0;
        while (!queue.isEmpty()) {
            int current = queue.poll();
            for (int v : graph[current]) {
                if (cost[current] + 1 < cost[v] && !visited[v]) {
                    cost[v] = cost[current] + 1;
                    prev[v].add(current);
                    visited[v] = true;
                    queue.add(v);
                } else if (cost[current] + 1 == cost[v]) {
                    prev[v].add(current);
                }
            }
        }
        if (cost[target] == Integer.MAX_VALUE) {
            return res;
        }
        trace(res, beginWord, wordList, prev, new int[cost[target]], cost[target] - 1, target);
        return res;
    }

    private void trace(List<List<String>> res, String beginWord, List<String> wordList, List<Integer>[] prev, int[] path, int idx, int current) {
        if (current == 0) {
            List<String> steps = new ArrayList<>();
            steps.add(beginWord);
            for (int i = 0; i < path.length; i++) {
                steps.add(wordList.get(path[i] - 1));
            }
            res.add(steps);
        } else {
            path[idx] = current;
            idx--;
            for (int v : prev[current]) {
                trace(res, beginWord, wordList, prev, path.clone(), idx, v);
            }
        }
    }

    private List<Integer>[] buildGraph(String beginWord, List<String> wordList) {
        List<Integer>[] graph = new List[wordList.size() + 1];
        for (int i = 0; i < graph.length; i++) {
            graph[i] = new ArrayList<Integer>();
        }
        for (int i = 0; i < wordList.size(); i++) {
            if (canGo(beginWord, wordList.get(i))) {
                graph[0].add(i + 1);
                graph[i + 1].add(0);
            }
        }
        for (int i = 0; i < wordList.size(); i++) {
            for (int j = i + 1; j < wordList.size(); j++) {
                if (canGo(wordList.get(i), wordList.get(j))) {
                    graph[i + 1].add(j + 1);
                    graph[j + 1].add(i + 1);
                }
            }
        }

        return graph;
    }

    private boolean canGo(String from, String to) {
        int diff = 0;
        if (from.length() != to.length()) return false;
        for (int i = 0; i < from.length() && diff < 2; i++) {
            if (from.charAt(i) != to.charAt(i)) ++diff;
        }

        return diff == 1;
    }
}
```