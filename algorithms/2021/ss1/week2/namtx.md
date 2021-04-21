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
