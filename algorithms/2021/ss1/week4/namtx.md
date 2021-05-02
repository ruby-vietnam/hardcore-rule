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


