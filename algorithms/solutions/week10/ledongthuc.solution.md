### Problem 1: 

https://leetcode.com/problems/valid-palindrome-ii/
Time: 32ms
Complexity: O(n)

Solution is the same with Palindrome checking with some change.
When you got a invalid pair character, we have 2 cases, 
  1. the left one is removable character
  2. the right one is removable character

=> just loop over the string 2 twice and skip left/right removable character and make sure the string are a palindrome.
  
  
```go
func validPalindrome(s string) bool {
    if len(s) == 0 {
        return true
    }

    left, right, count := 0, len(s) - 1, 0
    for left < right && count <= 1 {
        if s[left] != s[right] {
            count++
            left++
        } else {
            left++
            right--
        }
    }

    if count < 2 {
        return true
    }

    left, right, count = 0, len(s) - 1, 0
    for left < right  && count <= 2 {
        if s[left] != s[right] {
            count++
            right--
        } else {
            left++
            right--
        }
    }

    return count < 2
}
```

### Problem 2:

Time: 8ms
Complexity: O(n)

Solution is using depth first search in binary tree. Main idea, we append right branch to end of left branch and move left branch (including new appended right branch) to right of node (replace current right branch).


![](https://preview.ibb.co/bVg5Vx/1.png)

Ex-cases:
 - If left of node don't have any branch, just keep the node
 - If right of node don't have any branch, move left branch to right of node.

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func flatten(root *TreeNode)  {
    if root == nil {
        return
    }
    
    DigAndAppend(root)
}

func  DigAndAppend(node *TreeNode) (*TreeNode) {
    if node.Left == nil && node.Right == nil {
        return node
    }
    
    if node.Left == nil && node.Right != nil {
        return DigAndAppend(node.Right)
    }
    
    lastLeft := DigAndAppend(node.Left)
    lastLeft.Right = node.Right
    node.Right = node.Left
    node.Left = nil
    if node.Right == nil {
        return lastLeft
    }
    return DigAndAppend(node.Right)
}
```

### Problem 3:

https://leetcode.com/problems/is-subsequence
Time: 16 ms
Complexity: O(n)

`s` works like a queue. We loop through a string `t` and pop `s` to check. 
- If the loop is finish but `s` is not empty -> `t` is doesn't contain all `s`
- Otherwise -> `t` contains `s`

```
func isSubsequence(s string, t string) bool {
    if len(s) == 0 {
        return true
    }
    
    if len(t) == 0 {
        return false
    }
    
    checkingIndex := 0
    sLength := len(s)
    for _, r := range t {
        if r == rune(s[checkingIndex]) {
            checkingIndex++
        }
        
        if checkingIndex >= sLength {
            return true
        }
    }
    
    return false
}
```

### Problem 4:

https://leetcode.com/problems/the-skyline-problem/description/

Complexity: O(n^2)

```go
type SpecialPoint struct {
	X        int
	Height   int
	IsStart  bool
	Building []int
}

type SpecialPoints []SpecialPoint

func (a SpecialPoints) Len() int      { return len(a) }
func (a SpecialPoints) Swap(i, j int) { a[i], a[j] = a[j], a[i] }
func (a SpecialPoints) Less(i, j int) bool {
	return a[i].X < a[j].X || (a[i].X == a[j].X && a[i].Height < a[j].Height)  ||  (a[i].X == a[j].X && a[i].Height == a[j].Height && !a[i].IsStart && a[j].IsStart)
}

func getSkyline(buildings [][]int) [][]int {
	var sp SpecialPoints
	for _, b := range buildings {
		sp = append(sp, SpecialPoints{
			SpecialPoint{
				X:        b[0],
				Height:   b[2],
				IsStart:  true,
				Building: b,
			},
			SpecialPoint{
				X:        b[1],
				Height:   b[2],
				IsStart:  false,
				Building: b,
			},
		}...)
	}
	sort.Sort(sp)

	fmt.Println(sp)
	tmpBuilding := make(map[int][]int)
	var result [][]int
	var currTallest int
	for index, p := range sp {
		oldTallest := currTallest
		if p.IsStart {
			tmpBuilding[p.Height] = p.Building
			if p.Height > currTallest {
				currTallest = p.Height
			}
		} else {
			delete(tmpBuilding, p.Height)
			currTallest = 0
			for y, _ := range tmpBuilding { // This loop make the complexity increase
				if y > currTallest {
					currTallest = y
				}
			}
            
		}
        
        if p.X == 10 && p.Height == 7 && p.IsStart {
            fmt.Println("DEBUG, x:", p.X, ", height: ", p.Height ,", currTallest:", currTallest, ", condition: ", (sp[index-1].Height != p.Height), ", sp[index-1].Height: ", sp[index-1].Height, ", p.Height:", p.Height )
            }
        
        if index == 0 || len(tmpBuilding) == 0 || 
        (oldTallest != currTallest && index > 0 && (sp[index-1].Height != p.Height || sp[index-1].Height != currTallest)) {
			if index > 0 && result[len(result)-1][1] == currTallest {
                fmt.Println("Update 2:", p.X, currTallest)
				result[len(result)-1][0] = p.X
            } else if index > 0 && result[len(result)-1][0] == p.X && currTallest > oldTallest {
                fmt.Println("Update 3:", p.X, currTallest)
				result[len(result)-1][1] = currTallest
            } else {
                fmt.Println("Add:", p.X, currTallest)
				result = append(result, []int{
					p.X,
					currTallest,
				})
			}
		}
	}

	return result
}
```
