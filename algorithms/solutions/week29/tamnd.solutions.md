## Problem 1

```go
import (
    "fmt"
    "bytes"
)

func countAndSay(n int) string {
    ret := "1"
    
    for i := 1; i < n; i++ {
        var buf bytes.Buffer
        l := len(ret)
        for j := 0; j < l; j++ {
            count := 1
            for (j + 1 < l) && (ret[j] == ret[j+1]) {
                count++
                j++
            }
            buf.WriteString(fmt.Sprintf("%d", count))
            buf.WriteString(fmt.Sprintf("%d", ret[j] - '0'))
        }
        ret = buf.String()
        buf.Reset()
    }
    return ret
}
```

## Problem 2

```go
package main

import (
	"fmt"
	"os"
)

func read() (floors, start, goal, up, down int) {
	fmt.Fscanf(os.Stdin, "%d %d %d %d %d", &floors, &start, &goal, &up, &down)
	return
}

func solve(floors, start, goal, up, down int) int {
	queue := make([]int, 0)
	distance := make(map[int]int)

	distance[start] = 0
	queue = append(queue, start)

	for len(queue) > 0 {
		// dequeue
		tmp := queue[0]
		queue = queue[1:]

		if tmp == goal {
			return distance[goal]
		}

		if tmp+up <= floors {
			if _, found := distance[tmp+up]; !found {
				distance[tmp+up] = distance[tmp] + 1
				queue = append(queue, tmp+up)
			}
		}

		if tmp-down > 0 {
			if _, found := distance[tmp-down]; !found {
				distance[tmp-down] = distance[tmp] + 1
				queue = append(queue, tmp-down)
			}
		}

	}
	return -1
}

func main() {
	// ret := solve(10, 1, 10, 2, 1)
	ret := solve(read())
	if ret == -1 {
		fmt.Println("use the stairs")
	} else {
		fmt.Println(ret)
	}
}
```
