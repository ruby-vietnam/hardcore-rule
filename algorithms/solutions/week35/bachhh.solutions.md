# Problem 2
```cpp
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        vector<vector<int>> ret;
        int step_c = 1, step_r = 0, dr = 0, dc = 0;
        int count = 0;
        while(count < R*C){
            if(r0+dr < R && c0 + dc < C && r0+dr >= 0 && c0+dc >= 0){
                vector<int> v = {r0+dr, c0+dc};
                count++;
                ret.push_back(v);
            }
            if (dr == 0 && dc == 0){
            } else if (
               (dr == dc) ||
               (dr > 0 && dr == -dc) ||
               (dr<= 0 && -dr +1 == dc)){
                int t = step_r;
                step_r = step_c;
                step_c = -t;

            }
            dr += step_r;
            dc += step_c;
        }
        return ret;
    }
};
```
