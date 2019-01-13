# Problem 1

https://leetcode.com/problems/two-sum-ii-input-array-is-sorted

```go
func twoSum(numbers []int, target int) []int {
    numberMap := make(map[int]int, len(numbers))
    for index, numberValue := range numbers {
        if pairNumberIndex, existed := numberMap[target - numberValue]; existed {
            return []int{ pairNumberIndex, index+1 }
        }
        numberMap[numberValue] = index+1
    }
    return []int{}
}

```

# Problem 2

https://leetcode.com/problems/merge-intervals/

```go
func merge(intervals []Interval) []Interval {
    if len(intervals) < 1 {
        return intervals
    }
    top := 0
    sort.Slice(intervals, func (i, j int) bool {
        return intervals[i].Start < intervals[j].Start
    })
    result := []Interval{intervals[0]}
    for j:=1; j < len(intervals); j++ {
        if result[top].End >= intervals[j].Start {
            if result[top].End < intervals[j].End {
                result[top].End = intervals[j].End  
            }
            continue
        } 
        result = append(result, intervals[j])
        top++
    }
    return result
}
```
