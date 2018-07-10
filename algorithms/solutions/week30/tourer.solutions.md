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
