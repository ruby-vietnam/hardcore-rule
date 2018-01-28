# Problem 1: Degree of an Array

URL: https://leetcode.com/problems/degree-of-an-array/description/

```go
func findShortestSubArray(nums []int) int {
	type Sub struct {
		start int
		end   int
		count int
	}

	var sub = make(map[int]*Sub)

	isub := 0
	esub := 0
	maxSub := 0
	for i, v := range nums {
		if _, ok := sub[v]; ok {
			sub[v].count++
			sub[v].end = i
		} else {
			sub[v] = &Sub{
				count: 1,
				start: i,
				end:   i,
			}
		}

		if sub[v].count > maxSub {
			maxSub = sub[v].count
			isub = sub[v].start
			esub = sub[v].end
		} else if sub[v].count == maxSub {
			if sub[v].end-sub[v].start < esub-isub {
				isub = sub[v].start
				esub = sub[v].end
			}
		}
	}

	return esub - isub + 1
}
```
