## 1. Determine Color of a Chessboard Square
### 1.1. Summary
| Runtime  | Faster than | Memory   | Less than |
| :----:   | :----:      | :----:   | :----:    |
| 0ms      | 100%        | 5.9 MB   | 62.38%    |

### 1.2. Solution summary
I translate _[a..z]_ to _[1..27]_. Ok then, if it is odd row,
it should be even column and vice versa to be white cell.

### 1.3. Source code
```cpp
class Solution {
public:
    bool squareIsWhite(string coordinates) {
        return ((coordinates[0] - 'a' + 1) & 1)
            + ((coordinates[1] - '0') & 1) == 1;
    }
};
```
