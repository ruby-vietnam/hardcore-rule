# Find the Town Judge

``` typescript
function findJudge(n: number, trust: number[][]): number {
    let like = Array(n + 1).fill(0)
    let beLike = Array(n + 1).fill(0)
    for(let i = 0; i < trust.length; i++) {
        like[trust[i][0]]++
        beLike[trust[i][1]]++
    }
    for(let i = 1; i <= n; i++) {
        if(beLike[i] === n - 1 && like[i] === 0) return i
    }
    return -1
};
```


# Last Stone Weight

``` typescript
function lastStoneWeight(stones: number[]): number {
    let maxHeap = new MaxHeap<number>((a,b) => {
        if(a>b) return 1
        if(a===b) return 0
        return -1
    })
    for(let stone of stones) {
        maxHeap.push(stone)
    }
    while(maxHeap.length) {
        let biggest = maxHeap.pop()
        if(!maxHeap.length) return biggest
        let second = maxHeap.pop()
        if(biggest - second > 0) maxHeap.push(biggest - second)
    }
    
    return 0

};

class MaxHeap<T> {
    private heap: T[];
    private compare: (node1: T, node2: T) => 1 | -1 | 0;
    /**
     *
     * @param compareFunction return 1 if node 1 > node 2, return -1 if node 1 < node 2, return 0 if node1 = node2
     */
    constructor(compareFn: (node1: T, node2: T) => 1 | -1 | 0) {
        this.heap = [];
        this.compare = compareFn;
    }

    get length(): number {
        return this.heap.length;
    }

    public peek(): T | undefined {
        if (this.length > 0) return this.heap[0];
        else return undefined;
    }

    public push(node: T): void {
        this.heap.push(node);
        this.bubbleUp();
    }

    public pop(): T | undefined {
        if (this.length === 0) {
            return undefined;
        }
        [this.heap[0], this.heap[this.length - 1]] = [
            this.heap[this.length - 1],
            this.heap[0],
        ];
        const pop = this.heap.pop();
        this.bubbleDown();
        return pop;
    }

    private bubbleUp(): void {
        let current = this.length - 1;
        while (current > 0) {
            let parent = Math.ceil(current / 2) - 1;
            if (this.compare(this.heap[current], this.heap[parent]) == 1) {
                [this.heap[current], this.heap[parent]] = [
                    this.heap[parent],
                    this.heap[current],
                ];
                current = parent;
            } else {
                return;
            }
        }
    }

    private bubbleDown(): void {
        let current = 0;
        while (true) {
            let left = current * 2 + 1;
            if (left >= this.length) return;
            let right = left + 1;
            if (right >= this.length) right = left;
            let bigger: number;
            if (this.compare(this.heap[left], this.heap[right]) == 1) {
                bigger = left;
            } else {
                bigger = right;
            }
            if (this.compare(this.heap[bigger], this.heap[current]) == 1) {
                [this.heap[bigger], this.heap[current]] = [
                    this.heap[current],
                    this.heap[bigger],
                ];
                current = bigger;
            } else {
                return;
            }
        }
    }
}
```


# Count Complete Tree Nodes

``` typescript
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function countNodes(root: TreeNode | null): number {
    if(!root) return 0
    let leftLevel = getHeight(root.left)
    let rightLevel = getHeight(root.right)
    if(leftLevel > rightLevel) {
        return countNodes(root.left) + (1 << rightLevel)
    } else {
        return (1 << rightLevel) + countNodes(root.right)
    }
    
};

function getHeight(root) {
    if(!root) return 0
    return getHeight(root.left) + 1
}
```

# Top K Frequent Elements

``` typescript
function topKFrequent(nums: number[], k: number): number[] {
    let freqMap = new Map()
    let result = []
    for(let num of nums) {
        freqMap.set(num, (freqMap.get(num) || 0)  + 1)
    }
    let buckets = Array(nums.length + 1).fill(0).map(() => [])
    for(let [key, freq] of freqMap.entries()) {
        buckets[freq].push(key)
    }
    for(let i = nums.length; i > 0 && result.length < k; i--) {
        result.push(...buckets[i])
    }
    return result
};
```