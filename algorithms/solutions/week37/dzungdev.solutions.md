Problem1: https://leetcode.com/problems/find-k-closest-elements/description/

```java
public List<Integer> findClosestElements(int[] a, int k, int x) {
    final List<Integer> arr = Arrays.stream(a).boxed().collect(Collectors.toList());
    final int n = arr.size();
    if (x <= arr.get(0)) {
      return arr.subList(0, k);
    } else if (x >= arr.get(n - 1)) {
      return arr.subList(n - k, n);
    } else {
      int index = Collections.binarySearch(arr, x);
      if (index < 0) {
        index = -index - 1;
      }
      int low = Math.max(0, index - k);
      int high = Math.min(n - 1, index + k - 1);
      while (high - low + 1 > k) {
        if (x - arr.get(low) <= arr.get(high) - x) {
          high--;
        } else {
          low++;
        }
      }
      return arr.subList(low, high + 1);
    }
  }
```
