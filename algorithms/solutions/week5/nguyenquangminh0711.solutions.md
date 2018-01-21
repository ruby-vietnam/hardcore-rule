# Problem 2
*Accepted*
The algorithm is straight forward. The assumption is that the `*` represents
empty string character until we need them for `rescue` the bad situation.

Run from left to right, if the current character is `(`, increase the number
of pairs; if the current character is `)`, decrease the numer of pairs; otherwise,
increase the number of remaining. If the number of pairs is less than `0`, which
means that the number of `)` character is more than the number of `(`. In this
case, if there is any `*` left to rescue, we are safe to continue.

However, run left to right doesn't satisfy ending `(` cases. Therefore, we need
to check two tinmes: left to right and right to left.

```golang
func checkValidString(s string) bool {
	return check(s, 1) && check(s, -1)
}

func check(s string, delta int) bool {
	pair := 0
	life := 0

	i := 0
	if delta < 0 {
		i = len(s) - 1
	}

	for i >= 0 && i < len(s) {
		char := s[i]
		if char == '(' {
			pair += delta
		} else if char == ')' {
			pair -= delta
		} else {
			life++
		}
		if pair < 0 {
			if life > 0 {
				pair = 0
				life--
			} else {
				return false
			}
		}
		i += delta
	}
	return life >= pair
}
```

# Problem 3
*Accepted*
Choose from 2 dimention is hard. Therefore, we must enforce the order of one
dimention, and find the longest possible envelope chain in the other. Classic DP
problem. For the naive implementation, it tooks `O(N^2)`. We could improve this
by using BIT at the second step.

```golang
func maxEnvelopes(envelopes [][]int) int {
	rand.Seed(1235135)
	sortEnvelopes(envelopes, 0, len(envelopes)-1)
	var L = make([]int, len(envelopes))
	result := 0
	for i := 0; i < len(envelopes); i++ {
		L[i] = 1
		lmax := 1
		for j := i - 1; j >= 0; j-- {
			if canContain(envelopes[i], envelopes[j]) && lmax < L[j]+1 {
				lmax = L[j] + 1
			}
		}
		L[i] = lmax
		if lmax > result {
			result = lmax
		}
	}

	return result
}

func sortEnvelopes(envelopes [][]int, start int, end int) {
	if start >= end {
		return
	}

	i := start
	j := end
	pivot := envelopes[rand.Intn(end-start)+start]
	for i <= j {
		for smaller(envelopes[i], pivot) {
			i++
		}
		for bigger(envelopes[j], pivot) {
			j--
		}
		if i <= j {
			tmp := envelopes[i]
			envelopes[i] = envelopes[j]
			envelopes[j] = tmp
			i++
			j--
		}
	}

	sortEnvelopes(envelopes, start, j)
	sortEnvelopes(envelopes, i, end)
}

func smaller(a []int, b []int) bool {
	if a[0] < b[0] {
		return true
	} else if a[0] == b[0] {
		return a[1] < b[1]
	}
	return false
}

func bigger(a []int, b []int) bool {
	if a[0] > b[0] {
		return true
	} else if a[0] == b[0] {
		return a[1] > b[1]
	}
	return false
}

func canContain(a []int, b []int) bool {
	return a[0] > b[0] && a[1] > b[1]
}
```

# Problem bonus
An variant of Trie data structure. It is lucky that the `.` character presents a
fixed character, not wildcard. Therefore, when conduting a search operation, we
use a queue to store the possible path. At a step, if the current character is
`.`, push all child nodes of each node in the previous queue into a new queue;
otherwise, just push the matched character.

```golang
type node struct {
	value    bool
	children map[rune]*node
}

type WordDictionary struct {
	root *node
}

/** Initialize your data structure here. */
func Constructor() WordDictionary {
	return WordDictionary{
		root: &node{
			value:    false,
			children: make(map[rune]*node),
		},
	}
}

/** Adds a word into the data structure. */
func (dict *WordDictionary) AddWord(word string) {
	n := dict.root
	for _, char := range word {
		child, exists := n.children[char]
		if exists {
			n = child
		} else {
			n.children[char] = &node{
				value:    false,
				children: make(map[rune]*node),
			}
			n = n.children[char]
		}
	}
	n.value = true
}

/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
func (dict *WordDictionary) Search(word string) bool {
	queue := []*node{dict.root}
	for _, char := range word {
		q := []*node{}
		for _, n := range queue {
			if char == '.' {
				for _, child := range n.children {
					q = append(q, child)
				}
			} else {
				child, exists := n.children[char]
				if exists {
					q = append(q, child)
				}
			}
		}
		queue = q
		if len(queue) == 0 {
			return false
		}
	}
	exists := false
	for _, n := range queue {
		exists = exists || n.value
	}
	return exists
}
```

