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
