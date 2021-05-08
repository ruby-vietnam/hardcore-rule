# 1812. Determine Color of a Chessboard Square
  
### Approach
We can easily have a conclusion that if we rewrite the coordination into `(0,0)`, so the coordinate `X` and `Y` pair can have 2 possible cases:
- Both `X` and `Y` are even numbers: so the square is black
- Both `X` and `Y` are odd numbers: so the square is white 

### Submission

```java
class Solution {
    public boolean squareIsWhite(String coordinates) {
        int col = coordinates.charAt(0) - 'a';
        int row = coordinates.charAt(1) - '1';
        
        return !(col % 2 == row % 2);
    }
}
```

### Submission detail

| Status   | Runtime     | Memory   | Language  |
| ---      | ----------- | -------- | --------- |
| Accepted | 0ms         | 37.2 MB  | java      |

### Analyze
- Time complexity: **O(1)**
- Space complexity: **O(1)**

# 935. Knight Dialer

### Approach

From the example with `n = 2` we have the mapping array.

```
final int[][] m = new int[][]{
                new int[]{4, 6},
                new int[]{6, 8},
                new int[]{7, 9},
                new int[]{4, 8},
                new int[]{0, 3, 9},
                new int[]{},
                new int[]{0, 1, 7},
                new int[]{2, 6},
                new int[]{1, 3},
                new int[]{2, 4}
        };
```

The approach is we will build an 2 dimension matrix to save the each jump, the `k th` jump result is based on `k-1 th` jump.

### Submission

```
public class Solution {
    public int knightDialer(int n) {
        final int mod = (int) 1e9 + 7;
        final int[][] m = new int[][]{
                new int[]{4, 6},
                new int[]{6, 8},
                new int[]{7, 9},
                new int[]{4, 8},
                new int[]{0, 3, 9},
                new int[]{},
                new int[]{0, 1, 7},
                new int[]{2, 6},
                new int[]{1, 3},
                new int[]{2, 4}
        };
        double[][] dp = new double[n + 1][10];
        for (int i = 0; i < 10; i++) {
            dp[1][i] = 1;
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k : m[j]) {
                    dp[i][j] += dp[i - 1][k];
                }
                dp[i][j] = dp[i][j] % mod;
            }
        }
        double sum = 0;
        for (int i = 0; i < 10; i++) {
            sum += dp[n][i];
        }

        return (int) (sum % mod);
    }
}
```

### Submission detail

| Status   | Runtime     | Memory   | Language  |
| ---      | ----------- | -------- | --------- |
| Accepted | 68ms        | 53.1 MB  | java      |

### Analyze
- Time complexity **O(n)**
- Space complexity **O(n)**
