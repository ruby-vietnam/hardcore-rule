
# Problem 1 - Longest word in dictionary
```go
type TrieNode struct {
    isWord bool
    next map[byte]*TrieNode
}

type Trie struct {
    root *TrieNode
}

func (c *Trie) Insert(word string) {
    if len(word) == 0 {
        return
    }
    
    cur := c.root
    for i := range word {
        if cur.next == nil {
            cur.next = make(map[byte]*TrieNode)
        }
        
        node, ok := cur.next[word[i]]
        if !ok {
            node = &TrieNode{}
            cur.next[word[i]] = node
        }
        
        cur = node        
    }
    cur.isWord = true
}

func longestWord(words []string) string {
    if words == nil || len(words) == 0 {
        return ""
    }
    
    // init trie
    trie := &Trie{root:&TrieNode{isWord: true}}
    
    // fill up with words
    for _, word := range words {
        trie.Insert(word)
    }
    
    return string(reverse(longestWordOnTrie(trie.root)))
}

func longestWordOnTrie(node *TrieNode) (chain []byte) {
    if !node.isWord {
        return nil
    }
    
    if len(node.next) == 0 {
        return make([]byte, 0, 30)
    }
    
    max := -1
    var head byte
    result := make([]byte, 0, 30)
    
    for k, v := range node.next {
        if r := longestWordOnTrie(v); r != nil {
            if len(r) > max {
                max, head, result = len(r), k, append(r, k)
            } else if len(r) == max && head > k {
                head, result = k, append(r, k)
            }
        }
    }
    
    return result
}

func reverse(a []byte) (r []byte) {
    if a == nil || len(a) == 0 {
        return a
    }
    
    n := len(a)
    for i := 0; i < n >> 1; i++ {
        a[i], a[n-1-i] = a[n-1-i], a[i]
    }
    
    return a
}
```

# Problem 3 - Swim in Rising Water
```go
var directions = [][]int8{
    []int8{0, 1},
    []int8{1, 0},
    []int8{-1, 0},
    []int8{0, -1},
}

func swimInWater(grid [][]int) int {
    if grid == nil {
        return 0
    }
    
    n := int8(len(grid))
    if n <= 1 {
        return 0
    }
    
    var max int
    for i := range grid {
        for j, v := range grid[i] {
        	grid[i][j]++
            if v > max {
                max = v
            }
        }
    }
    max++
    
    // q1 q2: queue storing cordinates
    q1, q2 := make([]int8, 2500), make([]int8, 2500)
    
    left, right, mid := 1, max, 0
    for left <= right {
        if mid = (left + right) >> 1; mid == left {
            if canSwim(grid, n, left, q1, q2) {
                return left - 1
            }
            
            return right - 1
        }
        
        if canSwim(grid, n, mid, q1, q2) {
            right = mid 
        } else {
            left = mid
        }
    }
    
    return 0
}

func canSwim(grid [][]int, n int8, waterLevel int, q1, q2 []int8) bool {
    if grid[0][0] > waterLevel {
    	return false
    }
    
    defer func() {
    	for i := range grid {
    	   for j := range grid[i] {
    	      if grid[i][j] < 0 {
    	         grid[i][j] = -grid[i][j]
    	      }
    	   }
    	}
    }()
    
    start, end, tmpEnd := 0, 0, 0
    q1[start], q2[start] = 0, 0
    grid[0][0] = -grid[0][0]
    
    for {
    	tmpEnd = end
    	for ind := start; ind <= tmpEnd; ind++ {
    		u, v := q1[ind], q2[ind]
    		for _, dir := range directions {
    			x, y := u + dir[0], v + dir[1]
    			if x >= 0 && x < n && y >= 0 && y < n && grid[x][y] > 0 && grid[x][y] <= waterLevel {
    			    if x == n - 1 && y == n - 1 {
    					return true
    				}
    				
    				end++
    				q1[end], q2[end] = x, y
    				grid[x][y] = -grid[x][y]
    			}
    		}
    	}
    	
    	if tmpEnd == end {
    		break
    	}
    	
    	start = tmpEnd + 1
    }
    
    return false
}
```

