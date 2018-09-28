# Problem 1

## [Reverse Integer](https://leetcode.com/problems/reverse-integer/description/)
```java
class Solution {
    public int reverse(int x) {
        int sign = x < 0 ? -1 : 1;
        String s = Long.toString(x);
        if(sign == -1) {
            s = s.substring(1, s.length());
        }
        long result =  Long.parseLong(new StringBuilder(s).reverse().toString());
        if(result > Integer.MAX_VALUE) {
            return 0;
        }
        return (int)result * sign;
    }
}
```

# Problem 3

## [Continuous Subarray Sum](https://leetcode.com/problems/continuous-subarray-sum/description/)
```java
class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        for(int i = 1; i < nums.length; i++) {
            long sum = nums[i];
            for(int j = i-1; j >= 0; j--) {
                sum += nums[j];
                if((sum == 0 && k == 0) || (k != 0 && sum % k == 0)) {
                    return true;
                }
            }
        }
        return false;
    }
}
```
