### Session 4 - Week 4

1. https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

```go
func maxProfit(prices []int) int {
	max := 0
	minBuy := prices[0]
	sell := 1

	for sell < len(prices) {
		if minBuy > prices[sell] {
			minBuy = prices[sell]
		} else if max < prices[sell]-minBuy {
			max = prices[sell] - minBuy
		}
		sell++
	}

	return max
}
```

2. https://leetcode.com/problems/two-sum/

```go
func twoSum(nums []int, target int) []int {
	mapping := make(map[int]int)

	for index, num := range nums {
		remain := target - num
		if res, ok := mapping[remain]; ok {
			return []int{res, index}
		} else {
			mapping[num] = index
		}
	}

	return nil
}
```

3. https://leetcode.com/problems/merge-intervals/

```go
type twoDimArr [][]int

func (arr twoDimArr) Len() int {
	return len(arr)
}
func (arr twoDimArr) Swap(i, j int) {
	arr[i], arr[j] = arr[j], arr[i]
}
func (arr twoDimArr) Less(i, j int) bool {
	return arr[i][0] < arr[j][0]
}

func merge(intervals [][]int) [][]int {
	result := make([][]int, 0, 1)

	if len(intervals) <= 1 {
		result = append(result, intervals...)
	} else {
		sort.Sort(twoDimArr(intervals))
		current := intervals[0]
		min, max := current[0], current[1]
		for i := 1; i < len(intervals); i++ {
			nextMin, nextMax := intervals[i][0], intervals[i][1]

			if nextMin > max {
				result = append(result, []int{min, max})
				min = nextMin
				max = nextMax
			} else if max <= nextMax {
				max = nextMax
			}
		}

		result = append(result, []int{min, max})
	}

	return result
}
```
