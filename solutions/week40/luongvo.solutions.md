# Week 40

# Problem 1 

```java
class Solution {
    public void merge(int A[], int m, int B[], int n) {
        int i=m-1, j=n-1, k=m+n-1;
        while (i>-1 && j>-1) A[k--]= (A[i]>B[j]) ? A[i--] : B[j--];
        while (j>-1)         A[k--]=B[j--];
    }
}
```

> Submission Detail
59 / 59 test cases passed.
Status: Accepted
Runtime: 4 ms
Submitted: 2 minutes ago

