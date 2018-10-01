# problem 1
```cpp
bool isPowerOfThree(int n){
    int x = floor(log(n)/ log(3));
    int a =  1;
    for(int i = 0 ; i < x; ++ i){
        a *= 3;
    }
    return a == n;
}
```
