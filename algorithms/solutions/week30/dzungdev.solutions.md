Problem1: https://www.hackerrank.com/challenges/mini-max-sum/problem

In order to do this, firstly we loop through the array to have the sum, then we loop through the array again and for each current element, we can have one remaining_sum = sum - currentVal, then compare that remaining_sum with min/max.

Time complexity is O(n)
Space complexity is O(1)

```java
// Complete the miniMaxSum function below.
    static void miniMaxSum(int[] arr) {
        long sum = 0;
        for (int num: arr) {
            sum += num;
        }
        long max = Long.MIN_VALUE;
        long min = Long.MAX_VALUE;
        for (int num: arr) {
            long remainingSum = sum - num;
            if (remainingSum > max) max = remainingSum;
            if (remainingSum < min) min = remainingSum; 
        }
        System.out.print(min + " " + max);
    }
```

Problem2: https://www.hackerrank.com/challenges/sparse-arrays/problem

In order to do this, we loop through the strings and create a Map which have key is string and value is frequent number of that strings.
Then we loop through the queries and get data from the Map

Time complexity is O(n)
Space complexity is O(n)

```java
// Complete the matchingStrings function below.
    static int[] matchingStrings(String[] strings, String[] queries) {
        Map<String, Integer> stringMap = new HashMap<>();
        for (String str: strings) {
            stringMap.put(str, stringMap.getOrDefault(str,0) + 1);
        }
        int[] results = new int[queries.length];
        int i = 0;
        for (String query: queries) {
            results[i++] = stringMap.getOrDefault(query, 0);
        }    
        return results;
    }
```
