# problem 3
```cpp
class Solution {
public:
    void dfs(vector<vector<int>> am, int node, vector<bool> &marker, vector<int> &postNum, int &counter){
        if (marker[node]== true ){return;}
        marker[node] = true;
        counter++;
        for(int i : am[node]){
            dfs(am, i, marker, postNum, counter);
        }
        postNum[node] = counter;
        counter++;
        return;
    }
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> am = vector<vector<int>>(numCourses, vector<int>(0));
        vector<bool> marker = vector<bool>(numCourses, false);
        vector<int> postNum = vector<int>(numCourses, -1);
        int c = 0;
        for(int i = 0; i < prerequisites.size(); ++i){
            int x = prerequisites[i].second;
            int y = prerequisites[i].first;
            am[x].push_back(y);
        }
        for(int i = 0; i < numCourses; i++){
            if (!marker[i]){
                dfs(am, i, marker, postNum, c);
            }
        }
        for(auto p : prerequisites){
            if (postNum[p.second] < postNum[p.first]){
                return false;
            }
        }
        return true;
    }
};
```
