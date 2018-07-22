### Prolem 1
```cpp
#include <bits/stdc++.h>
using namespace std;

string s;
int ab, ba, aba;

int main() {
    cin >> s;
    for (int i = 0; i + 1 < s.size(); ++i) {
        if (i + 2 < s.size() && (s.substr(i, 3) == "ABA" || s.substr(i, 3) == "BAB")) {
            ++aba;
            i += 2;
        } else if (s.substr(i, 2) == "AB") {
            ++ab;
            ++i;
        } else if (s.substr(i, 2) == "BA") {
            ++ba;
            ++i;
        }
    }
    if ((ab > 0 && ba > 0) || aba > 1) return puts("YES");
    if (aba > 0 && (ab > 0 || ba > 0)) return puts("YES");
    puts("NO");
}
```
