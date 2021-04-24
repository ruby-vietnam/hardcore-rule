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

## Max Heap

We can optimize the naive approaching by reduce the sorting time complexity. The data structure we can use is a `MaxHeap`, everytime we remove two weightest stones, we can maintain the `MaxHeap` just by **O(log n)** time complexity. 

### Max Heap implementation

As this problem doesn't focus on `MaxHeap` so, we can implement it with 3 main methods: `insert` and `removeMax` and `heapify` 

- `insert` - inserts a new stone to `MaxHeap` - **O(log n)**
- `removeMax` - removes the largest stones from `MaxHeap` and resolve all violations on it. - **O(log n)**
- `heapify` - resolves all violations on `MaxHeap` - **O(log n)**

```java
class MaxHeap {
    List<Integer> harr;

    int heapSize;
    
    MaxHeap() {
        harr = new ArrayList<>();
        heapSize = 0;
    }

    public void insert(int k) {
        harr.add(heapSize, k);
        int i = heapSize;
        heapSize++;

        while(i != 0 && harr.get(i) > harr.get(parent(i))) {
            int tmp = harr.get(i);
            harr.set(i, harr.get(parent(i)));
            harr.set(parent(i), tmp);
            i = parent(i);
        }
    }

    public int removeMax() {
        int val = harr.get(0);

        if (heapSize == 1) {
            heapSize--;
            harr.remove(0);
            return val;
        }

        harr.set(0, harr.get(heapSize-1));
        heapSize--;
        harr.remove(heapSize);
        heapify(0);

        return val;
    }

    public void heapify(int i) {
        if (heapSize <= 1) return;
        int left = i*2+1;
        int right = i*2+2;
        int largest = i;

        if (left < heapSize && harr.get(largest) < harr.get(left)) largest = left;

        if (right < heapSize && harr.get(largest) < harr.get(right)) largest = right;

        if (largest != i) {
            int tmp = harr.get(largest);
            harr.set(largest, harr.get(i));
            harr.set(i, tmp);

            heapify(largest);
        }
    }

    public static int parent(int i) {
        return (i-1)/2;
    }

    public List<Integer> getHarr() {
       return harr; 
    }

    public int getHeapSize() {
        return heapSize;
    }

}
```

### Submission 

With the above implemented `MaxHeap` we can easily solve this problem as: 

```java
class Solution {
    public int lastStoneWeight(int[] stones) {
        int n = stones.length;
        if (n == 1) return stones[0];

        MaxHeap heap = new MaxHeap();

        for (int stone: stones){
            heap.insert(stone);
        }

        while (heap.getHeapSize() > 1) {
            int largest = heap.removeMax();
            int secondLargest = heap.removeMax();

            if (largest == secondLargest) {
                // Does not add anything to the heap
            } else {
                int result = Math.abs(largest - secondLargest);
                heap.insert(result);
            } 
        }

        return heap.getHeapSize() == 0 ? 0 : heap.getHarr().get(0);
    }
}
```

There is an edge case that after removing 2 largest stones, we have an empty heap, so everything we need is return 0.

### Submission detail

| Status    | Runtime     | Memory   | Language  |
| ---       | ----------- | -------- | --------- |
| Accepted  | 1ms         | 36.3MB   | java      |

### Analyze

- Time Complexity **O(n log n )**
- Space Compexity **O(n)**

## Another approach

This approach is kind of tricky, as we can notice that the stone weight: `1 <= stones[i] <= 1000`
We can present all stone weight in an array `weights`, `weights[i]` is the number of stones which has `i` weight.
So we can easily get the 2 most weightest stones by go backward, smash them together and add one more stone `weights[largest-secondLargest]++`

There is one special case, when the number of stones with the same weight is even, we can treat it as `0` as after smashing, there is nothing remain.

### Submission

```java
class Solution {
    public int lastStoneWeight(int[] stones) {
        int[] arr = new int[1001];
        Arrays.fill(arr, 0);
        for (int stone: stones) {
            arr[stone]++;
        }

        int right = 1000;
        int left;

        while (right >= 1) {
            if (arr[right] % 2 != 0) {
                left = right - 1;
                
                while (left >= 1 && arr[left] == 0) left--;
                
                if (left == 0) break;
                
                arr[right - left]++;
                arr[left]--;
            }
            
            right--;
        }

        return right;
    }
}
```

### Submission detail

| Status    | Runtime     | Memory   | Language  |
| ---       | ----------- | -------- | --------- |
| Accepted  | 1ms         | 36.4MB   | java      |

### Analyze

- Time Complexity **O(n ^ 2)**
- Space Compexity **O(n)**

# 719. Find K-th Smallest Pair Distance

## Approach

First of all, we sort the array for easily couting, it takes **O(n log n)** Time complexity and **O(n)** Space complexity.

We have a conclusion as the minimum distance is 0 and the maximum is `nums[N] - nums[0]`.

We're gonna use binary searching.
- the `mid` value is `min + (max - min)/2`
- we use two pointer `left` and `right` and then we count the number of pairs which are greater than the `mid` by sliding the `left` and `right` pointer
- if the number of pairs is greater than `k` so, we find a new `mid` value by reassign the `max` value to `(mid - 1)`, otherwise, the new min value is `(mid + 1)`
- And so on, the loop is end whenever the binary searching is done (`min > max`)

## Submission

```java
import java.util.Arrays;

public class Solution {
    public int smallestDistancePair(int[] nums, int k) {
        Arrays.sort(nums);
        int n = nums.length;

        int max = nums[n - 1] - nums[0];
        int min = 0;

        while (min <= max) {
            int mid = min + (max - min) / 2;

            int left = 0;
            int right = 0;
            int count = 0;

            while (right < n) {
                if (nums[right] - nums[left] > mid) {
                    left++;
                } else {
                    int pairs = right - left;
                    count += pairs;
                    right++;
                }
            }

            if (count >= k) {
                max = mid - 1;
            } else {
                min = mid + 1;
            }
        }

        return min;
    }
}
```

## Submission detail

| Status    | Runtime     | Memory   | Language  |
| ---       | ----------- | -------- | --------- |
| Accepted  | 3 ms        | 38.7MB   | java      |

## Complexity

Time complexity: **O(n log n)**
Space complexity **O(n)**
