# Week 1

## Problem 1
https://leetcode.com/problems/palindrome-linked-list/

### Approach 1
Use a list to store all values in the linked list and check palindrome by checking the value list.
We can reduce the space to n/2 by using stack.

Analysis: time complexity: O(n), and space complexity: O(n)

### Aproach 2
In order to check palindrome, single linked list is harder compare to simple list because single linked list can not go back to its previous node.
So to overcome this, we can reverse half of the linked list and check palindrome between two halves,
then reverse the reversed half back to original linked list.

Analysis: time complexity: O(n), space complexity: O(1)

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func isPalindrome(head *ListNode) bool {
    // Early exit
    if head.Next == nil {
        return true
    }
    if head.Next.Next == nil {
        return head.Val == head.Next.Val
    }
    
    // Find tail of first half and head of second half by running two pointers fast & slow
    slow, fast := head, head.Next
    for fast.Next != nil && fast.Next.Next != nil {
        slow, fast = slow.Next, fast.Next.Next
    }
    // If fast.Next is not nil => n is odd, head of second half is 1 node away from slow,
    // else n is even, head of second half is right next to slow
    head_second := slow.Next
    if fast.Next != nil {
        head_second = slow.Next.Next
    }
    tail_one := slow
    
    // Reverse the first half
    it := head
    for head != tail_one {
        temp := it.Next
        head, temp.Next, it.Next = temp, head, temp.Next
    }
    // Keep original head to reverse back later
    originalHead := it
    
    // Check palindrome
    result := true
    it1, it2 := head, head_second
    for it2 != nil {
        if it1.Val != it2.Val {
            result = false
            break
        }
        it1, it2 = it1.Next, it2.Next
    }
    
    // Reverse back to original linkedlist
    it = head
    for head != originalHead {
        temp := it.Next
        head, temp.Next, it.Next = temp, head, temp.Next
    }
    
    return result
}
```
```
Runtime: 180 ms, faster than 21.09% of Go online submissions for Palindrome Linked List.
Memory Usage: 11.1 MB, less than 46.70% of Go online submissions for Palindrome Linked List.
```
(I tried Python3 with runtime 956ms and 47.4MB -> Go reduces quite lot of runtime and memory)

## Problem 2
https://leetcode.com/problems/permutations/

There are n! permutations.

How: select any number in the array, find all permuation of remaining numbers, then concat with the selected number.

Example: [1,2,3]

```
    Select 1: remaining numbers are [2,3]:
        Select 2 -> remaining numbers are [3] -> only one permutation is [3]
            combine with selected number 2, we have permutation: [2,3]
        Select 3 -> remaining numbers are [2] -> only one permutation is [2]
            combine with selected number 3, we have permutations: [3,2]
        combine with selected number 1, we have [1,2,3], [1,3,2]
    ....
```

Analysis: time complexity: O(n!), space complexity: O(n!) n! for storing permuations and n for stack in recursive calls.

```go
func permute(nums []int) [][]int {
    var result [][]int
    p := make([]int, len(nums))
    return permuteRecur(nums, 0, p, result)
}

