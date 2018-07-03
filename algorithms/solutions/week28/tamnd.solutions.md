## Problem 1

```go
func checkPossibility(nums []int) bool {
    hit := false
    n := len(nums)
    for i := 0; i < n-1; i++ {
        if nums[i] > nums[i+1] {
            if hit {
                return false
            }
            hit = true
            if i-1 < 0 || nums[i-1] <= nums[i+1] {
                nums[i] = nums[i+1]
            } else {
                nums[i+1] = nums[i]
            }
        }
    }
    return true
}
```

## Problem 2

```go
func permute(nums []int) [][]int {
    var i, j int // uper index i, lower index j
    n := len(nums)
    p := make([]int, n)
    for i = 0; i < n; i++ {
        p[i] = 0
    }
    ret := make([][]int, 0)
    ret = append(ret, nums)
    i = 1
    for i < n {
        if p[i] < i {
            j = i%2*p[i] // if i is odd then j = p[i], otherwise j = 0
            nums[i], nums[j] = nums[j], nums[i]
            b := make([]int, n)           
            copy(b, nums)
            ret = append(ret, b)
            p[i]++
            i = 1 // rest index i to 1
        } else {
            p[i] = 0
            i++
        }
    }
    return ret
}
```

```go
func permute(nums []int) [][]int {
    ret := make([][]int, 0)
    n := len(nums)
    a := make([]int, n)
    for i := 0; i < n; i++ {
        a[i] = i
    }
    ret = append(ret, nums)
    for next(a) {
        b := make([]int, n)
        for i := 0; i < n; i++ {
            b[i] = nums[a[i]]
        }
        ret = append(ret, b)
    }
    return ret
}

func next(a []int) bool {
    n := len(a)
    if n < 2 {
        return false
    }
    i := n-2
    for i >= 0 && a[i] > a[i+1] {
        i--
    }
    if i < 0 {
        return false
    }
    j := n-1
    for a[j] < a[i] {
        j--
    }
    a[i], a[j] = a[j], a[i]
    reverse(a, i+1, n-1)
    return true
}  

func reverse(a []int, l int, r int) {
    for l < r {
        a[l], a[r] = a[r], a[l]
        l++
        r--
    }
}
```

## Problem 3 
```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

import java.util.StringTokenizer;

public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        StringBuilder builder = new StringBuilder();
        bufferedSerialize(builder, root);
        return builder.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        StringTokenizer tokenizer = new StringTokenizer(data, " ");
        return bufferedDeserialize(tokenizer);
    }
    
    private void bufferedSerialize(StringBuilder builder, TreeNode root) {
        if (root == null) {
            builder.append("? ");
        } else {
            builder.append(root.val);
            builder.append(" ");
            bufferedSerialize(builder, root.left);
            bufferedSerialize(builder, root.right);
        }
    }
    
    private TreeNode bufferedDeserialize(StringTokenizer tokenizer) {
        if (!tokenizer.hasMoreTokens()) {
            return null;
        }
        
        String token = tokenizer.nextToken();
        if (token.equals("?")) {
            return null;
        }
        TreeNode root = new TreeNode(Integer.parseInt(token));
        root.left = bufferedDeserialize(tokenizer);
        root.right = bufferedDeserialize(tokenizer);
        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));
```

## Problem 4
```go
import "container/heap"

type MinHeap []int
func (h MinHeap) Len() int           { return len(h) }
func (h MinHeap) Less(i, j int) bool { return h[i] > h[j] }
func (h MinHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *MinHeap) Push(x interface{}) {
    *h = append(*h, x.(int))
}
func (h *MinHeap) Pop() interface{} {
    old := *h
    n := len(old)
    x := old[n-1]
    *h = old[0: n-1]
    return x
}

type MaxHeap []int
func (h MaxHeap) Len() int           { return len(h) }
func (h MaxHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h MaxHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *MaxHeap) Push(x interface{}) {
    *h = append(*h, x.(int))
}
func (h *MaxHeap) Pop() interface{} {
    old := *h
    n := len(old)
    x := old[n-1]
    *h = old[0: n-1]
    return x
}

type MedianFinder struct {
    minHeap *MinHeap
    maxHeap *MaxHeap
}


/** initialize your data structure here. */
func Constructor() MedianFinder {
    minHeap := &MinHeap{}
    heap.Init(minHeap)
    maxHeap := &MaxHeap{}
    heap.Init(maxHeap)
    return MedianFinder{
        minHeap: minHeap,
        maxHeap: maxHeap,
    }
}


func (mf *MedianFinder) AddNum(num int)  { 
    heap.Push(mf.minHeap, num)
    heap.Push(mf.maxHeap, heap.Pop(mf.minHeap))
    
    if mf.maxHeap.Len() > mf.minHeap.Len() {
        heap.Push(mf.minHeap, heap.Pop(mf.maxHeap))
    }
}

func (mf *MedianFinder) FindMedian() float64 {
    if mf.minHeap.Len() > mf.maxHeap.Len() {
        return top(*mf.minHeap)
    } else {
        return (top(*mf.minHeap) + top(*mf.maxHeap)) / 2.0
    }
}

func top(h []int) float64 {
    if len(h) == 0 {
        return 0.0
    }
    return float64(h[0])
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AddNum(num);
 * param_2 := obj.FindMedian();
 */
 ```
