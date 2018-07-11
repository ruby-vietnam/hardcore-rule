# Problem 1
```cpp

#include <bits/stdc++.h>

using namespace std;


// Complete the miniMaxSum function below.
void miniMaxSum(vector<int> arr) {
    auto sum = 0;
    vector<int64_t> a;
    for(int i : arr ){
        a.push_back((int64_t)i);
    }

    if ( a[0] + a[1] + a[2] + a[3] < a[0] + a[1] + a[2] + a[4] ){
        if( a[0] + a[1] + a[2] + a[3] < a[0] + a[1] + a[3] + a[4] ){
            if ( a[0] + a[1] + a[2] + a[3] < a[0] + a[2] + a[3] + a[4] ){
                if ( a[0] + a[1] + a[2] + a[3] < a[1] + a[2] + a[3] + a[4] ){
                    cout << a[0] + a[1] + a[2] + a[3] << " ";
                }
                else {
                    cout << a[1] + a[2] + a[3] + a[4] << " ";
                }
            }
            else {
                if( a[0] + a[2] + a[3] + a[4] < a[1] + a[2] + a[3] + a[4] ){
                    cout << a[0] + a[2] + a[3] + a[4] << " ";
                }
                else {
                    cout << a[1] + a[2] + a[3] + a[4] << " ";
                }
            }
        }
        else {
            if ( a[0] + a[1] + a[3] + a[4] < a[0] + a[2] + a[3] + a[4] ){
                 if( a[0] + a[1] + a[3] + a[4] < a[1] + a[2] + a[3] + a[4] ){
                     cout << a[0] + a[1] + a[3] + a[4] << " ";
                 }
                 else{
                     cout << a[1] + a[2] + a[3] + a[4] << " ";
                 }
            }
            else{
                if ( a[0] + a[2] + a[3] + a[4] < a[1] + a[2] + a[3] + a[4] ){
                    cout << a[0] + a[2] + a[3] + a[4] << " ";
                }
                else {
                    cout << a[1] + a[2] + a[3] + a[4] << " ";
                }
            }
        }
    }
    else {
        if ( a[0] + a[1] + a[2] + a[4] < a[0] + a[1] + a[3] + a[4] ){
            if ( a[0] + a[1] + a[2] + a[4] < a[0] + a[2] + a[3] + a[4] ){
                if ( a[0] + a[1] + a[2] + a[4] < a[1] + a[2] + a[3] + a[4] ){
                    cout << a[0] + a[1] + a[2] + a[4] << " ";
                }
                else {
                    cout << a[1] + a[2] + a[3] + a[4] << " ";
                }
            }
            else {
                if ( a[0] + a[2] + a[3] + a[4] < a[1] + a[2] + a[3] + a[4] ){
                    cout << a[0] + a[2] + a[3] + a[4] << " ";
                }
                else {
                    cout << a[1] + a[2] + a[3] + a[4] << " ";
                }
            }
        }
        else {
            if ( a[0] + a[1] + a[3] + a[4] < a[0] + a[2] + a[3] + a[4] ){
                if ( a[0] + a[1] + a[3] + a[4] < a[1] + a[2] + a[3] + a[4] ){
                    cout << a[0] + a[1] + a[3] + a[4] << " ";
                }
                else {
                    cout << a[1] + a[2] + a[3] + a[4] << " ";
                }
            }
            else {
                if ( a[0] + a[2] + a[3] + a[4] < a[1] + a[2] + a[3] + a[4] ){
                    cout << a[0] + a[2] + a[3] + a[4] << " ";
                }
                else {
                    cout << a[1] + a[2] + a[3] + a[4] << " ";
                }
            }
        }
    }

    if ( a[0] + a[1] + a[2] + a[3] > a[0] + a[1] + a[2] + a[4] ){
        if( a[0] + a[1] + a[2] + a[3] > a[0] + a[1] + a[3] + a[4] ){
            if ( a[0] + a[1] + a[2] + a[3] > a[0] + a[2] + a[3] + a[4] ){
                if ( a[0] + a[1] + a[2] + a[3] > a[1] + a[2] + a[3] + a[4] ){
                    cout << a[0] + a[1] + a[2] + a[3] << endl;
                }
                else {
                    cout << a[1] + a[2] + a[3] + a[4] << endl;
                }
            }
            else {
                if( a[0] + a[2] + a[3] + a[4] > a[1] + a[2] + a[3] + a[4] ){
                    cout << a[0] + a[2] + a[3] + a[4] << endl;
                }
                else {
                    cout << a[1] + a[2] + a[3] + a[4] << endl;
                }
            }
        }
        else {
            if ( a[0] + a[1] + a[3] + a[4] > a[0] + a[2] + a[3] + a[4] ){
                 if( a[0] + a[1] + a[3] + a[4] > a[1] + a[2] + a[3] + a[4] ){
                     cout << a[0] + a[1] + a[3] + a[4] << endl;
                 }
                 else{
                     cout << a[1] + a[2] + a[3] + a[4] << endl;
                 }
            }
            else{
                if ( a[0] + a[2] + a[3] + a[4] > a[1] + a[2] + a[3] + a[4] ){
                    cout << a[0] + a[2] + a[3] + a[4] << endl;
                }
                else {
                    cout << a[1] + a[2] + a[3] + a[4] << endl;
                }
            }
        }
    }
    else {
        if ( a[0] + a[1] + a[2] + a[4] > a[0] + a[1] + a[3] + a[4] ){
            if ( a[0] + a[1] + a[2] + a[4] > a[0] + a[2] + a[3] + a[4] ){
                if ( a[0] + a[1] + a[2] + a[4] > a[1] + a[2] + a[3] + a[4] ){
                    cout << a[0] + a[1] + a[2] + a[4] << endl;
                }
                else {
                    cout << a[1] + a[2] + a[3] + a[4] << endl;
                }
            }
            else {
                if ( a[0] + a[2] + a[3] + a[4] > a[1] + a[2] + a[3] + a[4] ){
                    cout << a[0] + a[2] + a[3] + a[4] << endl;
                }
                else {
                    cout << a[1] + a[2] + a[3] + a[4] << endl;
                }
            }
        }
        else {
            if ( a[0] + a[1] + a[3] + a[4] > a[0] + a[2] + a[3] + a[4] ){
                if ( a[0] + a[1] + a[3] + a[4] > a[1] + a[2] + a[3] + a[4] ){
                    cout << a[0] + a[1] + a[3] + a[4] << endl;
                }
                else {
                    cout << a[1] + a[2] + a[3] + a[4] << endl;
                }
            }
            else {
                if ( a[0] + a[2] + a[3] + a[4] > a[1] + a[2] + a[3] + a[4] ){
                    cout << a[0] + a[2] + a[3] + a[4] << endl;
                }
                else {
                    cout << a[1] + a[2] + a[3] + a[4] << endl;
                }
            }
        }
    }

}
```

