Problem1: https://leetcode.com/problems/hamming-distance/description/

We can use XOR between x and y, then make the value to binary value, while we loop to make binary value, we can calculate the result if we meet 1

Time Complexity is O(log(n)).

```java
public int hammingDistance(int x, int y) {
    int xor = x ^ y;
    int result = 0;
  while (xor > 0) {
    result += (xor % 2);
    xor /= 2;
  }
  return result;
}
```

Problem2: https://leetcode.com/problems/network-delay-time/description/

We use Dijkstra to find the shortest path from source to all other node. Take note that we need to have shortest path (time) because one node can get elapse time for signal comes from different nodes. 

Time Complexity is O(N^2), there is better performance if we use Heap and I am reading about it

```java
public int networkDelayTime(int[][] times, int N, int K) {
    Map<Integer, Integer> dist = new HashMap<>();
    // load all time and vertex to graph
    Integer[][] graph = new Integer[N + 1][N + 1];
    for (int[] edge : times) {
      graph[edge[0]][edge[1]] = edge[2];
    }

    // initialize the distance map to infinite value
    for (int v = 1; v <= N; v++) {
      dist.put(v, Integer.MAX_VALUE);
    }

    dist.put(K, 0);
    boolean[] visited = new boolean[N + 1];// as we loop from

    for (int c = 1; c <= N; c++) {
      int minDistVertex = getMinDistanceVertex(dist, visited);
      visited[minDistVertex] = true;
      System.out.println(
          "c: " + c + ", minDistVertex: " + minDistVertex + ",dist.get(minDistVertex): " + dist.get(minDistVertex));
      // get all adjacent vertext (neighbor vertex)
      for (int v = 1; v <= N; v++) {
        System.out.println("graph[" + minDistVertex + "][" + v + "]: " + graph[minDistVertex][v] + ", dist.get(" + v
            + "): " + dist.get(v));
        if (!visited[v] && graph[minDistVertex][v] != null
            && dist.get(minDistVertex) + graph[minDistVertex][v] < dist.get(v)) {
          dist.put(v, dist.get(minDistVertex) + graph[minDistVertex][v]);
        }
      }
    }

    // because the
    int result = 0;
    for (int v : dist.keySet()) {
      if (dist.get(v) == Integer.MAX_VALUE)
        return -1;
      result = Math.max(result, dist.get(v));
    }
    return result;
  }

  private int getMinDistanceVertex(Map<Integer, Integer> dist, boolean[] visited) {
    int minDist = Integer.MAX_VALUE;
    int minDistVertex = 0;
    for (Integer v : dist.keySet()) {
      if (!visited[v] && dist.get(v) < minDist) {
        minDistVertex = v;
        minDist = dist.get(v);
      }
    }
    return minDistVertex;
  }
```
