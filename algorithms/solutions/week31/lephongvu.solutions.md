Bai 1
```
#include <vector>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std; //Back to the 90s

int main () {

    string s;
    cin >> s;
    int siz = s.size();
    for(int i = 0; i < siz - 1; i++){
        if(s[i] == 'A' && s[i + 1] == 'B'){
            i += 2;
            for(int j = i; j < siz; j++){
                if(s[j] == 'B' && s[j + 1] == 'A'){
                    cout << "YES";
                    return 0;
                }
            }
            i = siz;
        }
    }
    for(int i = 0; i < siz - 1; i++){
        if(s[i] == 'B' && s[i + 1] == 'A'){
            i += 2;
            for(int j = i; j < siz; j++){
                if(s[j] == 'A' && s[j + 1] == 'B'){
                    cout << "YES";
                    return 0;
                }
            }
            i = siz;
        }
    }
    cout << "NO";


}

```
