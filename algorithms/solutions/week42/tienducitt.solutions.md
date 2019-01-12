# Problem 1: 
https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

// This array is sorted, so dont need to use HashMap, just use 2 indexes
# Solution:
```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int i = 0, j = numbers.length - 1;
        
        while(i < j && numbers[i] + numbers[j] != target) {
            if (numbers[i] + numbers[j] > target) {
                j--;
            } else {
                i++;
            }
        }
        
        return new int[] {i+1, j+1};
    }
}
```

# Problem 2:
https://leetcode.com/problems/merge-intervals/submissions/

```java
class Solution {
    public List<Interval> merge(List<Interval> intervals) {
        List<Interval> res = new ArrayList<>();
        if(intervals.isEmpty()){
            return res;
        }

        Collections.sort(intervals, (a, b) -> a.start - b.start);
        
        res.add(intervals.get(0));
        int n = intervals.size(), r = 0;
        for(int i = 1; i < n; i++){
            Interval last = res.get(r);
            Interval candidate = intervals.get(i);
            if(last.end >= candidate.start){
                last.end = Math.max(candidate.end, last.end);
            }else {
                res.add(candidate);
                r++;
            }
        }
        return res;
    }
}
```