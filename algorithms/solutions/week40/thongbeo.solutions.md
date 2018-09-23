#Problem 1
``` Java 
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        for(int i = m ; i < m+ n; i++){
            nums1[i] = nums2[i-m];
        }
        Arrays.sort(nums1);
    }
```

#Problem 2
```Java
class Solution {
    public int numSquares(int n) {
        int[] results = new int[n +1];
        results[0]= 0; 
        
        for (int i = 1; i < n + 1 ; i++){
            int min = Integer.MAX_VALUE;
             for (int j=1; j*j<=i; j++) {
                min = Math.min(min, results[i-j*j]+1);
            }
            results[i] = min;
        }
        
        return results[n];
    }
}
```
