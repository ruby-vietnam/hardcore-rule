# Problem 2 - [Spiral-matrix-iii](https://leetcode.com/contest/weekly-contest-97/problems/spiral-matrix-iii/)

```cpp
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        vector<vector<int>> result;
        int n = R * C;
        result.push_back(vector<int>{r0, c0});
        for (int i = 0; n > 1; i++) {
            int d = i % 4;
            int nstep = i / 2 + 1;
            for (int j = 0; j < nstep; j++) {
                if (d == 0) {
                    c0 = c0 + 1; // go right
                } else if (d == 1) {
                    r0 = r0 + 1; // go down
                } else if (d == 2) {
                    c0 = c0 - 1; // go left
                } else if (d == 3) {
                    r0 = r0 - 1; // go up
                }
                if (r0 >= 0 && r0 < R && c0 >= 0 && c0 < C) {
                    result.push_back(vector<int>{r0, c0});
                    n = n - 1;
                }
            }
        }
        return result;
    }
};
```
