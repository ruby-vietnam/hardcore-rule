#Easy: palindrome-linked-list
https://leetcode.com/problems/palindrome-linked-list/

Submission Details:
```
134 / 134 test cases passed.
Status: Accepted
Runtime: 1756 ms
Memory Usage: 8.6 MB
```

For this problem we use two pointer technique. We have two pointers: slow and fast to find middle of linked list. And we will compare two part of linked list. If reverse of next part equal with first part the linkedlist is palindreme.

we use array to save value of first part and use another array to save value of remain part. We have two case here: if len of linked list is odd remain part will longer than first part 1 element. We need to remove it. After that we compare value first part with reverse of remain part. If they don't have different the linked list is palindrome 

Implementation:

```go
func isPalindrome(head *ListNode) bool {
    if head.Next == nil {
		return  true
	}

	if head.Next.Next == nil {
		if head.Val == head.Next.Val {
			return  true
		} else {
			return  false
		}
	}

	var stack = make([]int, 0)
	slow := head
	fast := head

	for fast != nil && fast.Next != nil {
		stack = append(stack, slow.Val)
		slow = slow.Next
		fast = fast.Next.Next
	}

	part2 := slow

	var stack2 = make([]int, 0)
	for part2 != nil {
		stack2 = append(stack2, part2.Val)
		part2 = part2.Next
	}

	if len(stack) != len(stack2) {
		stack2 = stack2[1:len(stack2)]
	}

	for i := 0; i < len(stack); i++ {
		if stack[i] != stack2[len(stack2) - 1 - i] { return  false }
	}

	return true
}
```

# Medium: Permutation
https://leetcode.com/problems/permutations/

Submission Details:
```
25 / 25 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 2.6 MB
```

use this head algorithm 
https://en.wikipedia.org/wiki/Heap%27s_algorithm


Implementation:

```go
func generatePermuation(n int, numbers []int, result *[][]int) {
	if n == 1 {
		tmp := make([]int, len(numbers))
		copy(tmp, numbers)
		*result = append(*result, tmp)
	} else {
		generatePermuation(n - 1, numbers, result)
		for i := 0; i < n - 1; i++ {
			if n % 2 == 0 {
				numbers[i], numbers[n - 1] = numbers[n - 1], numbers[i]
			} else {
				numbers[0], numbers[n - 1] = numbers[n - 1], numbers[0]
			}
			generatePermuation(n - 1, numbers, result)
		}
	}
}

func permute(nums []int) [][]int {
	result := make([][]int, 0)

	generatePermuation(len(nums), nums, &result)

	return result
}
```

#Hard: palindrome-pairs
https://leetcode.com/problems/palindrome-pairs/

Naive Solution:
we use bruce force, 2 loop , and check pair of word is panlimore or not 


```
134 / 134 test cases passed.
Status: Accepted
Runtime: 1620 ms
Memory Usage: 8.8 MB
```

Implementation:
```go
func isPalindrome(input string) bool {
	for i := 0; i < len(input)/2; i++ {
		if input[i] != input[len(input)-i-1] {
			return false
		}
	}
	return true
}

func palindromePairs(words []string) [][]int {
	result := make([][]int, 0)
	for i := 0; i < len(words) - 1; i++ {
		for j:= i + 1; j < len(words); j++ {
			string1 := words[i] + words[j]
			if isPalindrome(string1) {
				a := []int{i, j}
				result = append(result, a)
			}
			string2 := words[j] + words[i]
			if isPalindrome(string2) {
				a := []int{j, i}
				result = append(result, a)
			}
		}
	}

	return result
}
```

Better solution:
we use trie data structure. we reverse word and add it into trie. After that we find each word in trie if it exited we have pair of palindrome. And if the word is the part of branch of trie. We check the remain part if it is panlidrome, pair of words are palindrome too.

Implementation: in progress.
