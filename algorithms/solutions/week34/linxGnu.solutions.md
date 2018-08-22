## Problem 1 - [House Robber](https://leetcode.com/problems/house-robber/description/)

```go
func rob(nums []int) int {
    if len(nums) == 0 {
        return 0
    }
    
    tmp, max := 0, 0
    for i := range nums {
        if i >= 2 {
            if tmp = nums[i-2]; i >= 3 && nums[i-3] > tmp {
                tmp = nums[i-3]
            }
            nums[i] += tmp
        } 
        
        if max < nums[i] {
            max = nums[i]
        }
    }
    
    return max
}
```

## Problem 2 - [Word Break](https://leetcode.com/problems/word-break/description/)

```go
func wordBreak(s string, wordDict []string) bool {
    root := &trie{}
    for i := range wordDict {
        root.add(wordDict[i])
    }
    
    flag := make([]bool, len(s))
    
    for i := len(s) - 1; i >= 0; i-- {
        currentTrie := root
        for j := i; j < len(s); j++ {
            if currentTrie = currentTrie.moveTo(s[j]); currentTrie != nil {
                
                if currentTrie.isWord && (j + 1 == len(s) || flag[j + 1]) {
                    flag[i] = true
                    break
                }
                
            } else {
                break
            }
        }
    }
    
    return flag[0]
}

type trie struct {
    isWord bool
    next map[byte]*trie
}

func (c *trie) add(word string) {
    if len(word) == 0 {
        return
    }
    
    currentNode := c
    for i := range word {
        if currentNode.next == nil {
            currentNode.next = make(map[byte]*trie)
        }
        
        if tmp, ok := currentNode.next[word[i]]; !ok {
            tmp = &trie{}
            currentNode.next[word[i]] = tmp
            currentNode = tmp
        } else {
            currentNode = tmp
        }
    }
    
    currentNode.isWord = true
}

func (c *trie) moveTo(ch byte) *trie {
    if c.next == nil {
        return nil
    }
    return c.next[ch]
}
```

## Problem 3 - [Task Scheduler](https://leetcode.com/problems/task-scheduler/description/)

```go
func leastInterval(tasks []byte, n int) int {
    if n == 0 {
        return len(tasks)
    }
    
    // counting
    counter := make([]int, 30)
    for i := range tasks {
        counter[tasks[i] - 'A']++
    }
    
    max := 0
    for _, c := range counter {
        if max < c {
            max = c
        }
    }
    
    idles := (max - 1) * (n + 1)
    for _, c := range counter {
        if max - 1 < c {
            idles -= max - 1
        } else {
            idles -= c
        }
    }
    
    if idles > 0 {
        return len(tasks) + idles
    }
    return len(tasks)
}
```

## Problem 4 - [Longest Valid Parentheses](https://leetcode.com/problems/longest-valid-parentheses/description/)

```go
func longestValidParentheses(s string) int {
    n := len(s)
    if n <= 0 {
        return 0
    }
    
    stack, stackCount, start, max := make([]int, n), 0, -1, 0
    for i := range s {
        if s[i] == 41 {
            if stackCount == 0 {
                start = -1
                continue
            }
            
            if stackCount == 1 {
                if tmp := i - start + 1; tmp > max {
                    max = tmp
                }
            } else if tmp := i - stack[stackCount - 2]; tmp > max {
              max = tmp
            }
            
            stackCount--
        } else {
            stack[stackCount] = i
            stackCount++
            
            if stackCount == 1 && start == -1 {
                start = i
            }
        }
    }
    
    return max
}
```