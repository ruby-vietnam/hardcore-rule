Problem 1:

```

type LeftRight struct {
	Left   int
	Right  int
	Count  int
	Length int
}

func findShortestSubArray(nums []int) int {
	length := len(nums)
	mapOfLeftRight := make(map[int]LeftRight)
	var maxItem LeftRight
	for i := 0; i < length; i++ {
		number := nums[i]
		leftRight, ok := mapOfLeftRight[number]
		if !ok {
			leftRight = LeftRight{
				Left:   i,
				Right:  -1,
				Count:  1,
				Length: 1,
			}
		} else {
			leftRight.Right = i
			leftRight.Length = leftRight.Right - leftRight.Left + 1
			leftRight.Count++

			if leftRight.Count > maxItem.Count ||
				(leftRight.Count != -1 && leftRight.Count == maxItem.Count && leftRight.Length < maxItem.Length) {
				maxItem = leftRight
			}
		}

		mapOfLeftRight[number] = leftRight
	}

	if maxItem.Length == 0 {
		return 1
	}
	return maxItem.Length
}

```
