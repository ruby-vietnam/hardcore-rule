Problem 1:

```
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
