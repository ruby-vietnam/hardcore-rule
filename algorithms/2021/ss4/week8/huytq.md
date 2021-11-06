# Sum of Left Leaves

``` ruby
# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val = 0, left = nil, right = nil)
#         @val = val
#         @left = left
#         @right = right
#     end
# end
# @param {TreeNode} root
# @return {Integer}
def sum_of_left_leaves(root)
    @result = 0
    
    def dfs(node, parentGoLeft)
        if node == nil
            return
        end
        
        if node.left == nil && node.right == nil && parentGoLeft
            @result += node.val
        end
        dfs(node.left, true)
        dfs(node.right, false)
    end
    
    dfs(root, false)
    return @result
end
```

# Heaters

``` ruby
# @param {Integer[]} houses
# @param {Integer[]} heaters
# @return {Integer}
def find_radius(houses, heaters)
    houses.sort!
    heaters.sort!
    ans = 0
    houses.each do |house|
        min = 0
        max = heaters.length - 1
        while min < max
            mid = min + ((max - min + 1) / 2).ceil
            if heaters[mid] < house
                min = mid
            else
                max = mid - 1
            end
        end
        left = (heaters[min] - house).abs
        
        min = 0
        max = heaters.length - 1
        while min < max
            mid = min + ((max - min) / 2).floor
            if heaters[mid] < house
                min = mid + 1
            else
                max = mid
            end
        end
        right = (heaters[min] - house).abs
        
        ans = [[left, right].min, ans].max
    end
    
    ans
end
```


# Number of Ways to Arrive at Destination

``` typescript
function countPaths(n: number, roads: number[][]): number {
    let graph = new Map()
    const MOD = 1e9 + 7
    for(let road of roads) {
        if(!graph.has(road[0])) graph.set(road[0], [])
        if(!graph.has(road[1])) graph.set(road[1], [])
        graph.get(road[0]).push([road[1], road[2]])
        graph.get(road[1]).push([road[0], road[2]])
    }
    
    let minHeap = new MinHeap<any>((a,b) => {
        if(a[1] < b[1]) return -1
        if(a[1] === b[1]) return 0
        return 1
    })
    
    let ways = Array(n).fill(0)
    ways[0] = 1
    let distance = Array(n).fill(Number.MAX_SAFE_INTEGER)
    distance[0] = 0
    
    minHeap.push([0, 0])
    
    while(minHeap.length) {
        let [current, currentDistance] = minHeap.pop()
        if(current === n - 1) return ways[current]
        if(distance[current] < currentDistance) continue
        for(let [connect, dist] of graph.get(current)) {
            if(distance[connect] < currentDistance + dist) continue
            if(distance[connect] > currentDistance + dist) {
                distance[connect] = currentDistance + dist
                ways[connect] = ways[current]
                minHeap.push([connect, currentDistance + dist])
            } else if(distance[connect] === currentDistance + dist) {
                ways[connect] += ways[current]
                ways[connect] %= MOD
            }
        }
    }
    
    return ways[n - 1]
};

class MinHeap<T> {
    private heap: T[];
    private compare: (a: T, b: T) => 1 | 0 | -1
    constructor(compareFunction: (a:T, b:T) => 1 | 0 | -1) {
        this.heap = [];
        this.compare = compareFunction
    }

	get length(): number{
		return this.heap.length
	}
	
    public peek(): T | undefined {
		if(this.length > 0)
			return this.heap[0];
		else 
			return undefined
    }

    public push(val: T) {
        this.heap.push(val);
        this.bubbleUp();
    }
    
    public pop(): T | undefined {
        if(this.length === 0) {
            return undefined
        } 
        [this.heap[0], this.heap[this.length - 1]] = [this.heap[this.length - 1],this.heap[0]]
        const pop = this.heap.pop();
        this.bubbleDown();
        return pop;
    }

    private bubbleUp(): void {
        let current = this.length - 1;
        while (current > 0) {
            let parent = Math.ceil(current / 2) - 1;
            if (this.compare(this.heap[current], this.heap[parent]) == -1) {
				[this.heap[current], this.heap[parent]] = [ this.heap[parent], this.heap[current]];
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
            let smaller: number;
            if (this.compare(this.heap[left], this.heap[right]) == -1) {
                smaller = left;
            } else {
                smaller = right;
            }
            if (this.compare(this.heap[smaller], this.heap[current]) == -1) {
                [this.heap[smaller], this.heap[current]] = [
                    this.heap[current],
                    this.heap[smaller],
                ];
                current = smaller;
            } else {
                return;
            }
        }
    }
}
```

# Scramble String

``` typescript
function isScramble(s1: string, s2: string): boolean {
    const cache = new Map()
    let dfs = (str1, str2) => {
        if(str1 === str2) return true
        const key = `${str1},${str2}`
        if(cache.has(key)) return cache.get(key)
        for(let i = 1; i < str1.length; i++) {
            let left1 = str1.slice(0, i)
            let right1 = str1.slice(i)
            let left2 = str2.slice(0, i)
            let right2 = str2.slice(i)
            if(dfs(left1, left2) && dfs(right1, right2)) {
                cache.set(key, true)
                return true
            }
            let swapLeft2 = str2.slice(0, right1.length)
            let swapRight2 = str2.slice(right1.length)
            if(dfs(left1, swapRight2) && dfs(right1, swapLeft2)) {
                cache.set(key, true)
                return true
            }
        }
        cache.set(key, false)
        return false
    }
    return dfs(s1, s2)
};
```