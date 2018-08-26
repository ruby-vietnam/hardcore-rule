Problem3: https://leetcode.com/problems/possible-bipartition/description/

```java
    Integer[][] graph;

  public boolean possibleBipartition(int N, int[][] dislikes) {
    graph = new Integer[N+1][N+1];
    for (int i = 0; i <= N;i++) {
      for (int j = 0; j <= N; j++) {
        graph[i][j] = null;
      }
    }

    for(int[] edge: dislikes) {
      graph[edge[0]][edge[1]] = 1;
      graph[edge[1]][edge[0]] = 1;
    }

    int[] colors = new int[N+1];
    for (int i = 0; i <= N;i++) {
      colors[i] = -1;
    }

    colors[1] = 1;
    Queue<Integer> queue = new LinkedList<>();
    queue.add(1);

    while (!queue.isEmpty()) {
      int u = ((LinkedList<Integer>) queue).pop();
      if (graph[u][u] != null) return false;
      for (int v = 1; v <= N; v++) {
        if (graph[u][v] != null && colors[v] == -1) {
          colors[v] = 1 - colors[u];
          queue.add(v);
        } else if (graph[u][v] != null && colors[v] == colors[u]) {
          return false;
        }
      }
    }
    return true;
  }

```
