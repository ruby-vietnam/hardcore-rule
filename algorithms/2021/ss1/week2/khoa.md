# Easy: Last Stone Weight

## O(N^2 log N) Naive solution

- Sort the array in descending order
- Pickup the first two elements
- Compare them and append to the array

Analysis:
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

WIP

# Hard:

WIP