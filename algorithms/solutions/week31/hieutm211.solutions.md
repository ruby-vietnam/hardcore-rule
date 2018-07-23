##Problem 1

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    bool findAB, findBA;
    findAB = findBA = 1;
    cin >> s;
    
    if (s.size() >= 4)
    for(int i = 0; i < s.size()-3; ++i){
        if (findBA && s[i] == 'A' && s[i+1] == 'B'){
            for (int j = i+2; j < s.size()-1; ++j)
                if (s[j] == 'B' && s[j+1] == 'A'){
                    cout << "YES";
                    return 0;
                }
            findBA = 0;
        }
        if (findAB && s[i] == 'B' && s[i+1] == 'A'){
            for (int j = i+2; j < s.size()-1; ++j)
                if (s[j] == 'A' && s[j+1] == 'B'){
                    cout << "YES";
                    return 0;
                }
            findAB = 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
```
