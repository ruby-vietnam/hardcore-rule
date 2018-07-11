## Problem 1 - [Count and Say](https://leetcode.com/problems/count-and-say/description/)

```java
class Solution {
     public String countAndSay(int n) {
        String current = "1";
        while(--n>0) {
            int count = 1;
            StringBuilder sb = new StringBuilder();
            for(int i = 0; i < current.length(); i++) {
                if(i == current.length()-1 || current.charAt(i) != current.charAt(i+1)) {
                    sb.append(count).append(current.charAt(i));
                    count = 1;
                } else {
                    count++;
                }
            }
            current = sb.toString();
        }
        return current;
    }
}
```

## Problem 2 - [Elevator Trouble](https://www.spoj.com/problems/ELEVTRBL/)

```go
package main

import (
	"fmt"
	"os"
)

var f, s, g, u, d int64

func readInput() {
	fmt.Fscanf(os.Stdin, "%d %d %d %d %d", &f, &s, &g, &u, &d)
}

func solve() int64 {
	if s == g {
		return 0
	}

	if u == 0 {
		if d == 0 || g > s || (s-g)%d != 0 {
			return -1
		}
		return (s - g) / d
	}

	if d == 0 {
		if g < s || (g-s)%u != 0 {
			return -1
		}
		return (g - s) / u
	}

	var tmp, k1, k2 int64
	for k1 = 0; k1 <= f; k1++ {
		if tmp = s + u*k1; tmp >= g && (tmp-g)%d == 0 {
			if k2 = (tmp - g) / d; test(k1, k2) {
				return k1 + k2
			}
		}
	}
	return -1
}

func test(k1, k2 int64) bool {
	pos := s
	var remain, steps int64
	for k1 > 0 && k2 > 0 {
		if remain = f - pos; remain < u {
			// try to down
			if remain = pos - 1; remain < d {
				return false // can not go down
			} else if steps = remain / d; steps >= k2 {
				return true
			} else {
				k2 -= steps
				pos -= d * steps
			}
		} else if steps = remain / u; steps >= k1 {
			return true
		} else {
			k1 -= steps
			pos += u * steps
		}
	}
	return true
}

func main() {
	readInput()
	if result := solve(); result == -1 {
		fmt.Print("use the stairs")
	} else {
		fmt.Print(result)
	}
}
```

## Problem 3 - [Minimize the error](http://codeforces.com/problemset/problem/960/B)

```go
package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"os"
)

// B problem B
type B struct {
	q     IntHeap
	total int
}

// An IntHeap is a max-heap of ints.
type IntHeap []int

func (h IntHeap) Len() int            { return len(h) }
func (h IntHeap) Less(i, j int) bool  { return h[i] > h[j] }
func (h IntHeap) Swap(i, j int)       { h[i], h[j] = h[j], h[i] }
func (h *IntHeap) Push(x interface{}) { *h = append(*h, x.(int)) }
func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func (b *B) readInput() {
	inp := bufio.NewReader(os.Stdin)

	// read n
	var n, k1, k2, tmp int
	fmt.Fscanf(inp, "%d %d %d\n", &n, &k1, &k2)

	b.total = k1 + k2
	b.q = make(IntHeap, 0, n)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(inp, "%d", &a[i])
	}
	fmt.Fscanf(inp, "\n")
	for i := 0; i < n; i++ {
		fmt.Fscanf(inp, "%d", &tmp)
		if tmp = a[i] - tmp; tmp >= 0 {
			heap.Push(&b.q, tmp)
		} else {
			heap.Push(&b.q, -tmp)
		}
	}
}

func (b *B) solve() {
	total := b.total
	q := b.q

	for total > 0 {
		total--
		if q[0] > 0 {
			q[0]--
		} else {
			q[0]++
		}
		heap.Fix(&b.q, 0)
	}

	var sum int64
	for i := range q {
		sum += int64(q[i]) * int64(q[i])
	}
	fmt.Println(sum)
}

func main() {
	b := &B{}
	b.readInput()
	b.solve()
}
```

## Problem 4 - [Stone piles](https://www.hackerrank.com/challenges/stone-piles/problem)

```go
package main

import (
    "bufio"
    "fmt"
    "io"
    "os"
    "strconv"
    "strings"
)

var res = make([]int, 51)
var mark = make([][]bool, 51)

func playSubgame(prev, start, rest, key int) {
    for i := start; i <= rest >> 1; i++ {
        if rest - i > i {
		  mark[key][prev ^ res[i] ^ res[rest - i]] = true
		  playSubgame(prev ^ res[i], i + 1, rest - i, key)
        }
	}

	var k int
    for mark[key][k] {
	    k++
    }

    res[key] = k
}

func init() {
    for i := range mark {
        mark[i] = make([]bool, 51)
    }
    
    res[0], res[1], res[2], res[3] = 0, 0, 0, 1
    for i := 4; i <= 50; i++ {
        playSubgame(0, 1, i, i)
    }
}

func stonePiles(arr []int32) string {
    var s int
    for i := range arr {
        s ^= int(res[arr[i]])
    }
    
    if s == 0 {
        return "BOB"
    }
    return "ALICE"
}

func main() {
    reader := bufio.NewReaderSize(os.Stdin, 1024 * 1024)

    stdout, err := os.Create(os.Getenv("OUTPUT_PATH"))
    checkError(err)

    defer stdout.Close()

    writer := bufio.NewWriterSize(stdout, 1024 * 1024)

    tTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
    checkError(err)
    t := int32(tTemp)

    for tItr := 0; tItr < int(t); tItr++ {
        arrCount, err := strconv.ParseInt(readLine(reader), 10, 64)
        checkError(err)

        arrTemp := strings.Split(readLine(reader), " ")

        var arr []int32

        for arrItr := 0; arrItr < int(arrCount); arrItr++ {
            arrItemTemp, err := strconv.ParseInt(arrTemp[arrItr], 10, 64)
            checkError(err)
            arrItem := int32(arrItemTemp)
            arr = append(arr, arrItem)
        }

        result := stonePiles(arr)

        fmt.Fprintf(writer, "%s\n", result)
    }

    writer.Flush()
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == io.EOF {
        return ""
    }

    return strings.TrimRight(string(str), "\r\n")
}

func checkError(err error) {
    if err != nil {
        panic(err)
    }
}
```