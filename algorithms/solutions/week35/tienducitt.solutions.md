# Problem 3:
https://leetcode.com/contest/weekly-contest-97/problems/possible-bipartition/

```java
class Solution {
    List<Integer>[] dl;
    int[] visisted;
    
    public boolean possibleBipartition(int N, int[][] dislikes) {
        dl = new List[N + 1];
        visisted = new int[N + 1];

        for (int i = 1; i <= N; i++) {
            dl[i] = new ArrayList<Integer>();
        }

        for (int i = 0; i < dislikes.length; i++) {
            int[] pair = dislikes[i];
            dl[pair[0]].add(pair[1]);
            dl[pair[1]].add(pair[0]);
        }

        for (int i=1; i <= N; i++) {
            if (visisted[i] == 0) {
                if (!visit(i, 1)) {
                    return false;
                }
            }
        }

        return true;
    }

    public boolean visit(int i, int level) {
        visisted[i] = level;

        for (int h : dl[i]) {
            if (visisted[h] != 0) {
                if ((visisted[h] - level) % 2 == 0) {
                    return false;
                }
            } else {
                 if (!visit(h, level+1)) {
                     return false;
                 }
            }
        }

        return true;
    }
}
```