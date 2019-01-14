# Problem 2
```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int l = 0;
        int r = numbers.length-1;
        int[] n = numbers;
        while (l < r) {
            if (n[l] + n[r] == target) {
                return new int[]{l+1, r+1}; // fuck 1 base index
            } else if (n[l] + n[r] > target) {
                r--;
            } else {
                l++;
            }
        }
        throw new RuntimeException("should not be here");
    }
}
```

# Problem 3

```java
class Solution {
    public int maximumSwap(int num) {
        int max = num;
        int im = -1;
        int jm = -1;
        int length = (int)(Math.log10(num)+1);        
        for (int i = 0; i < length; i++) {
            for (int j = i+1; j < length; j++) {
                int newMax = swap(i, j, num);
                if (newMax >= max) { 
                    max = newMax;
                    im = i;
                    jm = j;
                }
            }
        }
        return max;
    }
    
    int swap(int i, int j, int num) {
        int i10 = i == 0 ? 1 : (int)Math.pow(10, i);
        int j10 = j == 0 ? 1 : (int)Math.pow(10, j);
                
        int numi = (num / i10)%10;
        int numj = (num / j10)%10;


        num += (numi - numj) * (j10 - i10);
        return num;
    }
}
```
