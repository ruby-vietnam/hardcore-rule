#Bai 1: 
```
class Solution {
public:
    int climbStairs(int n) {
        int a[100000] = {};
        a[0] = 0;
        a[1] = 1;
        a[2] = 2;
        if (n <= 2 && n >= 0) return a[n];
        for (int i = 3; i <= n; i++)
        {
            a[i] = a[i-1] + a[i-2];
            
        }
        return a[n];
    }
};
```

#Bai 2:
```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = -1;
        int a[10000];
        std::fill_n(a, 10000, -1);

        int max = 0;
        for (int i = 0; i != s.length(); i++) {
            if (a[s[i]] > left)
                left = a[s[i]];
            a[s[i]] = i;
            max = std::max(max, i - left);
        }

        return max;
    }
};
```
#Bai 3:

#Bai 4:

```
class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        
        std::sort(A.begin(), A.end());
        long mod = 1e9 + 7, p =1 , result = 0;
        for(int i = 0; i < A.size(); result +=  A[i] * p - A[A.size() - i - 1] * p , result %= mod,  i++, p = (p << 1) % mod) {}
        return result;
    }
}; 
```

