## Problem 1

```c++
#include <iostream>

int main() {
    long long int a[5], sum = 0;

    for (int i = 0; i < 5; ++i) {
        std::cin >> a[i];
        sum += a[i];
    }

    long long int minSum = 6000000000, maxSum = 0;

    for (int i = 0; i < 5; ++i) {
        if (minSum > sum - a[i]) minSum = sum - a[i];
        if (maxSum < sum - a[i]) maxSum = sum - a[i];
    }

    std::cout << minSum << " " << maxSum;
    
    return 0;
}
```

## Problem 2

```c++
#include <iostream>
#include <string>
#include <map>
#include <iterator>

using namespace std;

int main() {
    int n, m;
    map <string, int> a;
    string str;
    map <string, int> :: iterator it;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> str;
        if ((it = a.find(str)) != a.end()) {
            it->second += 1;
        } else {
            a.insert(pair <string, int> (str, 1));
        }
    }

    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> str;
        cout << (((it = a.find(str)) != a.end()) ? it->second : 0) << "\n";
    }

    return 0;
}
```