func permuteRecur(nums []int, i int, p []int, result [][]int) [][]int {
    // Base case, run out of number, append permuatation to final result
    if i == len(nums) {
        cp := make([]int, len(nums))
        copy(cp, p)
        return append(result, cp)
    }
    
    // Select a number from nums[i:len(nums)] as leading number and find permuations for nums[i+1:len(nums)]
    for j := i; j < len(nums); j++ {
        // Swap value between i and j
        nums[i], nums[j] = nums[j], nums[i]
        // Call recursive for i+1
        p[i] = nums[i]
        result = permuteRecur(nums, i+1, p, result)
        // Swap value back
        nums[i], nums[j] = nums[j], nums[i]
    }
    return result
}
```
```
Runtime: 0 ms, faster than 100.00% of Go online submissions for Permutations.
Memory Usage: 2.6 MB, less than 98.70% of Go online submissions for Permutations.
```

## Problem 3
https://leetcode.com/problems/palindrome-pairs/

### Approach 1
We can generate all pairs and check palindrome for each pair.

Analysis: time complexity O(n^2 * m), space complexity: O(n^2), with m is max length of word.

```go
func palindromePairs(words []string) [][]int {
    // Check palindrome of a word
    isPalindrome := func(word string) bool {
        for i := 0; i < len(word)/2; i++ {
            if word[i] != word[len(word)-i-1] {
                return false
            }
        }
        return true
    }
    
    // Generate all pairs and check if current pair is palindrome then append to result
    var result [][]int
    for i := 0; i < len(words)-1; i++ {
        for j := i+1; j < len(words); j++ {
            if isPalindrome(words[i] + words[j]) {
                result = append(result, []int{i, j})
            }
            if isPalindrome(words[j] + words[i]) {
                result = append(result, []int{j, i})
            }
        }
    }
    
    return result
}
```
```
Runtime: 3008 ms, faster than 5.88% of Go online submissions for Palindrome Pairs.
Memory Usage: 12 MB, less than 5.88% of Go online submissions for Palindrome Pairs.
```

### Approach 2
The best possible time complexity is O(n\*m). Is there any data structures can help us reduce time complexity to O(n\*m)?

Let's try using Trie.

```
1. Generate a nornal Trie, each node record index of words that end here and their remaning.
2. Check palindrome of a word by using its reversed word. There are 3 possiblities happen on the path from root down to ending node.
    2.1 If current node is ending node of some words (current word is right part of palindrome, which have longer length), this might be a palindrome if remaning of curent word is palindrome.
    2.2 If ending node of current word is also ending character of other words, then two words (same length) combined into a palindrome.
    2.3 If current word's ending node is prefix of other words (current word is right part of palindrome, which have shorter length), this might be a palindrome if remaining of other words is palindrome.
```


```go
const ALBHABET_SIZE = 26

type trieNode struct {
    childrens [ALBHABET_SIZE]*trieNode
    rem map[int]string  // Store remaining of word from this node
    isWordEnd []int  // If this node is ending node of what word
}

type trie struct {
    root *trieNode
    vocabSize int
}

func initTrie(n int) *trie {
    return &trie{
        root: &trieNode{
            rem: make(map[int]string),
            isWordEnd: make([]int, n),
        },
        vocabSize: n,
    }
}

func (t *trie) insert(word string, i int) {
    // Handle empty word
    if len(word) == 0 {
        t.root.isWordEnd[i] = 1
        return
    }
    
    current := t.root
    for j := 0; j < len(word); j++ {
        index := word[j] - 'a'
        if current.childrens[index] == nil {
            current.childrens[index] = &trieNode{
                rem: make(map[int]string),
                isWordEnd: make([]int, t.vocabSize),
            }
        }
        current.rem[i] = word[j:]
        current = current.childrens[index]
    }
    current.isWordEnd[i] = 1
}

func (t *trie) findPalindromes(word string, i int) [][]int {
    var res [][]int
    
    isPalindrome := func(word string) bool {
        for i := 0; i < len(word)/2; i++ {
            if word[i] != word[len(word)-i-1] {
                return false
            }
        }
        return true
    }

    current := t.root
    // Process root (in case empty word)
    for k := 0; k < len(current.isWordEnd); k++ {
        if current.isWordEnd[k] == 1 && k != i {
            if isPalindrome(word) {
                res = append(res, []int{k, i})
            }
        }
    }
    // Process on children
    for j := len(word)-1; j >= 0; j-- {
        index := word[j] - 'a'

        if current.childrens[index] == nil {
            // There are no palindromes on this path, just return all we got
           return res
        }
        
        // Check if this node is ending node of any words => current word's length >= ending word's length
        // If yes, then check the remaining of current word to see if it's palindrome
        current = current.childrens[index]
        for k := 0; k < len(current.isWordEnd); k++ {
            if current.isWordEnd[k] == 1 && k != i {
                if isPalindrome(word[:j]) {
                    res = append(res, []int{k, i})
                }
            }
        }
    }
    // Check other words has greater length than current word's
    for idx, word_rem := range current.rem {
        if isPalindrome(word_rem) {
            res = append(res, []int{idx, i})
        }
    }
    
    return res
}

