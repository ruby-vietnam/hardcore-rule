# 1512. Number of Good Pairs

### Bruteforce
We use two pointers `i` and `j` (with ` i < j < n`), with each `i` we check all value of `j` and increase the `count` for each time `arr[j] == arr[j]`

```java
class Solution {
    public int numIdenticalPairs(int[] nums) {
        int count = 0;
        for (int i = 0; i < nums.length - 1; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] == nums[j]) {
                    count++;
                }
            }
        }
        
        return count;
    }
}
```

- Time complexity: O(n^2)
- Space complexity: O(1)

### Hashmap

We use a `HashMap<Integer, Integer>` to save number of previous occuring before of a number.
If a `num` has already occurred before, we just increase the counting value.

```java
public int numIdenticalPairs(int[] nums) {
        HashMap<Integer, Integer> h = new HashMap<>();
        int count = 0;

        for (int num : nums) {
            int val = h.getOrDefault(num, 0);
            if (val == 0) {
                h.put(num, 1);
            } else {
                count += val;
                h.put(num, val + 1);
            }
        }

        return count;
    }
}
```

- Time complexity: O(n)
- Space complexity: O(n)

### Submission detail

> Runtime: 1 ms, faster than 69.23% of Java online submissions for Number of Good Pairs.
> Memory Usage: 38.5 MB, less than 6.37% of Java online submissions for Number of Good Pairs.

# 1043. Partition Array for Maximum Sum

### DP

We examine the base simplest key, when the length of `arr` is equal to `k`
ie, `[2, 5, 10]`
We can have an obviously maxium value is `arr.max * arr.length`.

Now, let examine the case when `arr`'s length is 1 greater than `k`.
ie, `[9, 2, 5, 10]`
We have `k` possible cases when spliting the `arr`:

- `[9] + [2, 5, 10]`, and the max is 39.
- `[9, 2] + [5, 10]`, and the max is 38.
- `[9, 2, 5] + [10]`, and the max is 37.

So, we can see the DP pattern hear.

### Submission
```java
class Solution {
    public int maxSumAfterPartitioning(int[] arr, int k) {
        int n = arr.length;
        int[] dp = new int[n];

        int max = Integer.MIN_VALUE;
        for (int i = 0; i < k; i++) {
            if (arr[n-1-i] > max) {
                max = arr[n-1-i];
            }
            dp[n-1-i] = max * (i+1);
        }

        for (int i = n-k-1; i >=0; i--) {
            max = arr[i];
            int m1 = Integer.MIN_VALUE;
            for (int j = 0; j < k; j++) {
                if (arr[i+j] > max) {
                    max = arr[i+j];
                }
                int temp = max*(j+1) + dp[i+j+1];
                if (temp > m1) {
                    m1 = temp;
                }
            }
            dp[i] = m1;
        }

        return dp[0];
    }
}
```

### Submission detail

> 52 / 52 test cases passed.
> Runtime: 2 ms

### Analysing
- Time complexity: O(nk)
- Space complexity: O(1)
