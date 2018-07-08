Problem2: https://www.spoj.com/problems/ELEVTRBL/

We can use BFS to solve this problem. The idea is we just go up first until can't go up, then we will go down. We will have the visited array which keep all the floor. 
Then when we go up or go down to one floor, we will update the value of that floor by previous floor + 1 (one more button to go to that floor from previous floor).

```java
public static void main(String[] args) {
    
    int f = Integer.parseInt(args[0]);
    int s = Integer.parseInt(args[1]);
    int g = Integer.parseInt(args[2]);
    int u = Integer.parseInt(args[3]);
    int d = Integer.parseInt(args[4]);
    
    int[] visited = new int[f+1];
    for (int i = 0; i < f+1;i++) {
      visited[i] = 0;
    }
    visited[s] = 1;
    Queue<Integer> queue = new LinkedList<>();
    queue.offer(s);
    while (!queue.isEmpty()) {
      int cur = queue.poll();
      if (cur + u <= f && visited[cur+u] == 0) {
        visited[cur+u] = visited[cur] + 1;
        queue.offer(cur + u);
      }
      if (cur - d >= 1 && visited[cur - d] == 0) {
        visited[cur - d] = visited[cur] + 1;
        queue.offer(cur - d);
      }
    }
    
    if (visited[g] == 0) {
      System.out.println("use the stairs");
    } else {
      System.out.println(visited[g] - 1);
    }
    
  }
```