# Problem bonus - Erect the Fence
```go
/**
 * Definition for a point.
 * type Point struct {
 *     X int
 *     Y int
 * }
 */
func outerTrees(points []Point) []Point {
    if points == nil || len(points) == 0 {
        return []Point{}
    }
    
    // sort and filter duplication points
    points = sortAndFilterDuplication(points)
    
    // check rest len
    n := len(points)
    if n <= 2 {
        return points
    }
    
    // get start point to convex hull
    xStart, yStart := points[0].X, points[0].Y
    sortByAngle(points[1:], xStart, yStart)
    
    // now stack build convex hull
    nStack := 2
    for i := 2; i < n; i++ {
        for nStack >= 2 && isTurnRight(points[nStack-1].X - points[nStack-2].X, points[nStack-1].Y - points[nStack-2].Y, points[i].X - points[nStack-2].X, points[i].Y - points[nStack-2].Y) {
            nStack--
        }
        points[nStack].X, points[nStack].Y = points[i].X, points[i].Y
        nStack++
    }
    
    return points[:nStack]
}

/// check if vector x2 y2 is turn right from x1 y1
func isTurnRight(x1, y1, x2, y2 int) bool {
    return y2 * x1 < y1 * x2
}

func sortAndFilterDuplication(points []Point) []Point {
    if len(points) == 0 {
        return points
    }
    
    // sort by Y, then by X
    sort.Slice(points, func(i, j int) bool {
        if points[i].Y == points[j].Y {
            return points[i].X < points[j].X
        }
        
        return points[i].Y < points[j].Y 
    })
    
    // filter duplication by code below
    // But All coordinates are distinct in this problem, then we just comment it out
    // In general, it's very necessary.
    //     old := &Point{X: points[0].Y-1}
    //     n := 0
    //     for i := range points {
    //         if v := &points[i]; old.Y != v.Y || old.X != v.X {
    //             points[n].X, points[n].Y = v.X, v.Y
    //             old = &points[n]
    //             n++
    //         }
    //     } 
    
    return points
}

func sortByAngle(points []Point, xCenter, yCenter int) {
    sort.Slice(points, func(i, j int) bool {
        x1, y1 := points[i].X - xCenter, points[i].Y - yCenter
        x2, y2 := points[j].X - xCenter, points[j].Y - yCenter
        
        if x1 == 0 {
            if x2 == 0 {
                return y1 < y2
            }
            return x2 < 0
        }
        
        if x2 == 0 {
            return x1 > 0
        }
        
        // since yCenter <= y1, y2, we just check x1 and x2
        
        // case 1
        if x1 < 0 && x2 > 0 {
            return false
        }
        
        // case 2
        if x1 > 0 && x2 < 0 {
            return true
        }
        
        // case 3
        if y1 * x2 == x1 * y2 {
            return x1 * x1 + y1 * y1 < x2 * x2 + y2 * y2
        }
        
        return y1 * x2 < x1 * y2 
    })
    
    // code below is not neccessary in general.
    // This problem requires us to do that.
    // Case is: [[3,0],[4,0],[5,0],[6,1],[7,2],[7,3],[7,4],[6,5],[5,5],[4,5],[3,5],[2,5],[1,4],[1,3],[1,2],[2,1],[4,2],[0,3]]
    // my output is: [[3,0],[4,0],[5,0],[6,1],[7,2],[7,3],[7,4],[6,5],[5,5],[4,5],[3,5],[2,5],[1,4],[0,3]]
    // expected is: [[0,3],[1,2],[2,1],[3,0],[4,0],[5,0],[6,1],[7,2],[7,3],[7,4],[6,5],[5,5],[4,5],[3,5],[2,5],[1,4]]
    // since (3,0) (0, 3) (2,1) (1,2) are on the same line, we must keep (2,1) and (1,2) in the convex hull set.
    n := len(points)
    vX, vY := points[n-1].X - xCenter, points[n-1].Y - yCenter

    var i int
    for i = n-1; i >= 0; i-- {
        if uX, uY := points[i].X - xCenter, points[i].Y - yCenter; uX * vY != uY * vX {
            break
        }
    }
    
    // reverse from i + 1 --> n - 1
    mid := (n + i) >> 1
    for head, tail := i + 1, n - 1; head <= mid; {
        points[head], points[tail] = points[tail], points[head]
        head++
        tail--
    }
}
```
