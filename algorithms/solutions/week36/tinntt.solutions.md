## Problem 1: [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/description/)

 ```java
class Solution {
        int climbStairs(int n) {
            if (n == 1) {
                return 1;
            }
            int numOfStep = 0;
            int maxNumOfTwoSteps = n / 2;
            for (int numOfTwoSteps = 0; numOfTwoSteps <= maxNumOfTwoSteps; numOfTwoSteps++) {
                numOfStep += combinations(n - numOfTwoSteps, numOfTwoSteps);
            }
            return numOfStep;
        }

        public long combinations(int n, int k) {
            BigInteger factorialN = factorial(n);
            BigInteger factorialK = factorial(k);
            BigInteger factorialNMinusK = factorial(n - k);
            return factorialN.divide(factorialK.multiply(factorialNMinusK)).longValue();
        }

        private BigInteger factorial(int n) {
            BigInteger ret = BigInteger.ONE;
            for (int i = 1; i <= n; ++i) ret = ret.multiply(BigInteger.valueOf(i));
            return ret;
        }

    }
```