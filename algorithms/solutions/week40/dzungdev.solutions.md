Problem1: https://leetcode.com/problems/merge-sorted-array/description/

```java
public void merge(int[] nums1, int m, int[] nums2, int n) {
    int i = m-1;
    int j = n-1;
    int k = m + n - 1;
    while (k >= 0) {
      if (i >= 0 && j >= 0) {
        if (nums1[i] < nums2[j]) {
            nums1[k] = nums2[j];
            j--;
          } else {
            nums1[k] = nums1[i];
            i--;
          }   
      } else if (i >= 0) {
          nums1[k] = nums1[i];
          i--;
      } else {
          nums1[k] = nums2[j];
          j--;
      }
      k--;
    }
  }
```
Problem2: https://leetcode.com/problems/perfect-squares/description/

```java
  public int numSquares(int n) {

    int[] dp = new int[n+1];
    dp[0] = 0;

    for (int i = 1; i <= n;i++) {
      int min = Integer.MAX_VALUE;
      int j = 1;
      while (i - j*j >= 0) {
        min = Math.min(min, dp[i - j *j] + 1);
        ++j;
      }
      dp[i] = min;
    }
    return dp[n];
  }
```
