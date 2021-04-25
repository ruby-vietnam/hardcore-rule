# Easy: Last Stone Weight

## O(N^2 log N) Naive solution

- Sort the array in descending order
- Pickup the first two elements
- Compare them and append to the array

**Analysis:**
- Time: The sort method takes `O(N log N)` with the worst case, then we pick two element out and append it to the result array. So the runtime for this solution would be `O(N ^ 2 log N)`.

- Space: If we solve this by Swift, because Swift prevent us to modified parameter array so if we use sort it will cost `O(N)` space, so the total space complexity is `O(N)`

## O(N log N) solution

To optimize the algorithm, we can use a max heap to pickup 2 first elements without sorting:

- Build the max heap from the input array.
- While the heap is not empty:
  - Pickup 2 first largest elements
  - Compare them and enqueue it.
- Return the remain element in max heap due to `At the end, there is at most 1 stone left.  Return the weight of this stone (or 0 if there are no stones left.)`

```swift
class Solution {
    func lastStoneWeight(_ stones: [Int]) -> Int {
        var maxHeap = Heap<Int>(array: [], priorityFunction: >)

        for stone in stones {
            maxHeap.enqueue(stone)
        }

        while maxHeap.count > 1 {
            guard let y = maxHeap.dequeue(),
                let x = maxHeap.dequeue() else { return 0 }

            if y > x {
                maxHeap.enqueue(y - x)
            }
        }

        return maxHeap.peek() ?? 0
    }
}

struct Heap<Element> {
    var array: [Element]

    let priorityFunction: (Element, Element) -> Bool

    var isEmpty: Bool {
        array.isEmpty
    }

    var count: Int {
        array.count
    }

    func peek() -> Element? {
        array.first
    }

    func isRoot(_ index: Int) -> Bool {
        index == 0
    }

    func leftChildIndex(of index: Int) -> Int {
        (2 * index) + 1
    }

    func rightChildIndex(of index: Int) -> Int {
        (2 * index) + 2
    }

    func parentIndex(of index: Int) -> Int {
        (index - 1) / 2
    }

    mutating func enqueue(_ element: Element) {
        array.append(element)
        siftUp(elementAtIndex: count - 1)
    }

    mutating func dequeue() -> Element? {
        guard !isEmpty else { return nil }
        swapElement(at: 0, with: count - 1)
        let element = array.removeLast()
        if !isEmpty {
            siftDown(elementAtIndex: 0)
        }
        return element
    }

    private mutating func siftUp(elementAtIndex index: Int) {
        let parent = parentIndex(of: index)
        guard !isRoot(index),
            isHigherPriority(at: index, than: parent) else {
                return
            }
        swapElement(at: index, with: parent)
        siftUp(elementAtIndex: parent)
    }

    mutating func siftDown(elementAtIndex index: Int) {
        let childIndex = highestPriorityIndex(for: index)
        if index == childIndex {
            return
        }
        swapElement(at: index, with: childIndex)
        siftDown(elementAtIndex: childIndex)
    }

    private func isHigherPriority(at firstIndex: Int, than secondIndex: Int) -> Bool {
        priorityFunction(array[firstIndex], array[secondIndex])
    }

    private mutating func swapElement(at firstIndex: Int, with secondIndex: Int) {
        guard firstIndex != secondIndex else { return }
        self.array.swapAt(firstIndex, secondIndex)
    }

    func highestPriorityIndex(of parentIndex: Int, and childIndex: Int) -> Int {
        guard childIndex < count
            && isHigherPriority(at: childIndex, than: parentIndex)
            else { return parentIndex }
        return childIndex
    }

    func highestPriorityIndex(for parent: Int) -> Int {
        return highestPriorityIndex(
            of: highestPriorityIndex(of: parent, and: leftChildIndex(of: parent)),
            and: rightChildIndex(of: parent)
        )
    }

}
```
```
Runtime: 8 ms, faster than 60.87% of Swift online submissions for Last Stone Weight.
Memory Usage: 14 MB, less than 73.91% of Swift online submissions for Last Stone Weight.
```

# Medium:

**Analysis:**

Call maximum stone weight is M

Time: O(NM/2) for two loops, so the overall complexity would be `O(NM)`

Space: O(M), which use 1D array for dp

```cpp
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  int lastStoneWeightII(vector<int> &stones) {
    int sum = accumulate(stones.begin(), stones.end(), 0);
    int halfSum = sum / 2;
    vector<bool> dp(halfSum + 1, false);
    dp[0] = true;

    int s2 = 0;
    for (int stone : stones) {
      for (int i = halfSum; i >= stone; i--) {
        if (!dp[i]) {
          dp[i] = dp[i - stone];
          if (dp[i])
            s2 = max(s2, i);
        }
      }
    }

    return sum - 2 * s2;
  }
}

```
```
Runtime: 4 ms, faster than 77.64% of C++ online submissions for Last Stone Weight II.
Memory Usage: 8 MB, less than 60.52% of C++ online submissions for Last Stone Weight II.
```

# Hard: Find K-th Smallest Pair Distance

We can use binary search to find the k-th smallest distance pair by guessing what we think k-th smallest distance will be. The pair of the largest and smallest elements in the array will have the largest distance between them. So, if two numbers are same, they will have a distance = 0. This gives us a lower and upper bound that we can use to perform binary search

1. First sort the array.
2. Create 2 variable:
- 3. `minDist` is minimum distance between two numbers is 0 if they are the same
- 4. `maxDist` is max distance in sorted array is leftmost - rightmost element
5. Do a binary search
- 6. Create `midDist`
- 7. Since we want the k-th smallest distance pair, we now need to count the number of pairs with a distance greater than `midDist` so that we can decide how to modify our search space
  - 8. If this condition is correct, then the current number and all numbers to its right will be greater than `midDist` from `nums[left]`
  - 9. Adds the number of pairs between right and left.3
- 10. We found too many pairs which means the k-th smallest distance pair must have a distance is less than our guess, so we remove the lower half of our search space
- 11. We found to few pairs which means the k-th smallest distance pair must have a distance that is greater than our guess so we remove the lower half of our search space

**Analysis:**
- Time: O(N Log N)
- Space: O(N) which use for sorted array

```swift
class Solution {
    func smallestDistancePair(_ nums: [Int], _ k: Int) -> Int {
        // 1
        let nums = nums.sorted()
        // 2
        var minDist = 0
        // 3
        var maxDist = nums[nums.count - 1] - nums[0]

        // 5
        while minDist <= maxDist {
            // 6
            let midDist = minDist + (maxDist - minDist) / 2

            // 7
            var left = 0
            var right = 0
            var count = 0

            while right < nums.count {
                if nums[right] - nums[left] > midDist {
                    // 8
                    left += 1
                } else {
                    // 9
                    let numberOfPairs = right - left
                    count += numberOfPairs
                    right += 1
                }
            }

            if count >= k {
                // 10
                maxDist = midDist - 1
            } else {
                // 11
                minDist = midDist + 1
            }
        }
        return minDist
    }
}
```
```
Runtime: 76 ms, faster than 66.67% of Swift online submissions for Find K-th Smallest Pair Distance.
Memory Usage: 14.8 MB, less than 5.56% of Swift online submissions for Find K-th Smallest Pair Distance.
```