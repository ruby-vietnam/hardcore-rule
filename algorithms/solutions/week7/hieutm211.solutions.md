## Problem 3

```
//Solution O(n):
//Gọi L[i] = số thằng có rating nhỏ dần về bên trái của i
//Gọi R[i] = số thằng có rating nhỏ dần về bên phải của i
//Số kẹo chia tối ưu cho thằng i = max(L[i], R[i]) + 1;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int ans, L, R[ratings.size()+1];
        
        R[ratings.size()-1] = 0;
        for (int i = ratings.size()-2; i >= 0; --i) 
            R[i] = ratings[i] <= ratings[i+1] ? 0 : R[i+1] + 1;
        
        L = 0; ans = R[0] + 1;
        for (int i = 1; i < ratings.size(); ++i){
            L = ratings[i] <= ratings[i-1] ? 0 : L+1;
            ans += max(L, R[i]) + 1;
        }
        
        return ans;
    }
};
```

## Problem bonus 2

```
//ý tưởng: Dùng mảng cnt[c] : số lượng kí tự c trong string

class Solution {
public:
    int cnt[27];
    int firstUniqChar(string s) {
        for (auto& c : s) ++cnt[c-'a'];
        for (int i = 0; i < s.size(); ++i) 
            if (cnt[s[i]-'a'] == 1) return i;
        return -1;
    }
};

```
