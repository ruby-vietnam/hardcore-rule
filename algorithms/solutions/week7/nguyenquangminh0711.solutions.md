## Problem 1

https://leetcode.com/problems/first-unique-character-in-a-string/description/

Use a hash map to count the apperance of a letter.

```golang
func firstUniqChar(s string) int {
    flags := make(map[rune]int);
    for _, char := range s {
        flags[char]++
    }
    for index, char := range s {
        if flags[char] == 1 {
            return index;
        }
    }
    return -1;
}
```

## Problem 2

https://leetcode.com/problems/symmetric-tree/description/

A tree is symmetric if all nodes of it are symmetric, starting from root. 
Two nodes A and B are considered to be symmetric if and only if A's value == B's value and A's left branch is symmetric with B's right branch and vice vera.

```golang
func isSymmetric(root *TreeNode) bool {
    if root == nil {
        return true
    } else {
        return symmetricCheck(root.Left, root.Right);   
    }
}

func symmetricCheck(left *TreeNode, right *TreeNode) bool {
    if left == nil && right == nil {
        return true
    } else if left != nil && right != nil {
        return left.Val == right.Val && symmetricCheck(left.Left, right.Right) && symmetricCheck(left.Right, right.Left)
    } else {
        return false
    }
}

func isLeaf(node *TreeNode) bool {
    return node.Left == nil && node.Right == nil
}
```

## Problem bonus 2

https://leetcode.com/problems/insert-delete-getrandom-o1/description/

Use a list to store all values. A hash map to map from key to the position on the list. 
When we remove an item, swap it with the ending value in the list and update the hash

```golang
type RandomizedSet struct {
	hash map[int]int
	list []int
}

/** Initialize your data structure here. */
func Constructor() RandomizedSet {
	rand.Seed(time.Now().UTC().UnixNano())
	return RandomizedSet{
		hash: make(map[int]int),
	}
}

/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
func (set *RandomizedSet) Insert(val int) bool {
	_, exist := set.hash[val]
	if exist {
		return false
	}
	set.hash[val] = len(set.list)
	set.list = append(set.list, val)
	return true
}

/** Removes a value from the set. Returns true if the set contained the specified element. */
func (set *RandomizedSet) Remove(val int) bool {
	_, exist := set.hash[val]
	if !exist {
		return false
	}
	pos := set.hash[val]
	if pos != len(set.list)-1 {
		tmp := set.list[pos]
		set.list[pos] = set.list[len(set.list)-1]
		set.hash[set.list[pos]] = pos
		set.list[len(set.list)-1] = tmp
	}
	set.list = set.list[:len(set.list)-1]
	delete(set.hash, val)
	return true
}

/** Get a random element from the set. */
func (set *RandomizedSet) GetRandom() int {
	fmt.Println("Length: ", len(set.list))
	fmt.Println("Random: ", rand.Intn(len(set.list)))
	return set.list[rand.Intn(len(set.list))]
}
```
