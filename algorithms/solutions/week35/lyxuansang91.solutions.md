## [Problem 1 - K-based Numbers](http://acm.timus.ru/problem.aspx?space=1&num=1009)

Solution: using Dynamic Programming. Let f(i,j) shows the numbers of k-based numbers with i-digit and end at j( j equal to 0 or 1). 
- f(1, 1) = k - 1
- f(i, 0) = f(i - 1, 1)
- f(i, 1) = (f(i - 1, 1) + f(i - 1, 0)) * (k - 1)

The answer is f(n, 0) + f(n, 1)
Time complexity: O(N)

```cpp
#include <iostream>

using namespace std;
typedef long long ll;


ll calculate(const int &n, const int &k) {
    if(n == 1) return k;
    ll f[20][2]; /* dynamic programming f[i][j] = result at i-digit, and end is j (j = 0 or 1) */
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 2; j++)
            f[i][j] = 0;
    f[1][1] = k-1;
    for(int i = 2; i <= n; i++) {
        f[i][0] = f[i-1][1];
        f[i][1] = (f[i-1][1] + f[i-1][0]) * (k-1);
    }
    return f[n][1] + f[n][0];
}

int main() {
    int n,k;
    cin >> n >> k;
    cout << calculate(n, k) << endl;
    return 0;
}
```