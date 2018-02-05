## Problem 2

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isSymmetric(root *TreeNode) bool {
    if root == nil {
        return true 
    }
    
    return checkSymmetric(root.Left, root.Right)
}

func checkSymmetric(left *TreeNode, right *TreeNode) bool {
    if left == nil {
        return right == nil
    }
    
    if right == nil {
        return false 
    }
    
    if left.Val != right.Val {
        return false
    }
    
    return checkSymmetric(left.Left, right.Right) && checkSymmetric(left.Right, right.Left)
}
```

## Problem 3

```go
func candy(ratings []int) int {
    if ratings == nil || len(ratings) == 0 {
        return 0
    }
    
    n := len(ratings)
    if n == 1 {
        return 1
    }
    
    candies := make([]int, n)
    
    i, j, k, peak := 0, 0, 0, 0
    for i < n {
        j = i
        for j + 1 < n && ratings[j] < ratings[j + 1] {
            j++ 
        }
        
        // now j is peak
        peak = j
        
        for j + 1 < n && ratings[j] > ratings[j+1] {
            j++
        }
        
        // so we have i < peak > j 
        if i == j {
            if candies[i] == 0 {
                candies[i] = 1
            }
            
            i++
            continue
        }
        
        if i == peak {
            candies[j] = 1
            for k := j-1; k >= i; k-- {
                candies[k] = candies[k+1] + 1
            }
        } else if j == peak {
            candies[i] = 1
            for k := i+1; k <= peak; k++ {
                candies[k] = candies[k-1] + 1
            }
        } else {
            candies[j] = 1
            for k := j-1; k > peak; k-- {
                candies[k] = candies[k+1] + 1
            }
            
            candies[i] = 1
            for k := i+1; k < peak; k++ {
                candies[k] = candies[k-1] + 1
            }
            
            k = peak + 1
            if candies[peak-1] > candies[k] {
                k = peak - 1
            }
            
            candies[peak] = candies[k] + 1
        }
        
        i = j
    }
    
    sum := 0
    for i := range candies {
        sum += candies[i]
    }
    
    return sum
}
```

## Problem bonus

```go
type LRUCache struct {
	cache    *list.List
	data     map[int]*list.Element
	capacity int
}

type LRUCacheItem struct {
	key   int
	value int
}

func Constructor(capacity int) LRUCache {
	return LRUCache{capacity: capacity, data: make(map[int]*list.Element, capacity), cache: list.New()}
}

func (c *LRUCache) Get(key int) int {
	if c.data == nil {
		return -1
	}

	if v, ok := c.data[key]; ok {
		// promote this element
		c.cache.MoveToFront(v)

		return v.Value.(*LRUCacheItem).value
	}

	return -1
}

func (c *LRUCache) Put(key int, value int) {
	if v, ok := c.data[key]; ok {
		// promote this element
		c.cache.MoveToFront(v)
        
        // set value
        v.Value.(*LRUCacheItem).value = value

		return
	}

	if len(c.data) >= c.capacity {
		if tail := c.cache.Back(); tail != nil {
			toRemove := c.cache.Remove(tail).(*LRUCacheItem)
			delete(c.data, toRemove.key)
		}
	}

	newElement := c.cache.PushFront(&LRUCacheItem{key: key, value: value})
	c.data[key] = newElement
}
```

## Problem bonus 2

```go
// Solution: sử dụng 2 map, link lẫn nhau.
// Map data và index.
// Map data[I] trả về giá trị tại vị trí I
// Map index[Val] trả về vị trí của value Val
// - Một thao tác insert Val sẽ set vị trí cho nó = size + 1 (vị trí cuối cùng)
// - Một thao tác xóa thực chất là swap vị trí cuối cùng lên vị trí cần xóa. Rồi xóa phần tử cuối cùng đi
// làm vậy sẽ luôn đảm bảo các value được đánh vị trí `liên tục` từ 0 --> size - 1
// - Thao tác get random đơn giản vì mọi value được đánh vị trí một cách liên tục, chỉ việc % là xong.
// Mọi thao tác là O(1)
type RandomizedSet struct {
    data map[int]int
    index map[int]int
    size int
    r *rand.Rand
}


/** Initialize your data structure here. */
func Constructor() RandomizedSet {
    return RandomizedSet{
        data: make(map[int]int, 1024),
        index: make(map[int]int, 1024),
        size: 0,
        r: rand.New(rand.NewSource(55)),
    }
}


/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
func (this *RandomizedSet) Insert(val int) bool {
    if _, ok := this.index[val]; ok {
        return false
    }
    
    size := this.size
    this.index[val] = size
    this.data[size] = val
    this.size++
    return true
}


/** Removes a value from the set. Returns true if the set contained the specified element. */
func (this *RandomizedSet) Remove(val int) bool {
    size := this.size
    if size == 0 {
        return false
    }
    
    if ind, ok := this.index[val]; ok {
        // remove from data
        delete(this.index, val)
        
        // try to swap with last element
        if size--; size != 0 && size != ind {
            dat, _ := this.data[size]
            this.data[ind] = dat
            this.index[dat] = ind
        }
        this.size = size
        delete(this.data, size)
        
        return true
    }
    
    return false
}


/** Get a random element from the set. */
func (this *RandomizedSet) GetRandom() int {
    if this.size == 0 {
        return 0
    }
    
    dat, _ := this.data[this.r.Int() % this.size]
    return dat
}
```
