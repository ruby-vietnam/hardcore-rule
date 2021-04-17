# 1. Permutations

https://leetcode.com/problems/permutations/

## 1.1. Summary
 - Based on backtracking (https://en.wikipedia.org/wiki/Backtracking)
 - Two solutions:
	 - Build tree then collect results.
	 - Swap elements.

## 1.2. Tree
- Use elements as a root node of a tree, remaining elements are building the branches and leafs.
- With each remaining elements of a tree, attach it to root element to have branches.
- Each branches continue to use remaining elements (after remove root and first branch) to build until out of remaining elements.
 - Collect all leafs of the trees as result of permutations.

![enter image description here](https://raw.githubusercontent.com/ledongthuc/notes/master/leetcode/permutations/Permutations-build%20tree%20%28step%29.png)
![enter image description here](https://raw.githubusercontent.com/ledongthuc/notes/master/leetcode/permutations/Permutations-build%20tree%20%28full%29.png)

## 1.3. Tree - example:

Following solution, you can combine step "build tree" and "harvest leaves" to once for performance trick.
But It's not fun with me, so let's put them seperatedly for single responsibility.

```
func permute(nums []int) [][]int {
    root := &Node{ Value: []int{}}
    buildTree(root, nums)
    return harvest(root)
}

type Node struct {
    Children []*Node
    Value []int
}

func (n *Node) composeBranchValue(value int) []int {
    branchValue := make([]int, len(n.Value))
    copy(branchValue, n.Value)
    return append(branchValue, value)
}

func buildTree(parent *Node, branchValues []int) {
    if len(branchValues) == 0 {
        return
    }
    
    for index := range branchValues {
        remaning, branchValue := cut(branchValues, index)
        
        child := &Node{Value: parent.composeBranchValue(branchValue)}
        parent.Children = append(parent.Children, child)
        
        buildTree(child, remaning)
    }
}

func harvest(n *Node) (leaves [][]int) {
    if len(n.Children) == 0 {
        return [][]int{n.Value}
    }
    
    for _, child := range n.Children {
        leaves = append(leaves, harvest(child)...)
    }
    
    return leaves
}

func cut(arr []int, index int) (remainingArr []int, item int) {
    item  = arr[index]
    remainingArr = append([]int{}, arr[:index]...)
    return append(remainingArr, arr[index+1:]...), item
}
```

![Screen Shot 2021-04-15 at 21 41 15](https://user-images.githubusercontent.com/1828895/114929488-24ee0a00-9e34-11eb-9ce5-2f449bbceffa.png)

## 1.4. Swap elements
 - Swap first element with remaining elements.
 - Lock first element and continue swapping remaining parts.
 - Continue swapping until we don't have remianing elements.
 - Collect all cases as result of permutations.

![enter image description here](https://raw.githubusercontent.com/ledongthuc/notes/master/leetcode/permutations/Permutations-swap.png)

## 1.5. Swap elements - example 1

Old solution that I don't remember when I did it. But I don't like it, so re-implement it with example 2

```
func permute(nums []int) [][]int {
    return permuteP([][]int{[]int{}}, nums) 
}

func permuteP(current [][]int, rest []int) (result [][]int) {
    if len(rest) == 0 {
        return current
    }
    for cIndex, _ := range current {
        for rIndex, _ := range rest {
            temp := append(current[cIndex], rest[rIndex])
            newRest := append([]int{}, rest[:rIndex]...)
            newRest = append(newRest, rest[rIndex+1:]...)
            result = append(result, permuteP([][]int{temp}, newRest)...)
        }
    }
    
    return result
}
```

## 1.6. Swap elements - example 2

```
func permute(nums []int) [][]int {
    return permuteR([]int{}, nums)
}

func permuteR(lockedArr []int, remainingArr []int)  [][]int {
    if len(remainingArr) == 0 {
        return [][]int{lockedArr}
    }
    
    result := [][]int{}
    for lockIndex := 0; lockIndex < len(remainingArr); lockIndex++ {
        lockedItem, remainingArr := lockItem(remainingArr, lockIndex)
        newLockedArr := newLockedItem(lockedArr, lockedItem)
        result = append(result, permuteR(newLockedArr, remainingArr)...)
    }
    return result
}

func lockItem(arr []int, lockIndex int) (lockedItem int, remainingArr []int) {
    lockedItem  = arr[lockIndex]
    remainingArr = append([]int{}, arr[:lockIndex]...)
    return lockedItem, append(remainingArr, arr[lockIndex+1:]...)
}

func newLockedItem(arr []int, lockedItem int) []int {
    return append(append([]int{}, arr...), lockedItem)
}
```

![Screen Shot 2021-04-15 at 20 20 59](https://user-images.githubusercontent.com/1828895/114929540-3505e980-9e34-11eb-8cbb-e64f70e1dd01.png)

# 2. Palindrome Linked List

Given the head of a singly linked list, return true if it is a palindrome.
Constraints:
 - The number of nodes in the list is in the range [1, 105].
 - 0 <= Node.val <= 9

## 2.1. Summary

We split the problem to 3 smaller problems:
 - Find middle point of linked list.
 - Reverse 2nd part of linked list.
 - Compare 1st part and reversed 2nd part of linked list.

## 2.2. Find middle point of linked list

 - Use 2 pointers;
 - First pointer jumps 2 element, Second pointer jump 1 element.
 - Result of this step, we can split the linked list to 2 parts.

![enter image description here](https://raw.githubusercontent.com/ledongthuc/notes/master/leetcode/palindrome-linked-list/palindrome_linked_list-Detect%20middle.png)
- Complexity: O(n)
- Space: O(2)

## 2.3. Reverse half part of linked list

Reverse half part of linked list
 - Use 3 pointers
 - First pointer points to current processing element.
 - Second pointer point to the next item of element that's pointed by first pointer.
 - Third pointer use to point to next item of element that's pointed by second pointer, temporary, during swapping between elements.
 - Swap actions:
	 - Third pointer point to next element of element that's pointed by second pointer.
	 - First pointer element remove the link.
	 - Second pointer element update next link to element that's pointed by first pointer.
	 - First pointer points to second pointer element, second pointer points to third pointer element.
	 - Release third pointer.
- Swap until end of the parse, we have a reversed half part linked list

![enter image description here](https://raw.githubusercontent.com/ledongthuc/notes/master/leetcode/palindrome-linked-list/palindrome_linked_list-Reverse%202nd%20part.png)
 - Complexity: O(n/2)
 - Space: O(3)

## 2.4. Compare 2 parts

 - Compare reversed part and remaining part of linked list
 - Use two pointers.
 - Each pointer keep a current checking item of two parts.
 - Loop through item and compare their value.
 - If they of the same value, then it's a palindrome linked list.

![enter image description here](https://raw.githubusercontent.com/ledongthuc/notes/master/leetcode/palindrome-linked-list/palindrome_linked_list-Compare%202%20linked%20list.png)

## 2.5. Total
 - Complexity: O(2n)
 - Space: O(7)

## 2.6. Example

```
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func isPalindrome(head *ListNode) bool {
    if head == nil || head.Next == nil {
        return true
    }
    second := splitLinkedList(head)
    reversedSecond := reverseLinkedList(second)
    return compareLinkedLists(head, reversedSecond)
}

func splitLinkedList(head *ListNode) (second *ListNode) {
    if head == nil || head.Next == nil {
        return head
    }
    current := head
    half := head
    for {
        // Even
        if current.Next == nil {
            second = half.Next
            return second
        }
        // Odd
        if current.Next.Next == nil {
            second = half.Next
            return second
        }
        current = current.Next.Next
        half = half.Next
    }
    return half.Next
}

func reverseLinkedList(head *ListNode) (*ListNode) {
    if head.Next == nil {
        return head
    }
    current := head
    next := head.Next
    head.Next = nil
    var tmp *ListNode
    for {
        tmp = next.Next
        next.Next = current
        current = next
        next = tmp
        if next == nil {
            break
        }
    }
    return current
}

func compareLinkedLists(first, second *ListNode) bool {
    for second != nil {
        if first == nil && second == nil {
            return true
        }
        if first == nil || second == nil || first.Val != second.Val {
            return false
        }
        first = first.Next
        second = second.Next
    }
    return true
}
```

![Screen Shot 2021-04-15 at 20 04 51](https://user-images.githubusercontent.com/1828895/114929579-418a4200-9e34-11eb-9fe6-6407f6beb250.png)
