# 1046. Last Stone Weight (Easy)

## Naive approach

The first idea comes through is if we ascendingly sort the array first. And while the array length is greater than 1, we easily pick two last one and smash them together, and put the result to new array.

### Submission

```java
class Solution {
    public int lastStoneWeight(int[] stones) {
        int n = stones.length;
        if (n == 1) return stones[0];

        Arrays.sort(stones);

        while (n > 1) {
            int[] tmp = new int[n-1];
            System.arraycopy(stones, 0, tmp, 0, n - 2);
            tmp[tmp.length-1] = Math.abs(stones[n-2] - stones[n-1]);
            stones = tmp;
            n = stones.length;
            Arrays.sort(stones);
        }

        return stones[0];
    }
}
```

### Submission detail

| Status    | Runtime     | Memory   | Language  |
| ---       | ----------- | -------- | --------- |
| Accepted  | 1ms         | 36.6MB   | java      |

### Analyze

- The Time Complexity is **O(n^2 log n)** as we have to sort the array which takes **O(n log n)** each time we smash two stones together and we have to do it N times.
- The Space Complexity is **O(n)** as we have to create a temporary array.
