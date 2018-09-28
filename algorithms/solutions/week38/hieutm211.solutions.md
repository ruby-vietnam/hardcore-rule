##Problem 2

```cpp
class Solution {
public:
    int find(int code, vector<vector<int>>& matrix, int id, int L, int R, int x){
        int mid, tmp;
        while (L <= R){
            mid = (L+R)/2;
            tmp = (!code ? matrix[mid][id] : matrix[id][mid]);
            if (tmp == x) return 1;
            else if (tmp < x) L = mid + 1;
            else R = mid - 1;
        }    
        return 0;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (!matrix.size() || !matrix[0].size()) return 0;


        for (int i = 0; i < matrix[0].size()-1; ++i)
            if (find(0, matrix, i, 0, matrix.size()-1, target)) return 1;        
        
        for (int i = 0; i < matrix.size(); ++i) 
            if (find(1, matrix, i, 0, matrix[i].size()-1, target)) return 1;
        
        return 0;
    }
};
```
