Problem 1:

https://play.golang.org/p/Ucpn4yfhbv8

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

Problem 2:

N/A

Problem 3:

https://play.golang.org/p/9fYhFYnNr3b

```

func rotate(matrix [][]int) {
	length := len(matrix)
	
	// Transpose
	for rowIndex, _ := range matrix {
		for columnIndex:=0; columnIndex < rowIndex;columnIndex++  { 
			matrix[rowIndex][columnIndex], matrix[columnIndex][rowIndex] = matrix[columnIndex][rowIndex], matrix[rowIndex][columnIndex]
		}
	}
	
	// Reverse
	for rowIndex, _ := range matrix {
		for columnIndex:=0; columnIndex < length / 2;columnIndex++  {
			matrix[rowIndex][columnIndex], matrix[rowIndex][length-columnIndex-1] = matrix[rowIndex][length-columnIndex-1], matrix[rowIndex][columnIndex]
		}
	}
}
```

Problem Bonus:

Bases alot idea from https://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/

```

func countSmaller(nums []int) []int {
	if len(nums) == 0 {
		return []int{}
	}

	min := 1<<31 - 1
	max := -1 << 31

	for _, item := range nums {
		if item < min {
			min = item
		}
	}

	cloned := make([]int, 0, len(nums))
	for index, item := range nums {
		counting := item - min + 1
		cloned = append(cloned, counting)
		if counting > max {
			max = cloned[index]
		}
	}

	tree := make([]int, max+1, max+1)
	result := make([]int, 0, len(nums))
	for index := len(cloned) - 1; index >= 0; index-- {
		result = append(result, get(cloned[index]-1, tree))
		update(cloned[index], tree)
	}

	// Reverse
	for i, j := 0, len(result)-1; i < j; i, j = i+1, j-1 {
		result[i], result[j] = result[j], result[i]
	}

	return result
}

func get(index int, tree []int) int {
	num := 0
	for index > 0 {
		num += tree[index]
		index -= index & (-index)
	}
	return num
}

func update(index int, tree []int) {
	for index < len(tree) {
		tree[index]++
		index += index & (-index)
	}
}
```
