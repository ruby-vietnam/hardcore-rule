# Bai 1:

```
void miniMaxSum(vector<int> arr) {
   int min = MIN_INT , max = MAX_INT, sum = 0;
    for(auto x :arr)
   {
       if( x < min) min = x;
        if(x > max ) max = x;
        sum += x;
   }
    
    std::cout << sum - max << " " << sum - min;

}
```
