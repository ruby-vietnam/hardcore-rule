#Problem 1
``` Java
class Solution {
    public int hammingDistance(int x, int y) {
        int xor = x^y;
        int distance = 0;
        while (xor > 0){
            if ((xor & 1) == 1){
                distance++;
            } 
            xor = xor >> 1;
        }
        return distance;
    }
}
```
