## Problem 1 - [Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/description/)

```java
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        int len1 = getLen(headA);
        int len2 = getLen(headB);
        
        if (len1 == 0 || len2 == 0) {
            return null;
        }
        
        if (len1 > len2) {
            headA = moveFurther(headA, len1 - len2);
        } else {
            headB = moveFurther(headB, len2 - len1);
        }
        
        while (headA != null) {
            if (headA == headB) {
                return headA;
            }
            headA = headA.next;
            headB = headB.next;
        }
        
        return null;
    }
    
    public static ListNode moveFurther(ListNode node, int step) {
        while (step-- > 0) {
            node = node.next;
        }
        return node;
    }
    
    public static int getLen(ListNode node) {
        int len = 0;
        while (node != null) {
            len++;
            node = node.next;
        }
        return len;
    }
}
```

## Problem 2 - [Simplify Path](https://leetcode.com/problems/simplify-path/description/)

```go
func simplifyPath(path string) string {
    splited := strings.Split(path, "/")
    
    stack := []string{}
    for i := range splited {
        if splited[i] != "" && splited[i] != "." {
            if splited[i] == ".." {
                if nStack := len(stack); nStack > 0 {
                    stack = stack[:nStack-1]
                }
            } else {
                stack = append(stack, splited[i])
            }
        }
    }
   
    if len(stack) == 0 {
        return "/"
    } 

    return "/" + strings.Join(stack, "/")
}
```

## Problem 3 - [New 21 Game](https://leetcode.com/problems/new-21-game/description/)

```go
func new21Game(N int, K int, W int) (res float64) {
    if K == 0 || N >= K + W {
        return 1
    }
    
    f := make([]float64, N + 1)
    f[0] = 1
    
    var sum float64 = 1
    var w = float64(W)
    for i := 1; i <= N; i++ {
        if f[i] = sum / w; i < K {
            sum += f[i]
        } else {
            res += f[i]
        }
          
        if i >= W {
            sum -= f[i - W]
        }
    }
    
    return
}
```

## Problem 4 - [Max Points on a Line](https://leetcode.com/problems/max-points-on-a-line/description/)

```go
func maxPoints(points []Point) int {
    if points == nil || len(points) < 1 {
        return 0
    } 
    
    n := len(points)
    if n <= 2 {
        return n
    }
    
    sort.Slice(points, func(i,j int) bool {
        if points[i].X == points[j].X {
            return points[i].Y < points[j].Y
        }
        return points[i].X < points[j].X 
    })
    
    var same, ver, hor, tmp, tmp1, tmp2, max int
    for i := range points {
        same, ver, hor = 1, 0, 0
        m := make(map[int]map[int]int)
        for j := i + 1; j < n; j++ {
            if points[i].X == points[j].X && points[i].Y == points[j].Y {
                same++
            } else if points[i].X == points[j].X {
                ver++
            } else if points[i].Y == points[j].Y {
                hor++
            } else {
                tmp = gcd(abs(points[j].X - points[i].X), abs(points[i].Y - points[j].Y))
                tmp1 = (points[j].Y - points[i].Y) / tmp
                tmp2 = (points[j].X - points[i].X) / tmp
                
                if mp, ok := m[tmp1]; !ok {
                    mp = make(map[int]int)
                    mp[tmp2] = 1
                    m[tmp1] = mp
                } else {
                    mp[tmp2]++
                }
            }
        }
        
        if max < same + hor {
            max = same + hor
        }
        
        if max < same + ver {
            max = same + ver
        }
        
        for _, v1 := range m {
            for _, v2 := range v1 {
                if max < same + v2 {
                    max = same + v2
                }
            }
        }
    }
    
    return max
}

func abs(a int) int {
    if a < 0 {
        return -a
    }
    return a
}

func gcd(a, b int) int {
    if a < b {
        a, b = b, a
    }
    
    for {
        if a % b == 0 {
            return b
        } 
        a, b = b, a % b
    }
    
    return 0
}
```