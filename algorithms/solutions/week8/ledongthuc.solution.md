Problem 1:

```go
func longestWord(words []string) string {
	if words == nil || len(words) == 0 {
		return ""
	}

	trie := NewTrie()
	for _, s := range words {
		trie.AddString(s)
	}
	return trie.Root.GetLongestWord()
}

type Trie struct {
	Root            *TrieNode
}

type TrieNode struct {
	Children         map[rune]*TrieNode
	IsPredefinedWord bool
}

func NewTrie() Trie {
	return Trie{
		Root: &TrieNode{
			Children: make(map[rune]*TrieNode),
		},
	}
}

func (t *Trie) AddString(text string) {
	currentNode := t.Root
	for _, c := range text {
		if searchNode, ok := currentNode.Children[c]; ok {
			currentNode = searchNode
		} else {
			newNode := &TrieNode{
				Children: make(map[rune]*TrieNode),
			}
			currentNode.Children[c] = newNode
			currentNode = newNode
		}
	}
	currentNode.IsPredefinedWord = true
}

func (t *TrieNode) GetLongestWord() string {
	var max string
	for c, node := range t.Children {
		if !node.IsPredefinedWord {
			continue
		}
		maxOfChildren := string(c) + node.GetLongestWord()
		if len(maxOfChildren) > len(max) || (len(maxOfChildren) == len(max) && maxOfChildren < max) {
			max = maxOfChildren
		}
	}
	return max
}
```

Problem 2:

```go

type MyCalendarThree struct {
	Timeline []int
	Counting map[int]int
}

func Constructor() MyCalendarThree {
	return MyCalendarThree{
		Counting: make(map[int]int),
	}
}

func (this *MyCalendarThree) Book(start int, end int) int {
	if counting, ok := this.Counting[start]; ok {
		this.Counting[start] = counting + 1
	} else {
		this.Timeline = OrderedInsert(this.Timeline, start)
		this.Counting[start] = 1
	}

	if counting, ok := this.Counting[end]; ok {
		this.Counting[end] = counting - 1
	} else {
		this.Timeline = OrderedInsert(this.Timeline, end)
		this.Counting[end] = -1
	}

	// sort.Ints(this.Timeline)

	max := 0
	currentCount := 0
	for _, t := range this.Timeline {
		currentCount += this.Counting[t]
		if currentCount > max {
			max = currentCount
		}
	}

	return max
}

func OrderedInsert(list []int, item int) []int {
	if len(list) == 0 {
		return []int{item}
	}

	isInserted := false
	result := make([]int, 0, len(list)+1)
	for _, t := range list {
		if t > item && isInserted == false {
			result = append(result, item)
			isInserted = true
		}
		result = append(result, t)
	}

	if isInserted == false {
		result = append(result, item)
	}
	return result
}

```
