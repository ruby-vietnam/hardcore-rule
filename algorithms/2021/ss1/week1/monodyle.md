# 1. Palindrome linked list [Easy]

Problem: https://leetcode.com/problems/palindrome-linked-list/

## 1.1. Idea

Use slow and fast method to quickly find a middle node. Slow is the node keep 
going forward to next node, meanwhile fast is double in iteration, until fast's 
node or next node is null (end of linked list). There is odd linked list and 
even linked list so even node will take one more step to make slow go forward.

Now we have 2 part of linked list: the full one and the half one.

![Slow n Fast](https://github.com/monodyle/algorithms-adventure/raw/master/leetcode-problems/234-palindrome-linked-list/slow-n-fast.png)

## 1.2. Step by Step

1. Linked list have 1 node: alway `true`
2. Make a stack to storage the values
3. Iteration fast and slow, store the slow value by apped to stack
4. Slow pointer keep going forward to compare to last stack item, if they 
difference, break and the result is `false`
5. When no item left on stack, return `true`

## 1.3. Example

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func isPalindrome(head *ListNode) bool {
	if head.Next == nil {
		return true
	}

	slow, fast := head, head
	stack := []int{}

	for fast != nil && fast.Next != nil {
		stack = append(stack, slow.Val)
		slow = slow.Next
		fast = fast.Next.Next
	}

	if fast != nil {
		slow = slow.Next
	}

	for slow != nil {
		if slow.Val != stack[len(stack)-1] {
			return false
		}
		slow = slow.Next
		stack = stack[:len(stack)-1]
	}

	return true
}

func (list *ListNode) print() {
	if list == nil {
		fmt.Print("NULL")
		return
	}
	fmt.Printf("%v -> ", list.Val)
	list.Next.print()
}
```

# 1.4. Submission detail

```
85 / 85 test cases passed.
Status: Accepted
Runtime: 168 ms
Memory Usage: 13.4 MB
```

# 2. Permutations [Medium]

Problem: https://leetcode.com/problems/permutations/

# 2.1. Idea

Backtracking. Just traverse the tree from root to leaves and record the numbers 
on the paths, and we will gget all the permutations.

Example: The tree start with [ ] node (root) and have 3 branches: [1], [2], [3]. 
Pick up branch [1], the lost number is `2` and `3`, so the child branches are 
them. Keep pick up branch [2], the lost number from root to this node is 3, so 
it is. No more lost number, [3] is leaf, we have [1, 2, 3]. Keep going with 
other branches which lost some number.

# 2.2. Step by Step

Permute make a backtrack with init numbers.

Backtrack take left number(s), previous nodes for each number left from previous 
backtrack. If there no number left, return result.

# 2.3. Example

```go
func permute(nums []int) [][]int {
	if len(nums) == 0 {
		return nil
	}

	result := make([][]int, 0)
	backtrack(nums, []int{}, &result)
	return result
}

func backtrack(nums []int, prev []int, result *[][]int) {
	if len(nums) == 0 {
		*result = append(*result, prev)
		return
	}

	for i, num := range nums {
		backtrack(
			append(
				append([]int{}, nums[:i]...),
				nums[i+1:]...,
			),
			append(prev, num),
			result,
		)
	}
}
```

# 2.4. Submission detail

```
25 / 25 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 2.7 MB
```
