##problem 3

```cpp
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

const int maxN = 1e3;

int main(){
    priority_queue<int> heap;	
    int a[maxN], b[maxN];
    int n, k1, k2, tmp;	
    long long ans;
    
    cin >> n >> k1 >> k2;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
   
    for (int i = 0; i < n; ++i) heap.push(abs(a[i]-b[i]));
    
    k1 += k2;
    while (k1--){
        tmp = abs(heap.top()-1);
        heap.pop();
        heap.push(tmp);
    }
    
    ans = 0;
    for (int i = 0; i < n; ++i){
        tmp = heap.top();
        ans += (long long) tmp * tmp;
        heap.pop();
    }
    
    cout << ans << endl;
    
    return 0;
}
```
