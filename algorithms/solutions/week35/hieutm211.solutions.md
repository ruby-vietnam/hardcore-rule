
##Problem 1

```cpp

#include <iostream>
using namespace std;

int main(){
    int n, k;
    long long tmp, f[2];

    cin >> n >> k;

    f[0] = 0;
    f[1] = k-1;

    for (int i = 1; i < n; ++i){
        tmp = f[1];
        f[1] = f[0] * (k-1) + f[1] * (k-1);
        f[0] = tmp;
    }

    cout << f[0] + f[1] << endl;
    return 0;
}

```

##Problem 3

```cpp
class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<int> adj[N];
        stack<int> st;
        int lab[N];
        
        adj[N].clear();
        for (int i = 0; i < dislikes.size(); ++i){
            adj[dislikes[i][0]-1].push_back(dislikes[i][1]-1);
            adj[dislikes[i][1]-1].push_back(dislikes[i][0]-1);
        }
        
        for (int i = 0; i < N; ++i) lab[i] = -1;
        
        lab[0] = 0;
        st.push(0);
        while (!st.empty()){
            int u = st.top();
            st.pop();
            for (auto& v : adj[u]){
                if (lab[v] == lab[u]) return 0;
                else if (lab[v] == -1){
                    lab[v] = 1 - lab[u];
                    st.push(v);
                }
            }
            
        }
        return 1;
    }
};
```
