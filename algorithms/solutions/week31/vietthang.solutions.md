# Problem 1

```cpp
#include <iostream>
#include <cstring>

using namespace std;

int main() {  
  string str;
  bool ab, ba;
  ab = ba = 0;
  cin >> str;

  for (int i = 0; i < str.size(); i++) {    
    if (!ab && str[i] == 'A' && (i+1) < str.size() && str[i+1] == 'B') {
      ab = 1;
      for (int j = i + 2; j < str.size(); j++) {
        if (str[j] == 'B' && (j + 1) < str.size() && str[j+1] == 'A') {
          cout << "YES";
          return 0;
        }
      }
    }

    if (!ba && str[i] == 'B' && (i+1) < str.size() && str[i+1] == 'A') {
      ba = 1;
      for (int j = i + 2; j < str.size(); j++) {
        if (str[j] == 'A' && (j + 1) < str.size() && str[j+1] == 'B') {
          cout << "YES";
          return 0;
        }
      }
    }
  }

  cout << "NO";
  return 0;
}
```
