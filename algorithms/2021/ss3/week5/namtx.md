# 168. Excel Sheet Column Title

### Approach

We do exectly the same when we generate the Decimal number into Binary, but with 26 alphabets.

### Submission

```java
class Solution {
    public String convertToTitle(int columnNumber) {
        String s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        StringBuilder r = new StringBuilder();

        while (columnNumber > 0) {
            columnNumber--;
            int i = columnNumber % 26;
            r.insert(0, s.charAt(i));
            columnNumber /= 26;
        }

        return r.toString();
    }
}
```

### Submission detail

18 / 18 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 36.3 MB


### Analyze

- Time complexity: O(n)
- Space complexity: O(1)

# 70. Climbing Stairs

### Approach - DP

When n = 1, we have only one way to reach the top: 1
When n = 2, we have two ways: 1->1 or 2
When n = 3, we have three ways, 1->1->1, 1->2 or 2->1. So we have the overlapping here. dp[3] = dp[1] + dp[2].

### Submission

```java
class Solution {
    public int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        
        int[] dp = new int[n+1];
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i-2] + dp[i-1];
        }

        return dp[n];
    }
}
```

### Submission detail

45 / 45 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 35.8 MB

### Analyze

- Space complexity: O(n)
- Time complexity: O(n)

# 198. House Robber 

### Approach - DP

When n = 1, we have only one choice.
When n = 2, since we can rob only one house, we will choose the house with the bigger value.
When n = 3, we have two choices:
- Rob the first house and the third house
- Rob only the second house

We we choose the right way to get the biggest value.
So, `dp[3] = max(nums[3] + dp[1], dp[2])`

### Submission

```java
class Solution {
    public int rob(int[] nums) {
        int[] dp = new int[nums.length];
        dp[0] = nums[0];
        
        if (nums.length == 1) {
            return dp[0];
        }
        
        dp[1] = max(nums[1], dp[0]);
        
        for (int i = 2; i < nums.length; i++) {
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        }
        
        return dp[nums.length-1];
    }
    
    public static int max(int a, int b) {
        return a > b ? a : b;
    }
}
```

### Submission detail

68 / 68 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 36.4 MB

### Analyze

- Time complexity: O(n)
- Space complexity: O(n)

# 213. House Robber II

### Approach - DP

Since the last house is adjacent with the first house, we separate our choices into two group: `withFirstHouse` and `withoutFirstHouse`.

When n = 1, we just rob it.
When n = 2, we choose the maxium house between two house.

And with n > 2, we do exactly the same process with the above problem.

For the last house, in case we already robbed the first house, we can rob it anymore.

And finally, we check between two ways and pick the max value.

### Submission

```java
class Solution {
    public int rob(int[] nums) {
        int N = nums.length;
        if (N == 1)
            return nums[0];
        int[] withFirstHouse = new int[nums.length];
        int[] withoutFirstHouse = new int[nums.length];

        withFirstHouse[0] = nums[0];
        withoutFirstHouse[0] = 0;

        withFirstHouse[1] = nums[0];
        withoutFirstHouse[1] = nums[1];
        
        if (N == 2) {
            return Math.max(withFirstHouse[1], withoutFirstHouse[1]);
        }

        for (int i = 2; i < N-1; i++) {
            withFirstHouse[i] = Math.max(nums[i] + withFirstHouse[i-2], withFirstHouse[i-1]);
            withoutFirstHouse[i] = Math.max(nums[i] + withoutFirstHouse[i-2], withoutFirstHouse[i-1]);
        }
        
        int i = N-1;
        int with = Math.max(withFirstHouse[i-1], withFirstHouse[i-2]);
        int without = Math.max(withoutFirstHouse[i-1], nums[i] + withoutFirstHouse[i-2]);

        return Math.max(with, without);
    }
}
```

### Submission detail

74 / 74 test cases passed.
Status: Accepted
Runtime: 0 ms

### Analyze

- Space complexity: O(n)
- Time complexity: O(n)
