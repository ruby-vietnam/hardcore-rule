# Easy: Majority Element

https://leetcode.com/problems/majority-element/

### Code

```go
func majorityElement(nums []int) int {
	sortedNums := quicksort(nums, 0, len(nums)-1)
	return sortedNums[len(sortedNums)/2]
}

func quicksort(nums []int, low, high int) []int {
	if low < high {
		var pivot int
		nums, pivot = partition(nums, low, high)
		nums = quicksort(nums, low, pivot-1)
		nums = quicksort(nums, pivot+1, high)
	}
	return nums
}

func partition(nums []int, low, high int) ([]int, int) {
	p := nums[high]
	i := low
	for j := low; j < high; j++ {
		if nums[j] < p {
			nums[i], nums[j] = nums[j], nums[i]
			i++
		}
	}
	nums[i], nums[high] = nums[high], nums[i]
	return nums, i
}
```

### Submission Detail

```
47 / 47 test cases passed.
Status: Accepted
Runtime: 572 ms
Memory Usage: 12.7 MB
```

# Medium : 3Sum

https://leetcode.com/problems/3sum/

### Code

```go
import "sort"

func threeSum(nums []int) [][]int {
	res := [][]int{}
	sort.Ints(nums)

	for i := 0; i < len(nums)-2; i++ {
		if i == 0 || (i > 0 && nums[i] != nums[i-1]) {
			low := i+1
			high := len(nums)-1
			sum := 0 - nums[i]
			for low < high {
				if nums[low]+nums[high] == sum {
					res = append(res, []int{nums[i], nums[low], nums[high]})
					for low < high && nums[low] == nums[low+1] {
						low++
					}
					for low < high && nums[high] == nums[high-1] {
						high--
					}
					low++
					high--
				} else if nums[low] + nums[high] > sum {
					high--
				} else {
					low++
				}
			}
		}
	}
	return res
}
```

### Submission Detail

```
318 / 318 test cases passed.
Status: Accepted
Runtime: 32 ms
Memory Usage: 7.6 MB
```
