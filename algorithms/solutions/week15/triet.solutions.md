## Problem 1
https://leetcode.com/problems/move-zeroes/

```go
func moveZeroes(nums []int) {
	if len(nums) <= 1 {
		return
	}
	countZ := 0

	i := 0
	for i < len(nums) {
		// 0 1 0 3 12
		if nums[i] == 0 {
			countZ++
			i++
			continue
		}
		nums[i-countZ] = nums[i]
		i++
	}

	// Replace countZ = 0
	for i := 0; i < countZ; i++ {
		nums[len(nums)-i-1] = 0
	}
}
```

## Problem 2
https://leetcode.com/submissions/detail/147989296/

Use heap

```go
func nthUglyNumber(n int) int {
	mapMarkedGenerated := map[int]bool{}

	h := heap{}

	h.Init(1)
	h.push(1)
	i := 1
	top := 1
	for i <= n {
		/*fmt.Println("BEFORE:", h)*/
		top = h.pop()
		/*fmt.Println("AFTER:", h)*/
		if _, exists := mapMarkedGenerated[top*2]; !exists {
			h.push(top * 2)
			mapMarkedGenerated[top*2] = true
		}

		if _, exists := mapMarkedGenerated[top*3]; !exists {
			h.push(top * 3)
			mapMarkedGenerated[top*3] = true
		}

		if _, exists := mapMarkedGenerated[top*5]; !exists {
			h.push(top * 5)
			mapMarkedGenerated[top*5] = true
		}
		fmt.Println(h, "Top:", top, "i:", i)

		i++
	}

	return top
}

type heap []int

func (h *heap) Init(n int) {
	t := heap(make([]int, n))
	h = &t
}

func (h *heap) size() int {
	return len(*h)
}

func (h *heap) isEmpty() bool {
	return len(*h) == 0
}

func (h *heap) push(v int) {
	*h = append(*h, v)
	// sift up if needed
	h.up(h.size() - 1)
}

func (h heap) up(i int) {
	for {
		if i == 0 {
			return
		}
		parentIndex := (i - 1) / 2
		if parentIndex == i {

		}
		if h[i] < h[parentIndex] {
			h.swap(i, parentIndex)
			i = parentIndex
		} else {
			return
		}
	}
}

func (h heap) down(i int) {
	for {
		if i > h.size()-1 {
			return
		}

		// if node at i has left child
		if (i+1)*2-1 < len(h) {
			// pick min node in left and right child
			minNodeIndex := (i+1)*2 - 1
			if minNodeIndex+1 < len(h) {
				if h[minNodeIndex+1] < h[minNodeIndex] {
					minNodeIndex++
				}
			}
			/*fmt.Println("minNode", minNodeIndex)*/
			/*fmt.Println("before", h)*/

			// compare with min node
			if h[i] > h[minNodeIndex] {
				h.swap(i, minNodeIndex)
				i = minNodeIndex
			} else {
				break
			}

			/*fmt.Println("after", h)*/
		} else {
			// don't have right child for sure
			break
		}

	}
}

func (h heap) swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

func (h *heap) pop() int {
	if h.isEmpty() {
		panic("empty")
	}
	// get max
	top := (*h)[0]

	n := h.size()
	// swap end node to top
	h.swap(0, n-1)
	// remove end node
	*h = (*h)[0 : n-1]
	// sift down
	h.down(0)

	return top
}
```
