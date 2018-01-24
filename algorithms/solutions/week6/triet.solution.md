## problem 1

```
func findShortestSubArray(nums []int) int {
   mapIndex := map[int]int{} // number and its first index
	mapFreq := map[int]int{}
	degree := 0
	minLength := len(nums)
	for i, num := range nums {
		if _, exists := mapFreq[num]; exists {
			mapFreq[num]++
			if mapFreq[num] > degree {
				degree = mapFreq[num]
				minLength = i - mapIndex[num] + 1
			}
            if mapFreq[num] == degree {
				if minLength > i-mapIndex[num] {
					minLength = i - mapIndex[num] + 1
				}
			}

		} else {
			mapIndex[num] = i
			mapFreq[num] = 1
		}
	}


	if degree == 0 {
		return 1
	}


	return minLength

}
```

