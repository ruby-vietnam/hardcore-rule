# Swim in Rising Water

```cpp
class Solution {
public:
    const int dx[4] = {-1, 0, 0, 1};
    const int dy[4] = {0, -1, 1, 0};
    
    int n, u, v;
    bool visited[51][51];

    void visit(vector<vector<int>>& grid, int x, int y, int L){
        if (grid[x][y] > L) return;
        visited[x][y] = 1;
        if (x == n-1 && y == n-1) return;
        for (int i = 0; i < 4; ++i){
            u = x + dx[i];
            v = y + dy[i];
            if (u < 0 || u > n-1 || v < 0 || v > n-1) continue;
            if (!visited[u][v]) visit(grid, u, v, L);
        }
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        int L, R, mid, ans;
        
        n = grid.size();        
        
        L = 0; R = n*n-1; ans = n*n-1; 
        while (L <= R){
            mid = (L+R)/2;
            
            for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                visited[i][j] = 0;
            
            visit(grid, 0, 0, mid);
            
            if (visited[n-1][n-1]){
                ans = mid;
                R = mid-1;
            } else L = mid+1;
        }
        
        return ans;
    }
};
```