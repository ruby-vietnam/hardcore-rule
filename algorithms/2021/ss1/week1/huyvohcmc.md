# Easy: Palindrome Linked List

Leetcode: https://leetcode.com/problems/palindrome-linked-list/

Since reversing the second-half of the linked list is a common solution, I wanted to solve this problem in a different way but still with O(N) time complexity and O(2) space.

### Approach

Because the given linked list represents an integer number, we can compute the number by traversing the list from head to tail. To check whether this number is palindrome, we can traverse the list again but this time from *tail to head*, compute a second number along the way and finally we compare the two numbers together to get the result:

```go
func isPalindrome(head *ListNode) bool {
	if head == nil || head.Next == nil {
		return true
	}
	num, numReversed := 0, 0
	var prev, next *ListNode
	for head != nil {
		num = num*10 + head.Val
		next = head.Next
		head.Next = prev
		prev = head
		head = next
	}
	for prev != nil {
		numReversed = numReversed*10 + prev.Val
		prev = prev.Next
	}
	return num == numReversed
}
```

### Submission Detail

```
85 / 85 test cases passed.
Status: Accepted
Runtime: 168 ms
Memory Usage: 8.4 MB
```

# Medium: Permutations

Leetcode: https://leetcode.com/problems/permutations/

### Approach

Imagine we have a given array `[1, 2, 3]`, all of its permutations is `[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]`.

So, the base case: `[1]` will only has one permutation which is itself. This is useful since we will solve this problem the recursive way.

If our input is `[1, 2]` we can:
1. take out `1` from input and ask our function to get all permutations of `[2]`, which is also `[2]` (base case)
2. append `1` back to `[2]`, we get `[2, 1]`
3. take out `2` from input, permutations of `[1]` is just `[1]`
4. append `2` back to `[1]`, we get `[1, 2]`
5. the final result is `[[2, 1], [1, 2]]`

In summary, we will loop through the input, take out the ith element and find all permutations of the remaining input. When all permutations are returned, we then add the ith element to each of the permutation, and then add all permutations to the final result.

```go
func permute(nums []int) [][]int {
	if len(nums) == 1 {
		return [][]int{nums}
	}
	res := [][]int{}

	for i := range nums {
		numsSlice := make([]int, len(nums))
		copy(numsSlice, nums)
		numsSlice[i], numsSlice[0] = numsSlice[0], numsSlice[i]
		numsSlice = numsSlice[1:]
		perms := permute(numsSlice)
		for _, perm := range perms {
			perm = append(perm, nums[i])
			res = append(res, perm)
		}
	}
	return res
}
```

### Submission Detail

```
25 / 25 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 3.3 MB
```

# Hard: Palindrome Pairs

Leetcode: https://leetcode.com/problems/palindrome-pairs/

After playing around with the inputs, there are 4 cases we need to address:

### Case 1

There is one empty string in the array (only one - because the array is unique words), so for any word `s` that is a palindrome, `"" + s` and `s + ""` is a palindrome.

```
["", "a"] // [[0, 1], [1, 0]]
```

### Case 2

For any string s1, if there exists s2 that is a reversed string of s1, then s1 + s2 and s2 + s1 is a palindrome.

```
["abc", "cba"] // [[0, 1], [1, 0]]
```

### Case 3 (this is quite tricky)

For any string s1, if `s1[0:pivot]` is a palindrome and there exists a s2 that is a reversed string of `s1[pivot:]`, then `s2 + s1` is a palindrome. We need to loop through the indices of string s1 and constantly check for 2 conditions listed to find the pivot.

```
["abaffee", "eeff"] // [[1, 0]]
```

### Case 4 (similar to case 3)

For any string s1, if `s1[pivot:]` is a palindrome and there exists a s2 that is a reversed string of `s1[0:pivot]`, then `s1 + s2` is a palindrome.

```
["abcaba", "cba"] // [[0, 1]]
```

### Code

For case 1, we just need to check whether the input contains empty string, if yes then loop through the input once to find any palindrome.

For case 2, 3, and 4, we can build a HashMap to store words as keys and word indices as values, so we can easier looking up for words existence without writing nested for loops.

```go
func palindromePairs(words []string) [][]int {
	result := [][]int{}
	if words == nil || len(words) == 0 {
		return result
	}

	m := make(map[string]int)
	for i := range words {
		m[words[i]] = i
	}

	// case 1
	for i := range words {
		if words[i] == "" {
			for j := range words {
				if isPalindrome(words[j]) {
					if i != j {
						result = append(result, []int{i, j}, []int{j, i})
					}
				}
			}
			break
		}
	}

	// case 2
	for i := range words {
		reversed := reverse(words[i])
		if j, ok := m[reversed]; ok {
			if i != j {
				result = append(result, []int{i, j})
			}
		}
	}

	// case 3 and 4
	for i := range words {
		s1 := words[i]
		for j := 1; j < len(s1); j++ {
			if isPalindrome(s1[:j]) {
				s2 := reverse(s1[j:])
				if k, ok := m[s2]; ok {
					if k != i {
						result = append(result, []int{k, i})
					}
				}
			}
			if isPalindrome(s1[j:]) {
				s2 := reverse(s1[:j])
				if k, ok := m[s2]; ok {
					if k != i {
						result = append(result, []int{i, k})
					}
				}
			}
		}
	}

	return result
}

func isPalindrome(input string) bool {
	for i := 0; i < len(input)/2; i++ {
		if input[i] != input[len(input)-i-1] {
			return false
		}
	}
	return true
}

func reverse(input string) string {
	r := []rune(input)
	for i, j := 0, len(r)-1; i < len(r)/2; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	return string(r)
}
```

### Submission Detail

```
134 / 134 test cases passed.
Status: Accepted
Runtime: 68 ms
Memory Usage: 6.8 MB
```
