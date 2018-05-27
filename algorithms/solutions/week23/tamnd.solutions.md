### Problem 1

```go
import "strings"

func simplifyPath(path string) string {
	parts := strings.Split(path, "/")
	ret := make([]string, len(parts))
	index := 0
	for _, part := range parts {
		switch part {
		case ".":
			continue
		case "":
			continue
		case "..":
			if index > 0 {
				index--
			}
		default:
			{
				ret[index] = part
				index++
			}
		}
	}
	ret = ret[0:index]
	return "/" + strings.Join(ret, "/")
}
```

### Problem 4
```go
/**
 * Definition for a point.
 * type Point struct {
 *     X int
 *     Y int
 * }
 */
func maxPoints(points []Point) int {
    max := 0
    n := len(points)
    for i := 0; i < n; i++ {
        lines := make(map[Line]int, n)
        dup := 1
        for j := i+1; j < n; j++ {       
            if points[i].X == points[j].X && points[i].Y == points[j].Y {
                dup++
            } else {
                line := makeLine(points[i], points[j])
                lines[line]++
            }
        }
        if dup > max {
            max = dup
        }
        for _, count := range lines {
            if count + dup > max {
                max = count + dup
            }
        }
    }
    return max
}

type Line struct {
    X int
    Y int
}

func gcd(a int, b int) int {
    for b != 0 {
        b, a = a % b, b
    }
    return a
}

func makeLine(p1 Point, p2 Point) Line {
    dx := p2.X - p1.X
    dy := p2.Y - p1.Y
    dgcd := gcd(dx, dy)
    return Line{X: dx/dgcd, Y: dy/dgcd}
}
```
