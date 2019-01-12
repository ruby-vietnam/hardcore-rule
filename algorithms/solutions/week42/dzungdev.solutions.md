Problem2: https://leetcode.com/problems/merge-intervals/

We can sort the interval by the start time first, then each time we loop through one interval, we can check with the lastest interval in the result list. If it is overlapsed interval, so we just merge the interval, if not, then we just add to result.

Time complexity is: O(nlogn)
Space Complexity: O(n)
```java
private boolean isOverlapsed(Interval i1, Interval i2) {
        return (i2.start >= i1.start && i2.start <= i1.end) ||
                    (i2.end >= i1.start && i2.end <= i1.end) ||
                    (i1.start >= i2.start && i1.start < i2.end) ||
                    (i1.end >= i1.start && i1.end <= i2.end);
    }
    
    public List<Interval> merge(List<Interval> intervals) {
        if (intervals.size() == 0) return new ArrayList<Interval>();
        if (intervals.size() == 1) return intervals;
        
        Comparator<Interval> comp = (i1, i2) -> i1.start - i2.start;
        Collections.sort(intervals, comp);
        List<Interval> results = new ArrayList();
        results.add(intervals.get(0));
        for (int i = 1; i < intervals.size(); i++) {
            Interval lastInterval = results.get(results.size() -1);
            if (isOverlapsed(intervals.get(i), lastInterval)) {
                lastInterval.start = Math.min(lastInterval.start, intervals.get(i).start);
                lastInterval.end = Math.max(lastInterval.end, intervals.get(i).end);
            } else {
                results.add(intervals.get(i));
            }
        }
        return results;
    }
```
