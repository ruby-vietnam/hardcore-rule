# Proplem 1:
https://leetcode.com/problems/power-of-three/description/
```java
public boolean isPowerOfThree(int n) {
    if (n < 1) {
        return false;
    }

    while (n % 3 == 0) {
        n /= 3;
    }

    return n == 1;
}
```

# Problem 2: 
https://leetcode.com/problems/find-k-closest-elements/description/

```java
public List<Integer> findClosestElements(int[] arr, int k, int x) {
    List<Integer> list = new ArrayList<>();
    for (int i : arr) {
        list.add(i);
    }

    list.sort(Comparator.comparingInt(i -> Math.abs((int)i - x)));
    
    List<Integer> result = list.subList(0, k);
    result.sort(Comparator.comparingInt(i -> i));
    return result;
}
```

# Problem 3:
