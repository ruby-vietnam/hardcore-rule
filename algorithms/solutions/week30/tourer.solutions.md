# Problem 1

## [Mini-Max Sum](https://www.hackerrank.com/challenges/mini-max-sum/problem)
```java
static void miniMaxSum(int[] arr) {
    Arrays.sort(arr);
    long min = 0;
    long max = 0;
    for(int i = 0; i < 4; i++) {
        min += arr[i];
        max += arr[arr.length-1-i];
    }
    System.out.println(min + " " + max);
}
```
## [Sparse Arrays](https://www.hackerrank.com/challenges/sparse-arrays/problem)
```java
static int[] matchingStrings(String[] strings, String[] queries) {
    Map<String, Integer> map = new HashMap<>();
    for(int i = 0; i < strings.length; i++) {
        int count = 0;
        if(map.containsKey(strings[i])) {
            count = map.get(strings[i]);
        }
        map.put(strings[i], count + 1);
    }
    int[] res = new int[queries.length];
    for(int i = 0; i < queries.length; i++) {
        res[i] = Optional.ofNullable(map.get(queries[i])).orElse(0);
    }
    return res;
}
```
