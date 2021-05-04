# Easy: Last Stone Weight

There are two solutions here, the first is a naive `O(n^2 log n)` one, and the next one uses a max heap, which is `O(n log n)`.

## O(N^2 log N) solution

Submission detail:
```
70 / 70 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 2 MB
```

Since this is the easy one, there's no need to think too much. The process is simple, first, we sort the array, and then pick up the first two stones to smash, get the result and put it back to the array.

The algorithm:

- While the array still have at least two elements:
  + Sort the array in descending order
  + Pickup the first two elements
  + Smash them together and get the result
  + Push the result back to the array
- At this step, there will be two cases:
  + The array is empty, return 0
  + There's one element in the array, return that element

Implementation:

```go
func lastStoneWeight(n []int) int {
    for len(n) > 1 {
        sort.Slice(n, func(i, j int) bool {
            return n[i] > n[j]
        })
        smash := n[:2]
        n = n[2:]
        r := smash[0] - smash[1]
        if r > 0 {
            n = append(n, r)
        }
    }
    if len(n) > 0 {
        return n[0]
    } else {
        return 0
    }
}
```

Analysis:

The sort method takes `O(n log n)` time, and during the algorithm, we're trying to pick two element out, insert one back, so it's basically repeated `N` times. That mean the runtime for this algorithm would be `O( n^2 log n)`.

All operations in this algorithm are modified the original input data, there's no new data structure allocated at any step, so the space complexity is `O(1)`.

## O(N log N) solution

Submission detail:
```
70 / 70 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 7.7 MB
```

We can optimize the algorithm by decrease its runtime. The operation that cost most in the naive algorithm is the sort, which takes `O(n log n)` time, and repeated at most `N` times. To avoid the need of sorting, we should use some data structure that can maintain the order by just insert or remove. That's something a Heap or a Prioity Queue can do.

The algorithm:

- Build a priority queue from the input array
- While the heap is not empty:
  + Take the max two elements
  + Smash them together and put the result back
- Eventually, take out the result and print

Implementation:

```cpp
class Solution {
    public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (int i : stones) {
            pq.push(i);
        }
        while (pq.size() > 1) {
            int x = pq.top(); pq.pop(); 
            int y = pq.top(); pq.pop(); 
            int re = x - y;
            if (re > 0) {
                pq.push(re);
            }
        }
        return pq.size() ? pq.top() : 0;
    }
};
```

Analysis:

The first step is to push every elements of the input array into a priority queue, which takes `O(n log n)` time. The main `while` loop takes `n` times as explained in the previous solution. All priority queue's operations in the main loop are `O(log n)` time, except the `pq.top()` is just `O(1)`. Combine them all we have the total time complexity is `O(n log n) + n * (2 * (O(1) + O(log n)) + O(log n) + O(1))`, well, eventually it's just `O(n log n)`.

This algorithm created a priority queue to store every elements of the input array in it, so it would be `O(n)` space.

# Hard: Find K-th Smallest Pair Distance

Submission details:
```
19 / 19 test cases passed.
Status: Accepted
Runtime: 3548 ms
Memory Usage: 3.5 MB
```

```go
func smallestDistancePair(n []int, k int) int {
    sort.Ints(n)
    l := len(n)
    low := 0
    high := 1000000
    for low < high {
        mid := (high + low) / 2
        fk := 0
        for i := 0; i < l; i++ {
            j := 0
            for j < l && n[j] - n[i] <= mid {
                j++
            }
            fk += j - i - 1
        }
        if fk < k {
            low = mid + 1
        } else {
            high = mid
        }
    }
    return low
}
```
