## Problem 1 - [Nim Game](https://leetcode.com/problems/nim-game/description/)

Prove it by dynamic programing is very easy. 

In general, suppose that we can remove 1 to k stones in a turn, then the formula is: n % (k+1) != 0

```go
func canWinNim(n int) bool {
    return n & 3 != 0
}
```

## Problem 2 - [Teemo Attacking](https://leetcode.com/problems/teemo-attacking/description/)

This problem is simple segment merging. It's more simple because segments are sorted in input and have the same length.

```go
func findPoisonedDuration(timeSeries []int, duration int) int {
    if timeSeries == nil || len(timeSeries) == 0 {
        return 0
    }
    
    n := len(timeSeries)
    if n == 1 {
        return duration
    }
    
    total, max := duration, timeSeries[0] + duration
    for i := 1; i < n; i++ {
        if timeSeries[i] >= max {
            total += duration
        } else {
            total += timeSeries[i] + duration - max
        }
        
        max = timeSeries[i] + duration
    }
    
    return total
}
```

## Problem 3 - [Swim in Rising Water](https://leetcode.com/problems/swim-in-rising-water/description/)

We had done this problem in previous week. Just use BFS to surf with pre-assume of water level.

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

## Problem Bonus - [Parse Lisp Expression](https://leetcode.com/problems/parse-lisp-expression/description/)

Because expression syntax is prefix notation, it's much easier to parse and calculate tree.
One more thing makes this problem easy is the assumption: `The given string expression is well formatted`

```go
func evaluate(expression string) int {
    exp := parseTo(expression)
    return exp.val
}

type expressionNode struct {
    oType byte   // operator type: {'(': 0, ')': 1, 'let': 2, 'add': 3, 'mult': 4, variable: 5, value: 6}
    val int      // value if have
    name string  // variableName if have
    // left  *expressionNode
    // right *expressionNode
}

func parseTo(expression string) *expressionNode {
    var b bytes.Buffer
    
    // Adding space between '(' ')' and the rest
    for i := range expression {
        if c := expression[i]; c == 40 { // '('
            b.WriteByte(c)
            b.WriteByte(32)
        } else if c == 41 {
            b.WriteByte(32)
            b.WriteByte(c)
        } else {
            b.WriteByte(c)
        }
    }
    
    //
    firstPass := b.String()

    //
    secondPass := strings.Split(firstPass, " ")
    
    //
    thirdPass := make([]expressionNode, len(secondPass))
    for i := range secondPass {
        switch secondPass[i] {
            case "(":
                thirdPass[i].oType = 0
            case ")":
                thirdPass[i].oType = 1
            case "let":
                thirdPass[i].oType = 2
            case "add":
                thirdPass[i].oType = 3
            case "mult":
                thirdPass[i].oType = 4
            default:
                if v, e := strconv.Atoi(secondPass[i]); e == nil { // it's value
                    thirdPass[i].oType, thirdPass[i].val = 6, v
                } else {
                    thirdPass[i].oType, thirdPass[i].name = 5, secondPass[i]
                }
        }
    }
    
    // since lisp is prefix expression, then we just try to push things to tree
    x := 0
    return buildExpressionTree(thirdPass, &x, make(map[string]int))
}

func buildExpressionTree(exps []expressionNode, current *int, vMap map[string]int) *expressionNode {
    cur := *current

    if exps[cur].oType == 0 { // start new expression
        *current += 1
        r := buildExpressionTree(exps, current, vMap)
        *current += 1 // because expression is correct, we must have ')' at the end of expression
        return r
    }
    
    if exps[cur].oType == 3 || exps[cur].oType == 4 { // an add expression
        *current += 1
        x := buildExpressionTree(exps, current, vMap)
        
        *current += 1
        y := buildExpressionTree(exps, current, vMap)
        
        // exps[cur].left, exps[cur].right = x, y
        
        if exps[cur].oType == 3 {
            exps[cur].val = x.val + y.val
        } else {
            exps[cur].val = x.val * y.val
        }
        
        return &exps[cur]
    }
    
    if exps[cur].oType == 5 { // variable
        if v, ok := vMap[exps[cur].name]; ok {
            exps[cur].val = v
        }
        
        return &exps[cur]
    }
    
    if exps[cur].oType == 6 {
        return &exps[cur]
    }
    
    // so it must be 'let'
    // find the end of let expression
    var end, counter int
    for end, counter = cur, 0;; end++ {
        if exps[end].oType == 0 {
            counter--
        } else if exps[end].oType == 1 {
            counter++
        }
        
        if counter == 1 {
            break
        }
    }
    
    // now we have end
    curMap := make(map[string]int)
    for k, v := range vMap {
        curMap[k] = v
    }
    
    // Note: Malicious format of expression could cause loop run forever.
    // Below code is not for production use
    for {
        *current += 1
        variable := buildExpressionTree(exps, current, curMap)
        
        if *current + 1 == end { // variable is expression
            return variable
        }
        
        *current += 1
        value := buildExpressionTree(exps, current, curMap)
        
        curMap[variable.name] = value.val
    }
    
    return nil
}
```