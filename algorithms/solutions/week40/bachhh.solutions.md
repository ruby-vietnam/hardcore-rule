# Problem 2

```cpp
class Solution{
public:
    vector<int32_t> v(n+5, INT32_MAX);
    v[0] = 0;
    for (int32_t i = 1; i <= n; ++i){
        for(int32_t j = 1; j*j <= i; ++j){
            v[i] = min(v[i], v[i - j*j]+1);
        }
    }
    return v[n];
}
```
