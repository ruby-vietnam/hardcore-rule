# Problem 1

Here we need to check there are non-overlapping occurences of

the string "BA" and "AB"

```cpp
#include <bits/stdc++.h>

using namespace std;

//  ***** MAIN *****
int main(){
    string s; cin >> s;

    int ab_first = -1 , ba_first = -1;
    int ab_last = -1, ba_last = -1;

    for(int i =0; i < s.length() -1; i++){
        if(s[i] == 'A' && s[i+1] == 'B'){
            if(ab_first == -1 ) ab_first = i;
            ab_last = i;
        }
        else if (s[i] == 'B' && s[i+1] == 'A'){
            if (ba_first == -1) ba_first = i;
            ba_last = i;
        }
    }

    if (ba_first ==-1 || ab_first == -1){}
    else if(ba_last - ab_first > 1 || ab_last - ba_first > 1){
      cout << "YES" << endl;
      return 0;
    }
    cout << "NO" << endl;
    return 0;
}
```

# Problem 2

Here we take notice that tree datastructure are recursive. The longest path
can either reside entirely on the left subtree, the right subtree, or it can be
a path that cross over the root node


```cpp


