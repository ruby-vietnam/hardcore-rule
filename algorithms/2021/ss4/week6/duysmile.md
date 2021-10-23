1. https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
```go
func twoSum(numbers []int, target int) []int {
	i, j := 0, len(numbers)-1

	sum := numbers[i] + numbers[j]
	for i < j {
		if sum == target {
			return []int{i + 1, j + 1}
		} else if sum > target {
			j--
		} else {
			i++
		}
		sum = numbers[i] + numbers[j]
	}

	return nil
}
```

2. https://leetcode.com/problems/longest-substring-without-repeating-characters/
```go
func lengthOfLongestSubstring(s string) int {
	if len(s) <= 1 {
		return len(s)
	}

	i, j := 0, 1

	max := 0
	o := make(map[string]int)
	for {
		o[string(s[i])] = i
		for j < len(s) {
			pre, ok := o[string(s[j])]

			if ok && pre >= i {
				if max < j-i {
					max = j - i
				}

				if i > pre || pre+1 == j {
					i = j
				} else {
					i = pre + 1
				}
			}

			fmt.Println(o)
			fmt.Println(max)
			fmt.Println("i:", i, "- j:", j)

			o[string(s[j])] = j
			j++

			if ok {
				break
			}
		}

		if j > len(s)-1 {
			break
		}
	}

	if max < j-i {
		max = j - i
	}

	return max
}
```