func palindromePairs(words []string) [][]int {
    // Build trie data
    t := initTrie(len(words))
    for i, word := range words {
        t.insert(word, i)
    }

    // Find palindromes
    var result [][]int 
    for i, word := range words {
        result = append(result, t.findPalindromes(word, i)...)
    }
    return result
}
```
```
Runtime: 992 ms, faster than 38.24% of Go online submissions for Palindrome Pairs.
Memory Usage: 252.7 MB, less than 5.88% of Go online submissions for Palindrome Pairs.
``` 
Still not good enough, initial idea is good but gradually complexity adds up duing implementation so overall time complexity is huge.

### Aproach 3 (does not work)
We use hash to reduce palindrome time checking, the approach is somehow similar to Rabin-Karp algorithm.

If a word is palindrome then its hash value equals to hash value of reversed word: `hash(word) == hash(reverse(word))`.

Unfortunately, this approach does not work for long word because hash value is too large (`0 <= words[i].length <= 300`), leads to overflowed `int` type.

Example of overflowed hash: ["bbbbbbbabbabbbbbb", "b"]

```go
func palindromePairs(words []string) [][]int {
    const alphabet = 26
    
    // Create hash or words and hash of reversed word
    hash := make(map[int]int64)
    rhash := make(map[int]int64)
    for i, word := range words {
        var h int64
        for j := 0; j < len(word); j++ {
            h = alphabet * h + int64(word[j] - 'a' + 1)
        }
        hash[i] = h
        
        var rh int64
        for j := len(word)-1; j >= 0; j-- {
            rh = alphabet * rh + int64(word[j] - 'a' + 1)
        }
        rhash[i] = rh
    }
    
    // Check if combined word is palindrome by compare hash of combined word and its reversed one
    cmpHash := func(i, j int) bool {
        normal := hash[i] * int64(math.Pow(float64(alphabet), float64(len(words[j])))) + hash[j]
        reversed := rhash[j] * int64(math.Pow(float64(alphabet), float64(len(words[i])))) + rhash[i]
        return normal == reversed
    }
    
    isPalindrome := func(word string) bool {
        for i := 0; i < len(word)/2; i++ {
            if word[i] != word[len(word)-i-1] {
                return false
            }
        }
        return true
    }
    
    var result [][]int
    for i := 0; i < len(words)-1; i++ {
        for j := i+1; j < len(words); j++ {
            // Check word: word[i] + word[j]
            if cmpHash(i, j) && isPalindrome(words[i] + words[j]) {
                    result = append(result, []int{i, j})
            }
            // Check word: word[j] + word[i]
            if cmpHash(j, i) && isPalindrome(words[j] + words[i]) {
                result = append(result, []int{j, i})
            }   
        }
    }
    
    return result
}
```

### Approach 4
This approach is a bit similar to approach 3 by examining part of word is palindrome, but does not rely on Trie.

For each word, we separate into two parts: s1, s2
1. If s1 is palindrome, then s1 is in the middle, s2 is the left part, we check if there any word that equals to reverse(s2) for the left part, they must form a palindrome.
2. If s2 is palindrome, then se is in the middle, s1 is the left part, as in step 1, we find any words that equals to reverse(s1) for the right part.

Example: ["lls", "s"]
```
Split "lls" into s1("ll") and s2("s")
s1 is a palindrome, we check the revese(s2) = "s" == word[1] => (1,0) is a palindrome
```

Analysis: time complexity O(n*m^2), space complexity O(n!)

```go
func palindromePairs(words []string) [][]int {
    isPalindrome := func(word string) bool {
        for i := 0; i < len(word)/2; i++ {
            if word[i] != word[len(word)-i-1] {
                return false
            }
        }
        return true
    }
    
    reverse := func(s string) string {
        n := len(s)
        runes := make([]rune, n)
        for _, rune := range s {
            n--
            runes[n] = rune
        }
        return string(runes[n:])
    }
    
    // Create a map of word -> index
    m := make(map[string]int)
    for i, w := range words {
        m[w] = i
    }
    
    var result [][]int
    for i, w := range words {
        for j := 0; j <= len(w); j++ {
            s1, s2 := w[0:j], w[j:]
            
            // If s1 is palindrome, then s1 is in the middle of a palindrome,
            // s2 will be right part, we look for left part that is reversed of s2
            if isPalindrome(s1) {
                rs2 := reverse(s2)
                if idx, ok := m[rs2]; ok && idx != i {
                    result = append(result, []int{idx, i})
                }
            }
            
            // If s2 is palindrome, then s2 is in the middle of a palindrome,
            // s1 will be left part, we look for right part that is reversed of s1
            if isPalindrome(s2) && len(s2) != 0 {
                rs1 := reverse(s1)
                if idx, ok := m[rs1]; ok && idx != i {
                    result = append(result, []int{i, idx})
                }
            }
        }
    }
    
    return result
}
```
```
Runtime: 72 ms, faster than 78.38% of Go online submissions for Palindrome Pairs.
Memory Usage: 6.9 MB, less than 67.57% of Go online submissions for Palindrome Pairs.
```
