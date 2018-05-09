## Problem 1 * Accepted *

https://leetcode.com/problems/valid-palindrome-ii/description/

```golang
func validPalindrome(s string) bool {
    return checkPalindrome(s, 0, len(s) - 1, false)
}

func checkPalindrome(s string, i int, j int, deleted bool) bool {
    for i < j {
        if s[i] != s[j] {
            if deleted {
                return false
            }
            return checkPalindrome(s, i + 1, j, true) || 
                   checkPalindrome(s, i, j - 1, true)
        }
        i++
        j--
    }
    return true
}
```

## Problem 2 * Accepted *

https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

We keep the current node, flatten left and right branches, then insert the right branch at the end of left branch and move left branch to the right

```golang
func flatten(root *TreeNode)  {
    if root == nil {
        return
    }
    
    flatten(root.Left)
    flatten(root.Right)
    
    legacyRight := root.Right
    root.Right = root.Left
    root.Left = nil
    
    i := root
    for i.Right != nil {
        i = i.Right
    }
    i.Right = legacyRight
}
```

## Problem 3 * Accepted *

https://leetcode.com/problems/is-subsequence/description/

We check for the position of letter i of s in j. If we can build a sequence n1, n2, n3..nn so that n1 < n2 < n3 ... nn and n(i) is one of the positions of s[i] in t

```golang
func isSubsequence(s string, t string) bool {
    hash := map[rune][]int{}
    for index, char := range t {
        _, exist := hash[char]
        if exist {
            hash[char] = append(hash[char], index)
        } else {
            hash[char] = []int{ index }
        }
    }
    
    flag := map[rune]int{}
    for key, _ := range hash {
        flag[key] = -1
    }
    
    places := []int{}
    for index, char := range s {
        current, exist := flag[char]
        if !exist || current >= len(hash[char]) {
            return false
        }
        previous := -1
        if index != 0 {
            previous = places[index-1]
        }
        current++
        for current < len(hash[char]) {
            if hash[char][current] > previous {
                break
            }
            current++
        }
        if current >= len(hash[char]) {
            return false
        }
        places = append(places, hash[char][current])
        flag[char] = current
    }
    return true
}
```

## Problem Bonus * Not finish. 32/36 *

https://leetcode.com/problems/the-skyline-problem/description/

- Put start and end point into an array, sort by x, then y. 
- Normalize the array, flatten the height so that the middle slower height is removed
- Loop from left to right. If at a point, the height increases, add that into the result; if the height decreases, calculate the decrease point.
- Watch out for the isolated group

```golang
type point struct {
	x         int
	y         int
	originalY int
	building  int
	start     bool
}

func getSkyline(buildings [][]int) [][]int {
	points := []point{}
	for index, b := range buildings {
		points = append(points, point{building: index, x: b[0], y: b[2], start: true})
		points = append(points, point{building: index, x: b[1], y: b[2], start: false})
	}
	sort(points, 0, len(points)-1)

	skyline := [][]int{}
	group := 0

	for i := 0; i < len(points); i++ {
		if points[i].start {
			normalize(points, buildings, i)
		}
	}

	for i := 0; i < len(points); i++ {
		if i < len(points)-1 && points[i].x == points[i+1].x && points[i].start == points[i+1].start {
			if points[i].start {
				group++
			} else {
				group--
			}
		} else {
			if len(skyline) == 0 {
				skyline = append(skyline, []int{points[i].x, points[i].y})
			} else if group == 0 && points[i].x != points[i-1].x {
				skyline = append(skyline, []int{points[i-1].x, 0})
				skyline = append(skyline, []int{points[i].x, points[i].y})
			} else {
				if points[i].y > points[i-1].y {
					skyline = append(skyline, []int{points[i].x, points[i].y})
				} else if points[i].y < points[i-1].y {
					skyline = append(skyline, []int{points[i-1].x, points[i].y})
				}
			}

			if points[i].start {
				group++
			} else {
				group--
			}
		}
	}

	if len(points) != 0 {
		skyline = append(skyline, []int{points[len(points)-1].x, 0})
	}

	return skyline
}

func normalize(points []point, buildings [][]int, i int) {
	for j := i + 1; j < len(points); j++ {
		if points[i].building == points[j].building {
			break
		}
		if points[j].y < buildings[points[i].building][2] {
			points[j].y = buildings[points[i].building][2]
		}
	}
}

func sort(points []point, start int, end int) {
	if start >= end {
		return
	}

	i := start
	j := end
	pivot := points[rand.Intn(end-start)+start]
	for i <= j {
		for smaller(points[i], pivot) {
			i++
		}
		for bigger(points[j], pivot) {
			j--
		}
		if i <= j {
			tmp := points[i]
			points[i] = points[j]
			points[j] = tmp
			i++
			j--
		}
	}

	sort(points, start, j)
	sort(points, i, end)
}

func smaller(a point, b point) bool {
	if a.x < b.x {
		return true
	} else if a.x > b.x {
		return false
	}
	return a.y < b.y
}

func bigger(a point, b point) bool {
	if a.x > b.x {
		return true
	} else if a.x < b.x {
		return false
	}
	return a.y > b.y
}
```
