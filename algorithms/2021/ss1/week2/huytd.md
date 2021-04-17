# Easy: Last Stone Weight

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
