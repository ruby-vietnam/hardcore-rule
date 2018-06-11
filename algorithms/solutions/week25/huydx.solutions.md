# Problem 1

```java
class Solution {
    
    public String[] findWords(String[] words) {
        int[] row1 = new int[100];
        int[] row2 = new int[100];
        int[] row3 = new int[100];
        String row1s = "qwertyuiop";
        String row2s = "asdfghjkl";
        String row3s = "zxcvbnm";
        for (char c : row1s.toCharArray()) { row1[intOf(c)] = 1; }
        for (char c : row2s.toCharArray()) { row2[intOf(c)] = 1; }
        for (char c : row3s.toCharArray()) { row3[intOf(c)] = 1; }
        int[][] rowIdx = new int[][]{row1, row2, row3};
        List<String> r = new ArrayList<>();
        
        for (String word : words) {
            if (sameRowWord(word, rowIdx)) {
                r.add(word);
            }
        }
        return r.toArray(new String[r.size()]);
    }
    
    private boolean sameRowWord(String word, int[][] rowIndices) {
        int[] curRow = null;
        for (char c : word.toCharArray()) {
            if (curRow == null) {
                for (int[] rowIdx : rowIndices) {
                    if (rowIdx[intOf(c)] == 1) {
                        curRow = rowIdx;
                        continue;
                    }
                }
            } else {
                if (curRow[intOf(c)] != 1) {
                    return false;
                }
            }
        }
        return true;
    }
    
    private int intOf(char c) {
        int r = c-'a';
        if (r < 0) {
            return c-'A';
        } else {
            return r;
        }
    }
}
```

# Problem 2

```java
class Solution {
    
    public int findCircleNum(int[][] M) {
        int[] visited = new int[M.length];
        for (int v = 0; v < visited.length; v++) {
            visited[v] = -1;
        }
        int cluster = 0;
        for (int i = 0; i < M.length; i++) {
            if (dfs(M, i, visited, cluster) == -1) {
                cluster++;
            }
        }
        return cluster;
    }

    public int dfs(int[][] graph, int vertex, int[] visited, int cluster) {
        if (visited[vertex] != -1) {
            return visited[vertex];
        }
        visited[vertex] = cluster;
        int[] friends = graph[vertex];
        for (int i = 0; i < friends.length; i++) {
            if (friends[i] == 1 && i != vertex) {
                dfs(graph, i, visited, cluster);
            }
        }
        return -1;
    }
}
```

# Problem 3

```java
class Solution {
    private static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a%b);
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String arrStr = scan.next();
        int len = scan.nextInt();
        String[] arrS = arrStr.split(" ");
        int[] arr = new int[len];
        for (int i = 0; i < len; i++) {
            arr[i] = Integer.parseInt(arrS[i]);
        }

        // if there any 1, we have solution
        int num1=0;
        for (int i = 0; i < len; i++) {
           if (arr[i] == 1) {
               num1++;
           }
        }
        if (num1 > 0) {
            System.out.println(len-num1);
            return;
        }

        int ans = Integer.MAX_VALUE;

        // else find an continous array which have gcd = 1 and minimum len
        for (int i = 0; i < len; i++) {
            int x = arr[i];
            for (int j = i+1; j < len; j++) {
                x = gcd(x, arr[j]);
                if (x == 1) {
                    ans = Math.min(ans, j - 1);
                }
            }
        }
        if (ans == Integer.MAX_VALUE) {
            System.out.println(-1);
        } else {
            System.out.println(ans);
        }
    }
}
```
