Problem 1: Degree of an Array

URL: https://leetcode.com/problems/degree-of-an-array/description/

Status:
```
89 / 89 test cases passed.
Status: Accepted
Runtime: 156 ms
```

<details>
Time Complexity: O(nlogn)
Space: O(n)

We will find the position of the first number of degree and position of last time the degree number appear. Then we can use formula: distance = right - left + 1 (Because it is contigous array).
I am using sorted map and I think the time to sort reverse the map is O(nlogn) then I just get the first  one is Max.

```java
public int findShortestSubArray(int[] nums) {
    Map<Integer, Integer> left = new HashMap<Integer, Integer>(),
        right = new HashMap<>(), count = new HashMap<>();
    
    for (int i = 0; i < nums.length;i++) {
      if (!left.containsKey(nums[i])) left.put(nums[i], i);
      right.put(nums[i], i);
      count.put(nums[i], count.containsKey(nums[i]) ? count.get(nums[i]) + 1 : 1);
    }
    
    Map<Integer, Integer> sortedCountMap = count.entrySet().stream()
                                                .sorted(Map.Entry.comparingByValue(Comparator.reverseOrder()))
                                                .collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue,
                                                        (oldValue, newValue) -> oldValue, LinkedHashMap::new));
    
    Integer degreeNum = sortedCountMap.values().iterator().next();
    int shortestSubArray = nums.length;
    for (Integer num: sortedCountMap.keySet()) {
      if (sortedCountMap.get(num) < degreeNum) {
        break;
      } else {
        int newSetLength = right.get(num) - left.get(num) + 1;
        shortestSubArray = shortestSubArray >= newSetLength ? newSetLength : shortestSubArray;
      }
    }

    return shortestSubArray;
  }
```
</details>
