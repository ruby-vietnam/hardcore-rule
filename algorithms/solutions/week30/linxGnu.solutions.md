## Problem 1 - [Mini-Max sum](https://www.hackerrank.com/challenges/mini-max-sum/problem)

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

// Complete the miniMaxSum function below.
func miniMaxSum(arr []int32) {
	var sum int64
	for i := range arr {
		sum += int64(arr[i])
	}

	min, max := sum-int64(arr[0]), sum-int64(arr[0])
	var tmp int64
	for i := 1; i < 5; i++ {
		tmp = sum - int64(arr[i])
		if tmp < min {
			min = tmp
		}
		if tmp > max {
			max = tmp
		}
	}

	fmt.Print(min, max)
}

func main() {
	reader := bufio.NewReaderSize(os.Stdin, 1024*1024)

	arrTemp := strings.Split(readLine(reader), " ")

	var arr []int32

	for i := 0; i < 5; i++ {
		arrItemTemp, err := strconv.ParseInt(arrTemp[i], 10, 64)
		checkError(err)
		arrItem := int32(arrItemTemp)
		arr = append(arr, arrItem)
	}

	miniMaxSum(arr)
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

## Problem 2 - [Sparse Array](https://www.hackerrank.com/challenges/sparse-arrays/problem)

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

type trie struct {
	counter int32
	next    map[byte]*trie
}

func newTrie() *trie {
	return &trie{next: make(map[byte]*trie)}
}

func (t *trie) Add(s string) {
	current := t
	var next *trie
	for i := range s {
		if next = current.next[s[i]]; next == nil {
			next = newTrie()
			current.next[s[i]] = next
		}
		current = next
	}
	current.counter++
}

func (t *trie) Find(s string) int32 {
	current := t
	var next *trie
	for i := range s {
		if next = current.next[s[i]]; next == nil {
			return 0
		}
		current = next
	}
	return current.counter
}

// Complete the matchingStrings function below.
func matchingStrings(strings []string, queries []string) []int32 {
	root := newTrie()
	for i := range strings {
		root.Add(strings[i])
	}

	result := make([]int32, len(queries))
	for i := range queries {
		result[i] = root.Find(queries[i])
	}

	return result
}

func main() {
	reader := bufio.NewReaderSize(os.Stdin, 1024*1024)

	stdout, err := os.Create(os.Getenv("OUTPUT_PATH"))
	checkError(err)

	defer stdout.Close()

	writer := bufio.NewWriterSize(stdout, 1024*1024)

	stringsCount, err := strconv.ParseInt(readLine(reader), 10, 64)
	checkError(err)

	var strings []string

	for i := 0; i < int(stringsCount); i++ {
		stringsItem := readLine(reader)
		strings = append(strings, stringsItem)
	}

	queriesCount, err := strconv.ParseInt(readLine(reader), 10, 64)
	checkError(err)

	var queries []string

	for i := 0; i < int(queriesCount); i++ {
		queriesItem := readLine(reader)
		queries = append(queries, queriesItem)
	}

	res := matchingStrings(strings, queries)

	for i, resItem := range res {
		fmt.Fprintf(writer, "%d", resItem)

		if i != len(res)-1 {
			fmt.Fprintf(writer, "\n")
		}
	}

	fmt.Fprintf(writer, "\n")

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

## Problem 3 - [Need More Bosses](http://codeforces.com/problemset/problem/1000/E)

```go
package main

import (
	"bufio"
	"fmt"
	"os"
)

var n int
var nodes [][]int
var low, num, parent, crit []int

func readInput() {
	inp := bufio.NewReader(os.Stdin)

	// read n
	var m int
	fmt.Fscanf(inp, "%d %d\n", &n, &m)

	nodes, low, num, parent, crit = make([][]int, n+1), make([]int, n+1), make([]int, n+1), make([]int, n+1), make([]int, n+1)
	for i := range nodes {
		nodes[i] = make([]int, 0, 64)
	}

	var u, v int
	for m > 0 {
		m--
		fmt.Fscanf(inp, "%d %d\n", &u, &v)
		nodes[u] = append(nodes[u], v)
		nodes[v] = append(nodes[v], u)
	}
}

var time int

func visit(u int) {
	time++
	num[u], low[u] = time, n+2

	for _, v := range nodes[u] {
		if v != parent[u] { // no reverse back
			if num[v] == 0 {
				parent[v] = u
				visit(v)

				if low[v] < low[u] {
					low[u] = low[v]
				}

				if low[v] >= num[v] { // critical edge u --> v
					crit[v] = u
				}
			} else if num[v] < low[u] {
				low[u] = num[v]
			}
		}
	}
}

func longest(u int) (int, int) {
	var tmp1, tmp2, max, max1, max2 int

	for _, v := range nodes[u] {
		tmp1, tmp2 = longest(v)

		if crit[v] == u {
			tmp2++
		}

		if max < tmp1 {
			max = tmp1
		}

		if tmp2 > max2 {
			if max2 = tmp2; max2 > max1 {
				max1, max2 = max2, max1
			}
		}
	}

	if max < max2+max1 {
		max = max2 + max1
	}

	return max, max1
}

func solve() {
	parent[1] = -1
	visit(1)

	for i := 1; i <= n; i++ {
		nodes[i] = make([]int, 64)
	}

	var p int
	for u := 2; u <= n; u++ {
		p = parent[u]
		nodes[p] = append(nodes[p], u)
	}

	max1, max2 := longest(1)
	if max1 < max2 {
		fmt.Print(max2)
	} else {
		fmt.Print(max1)
	}
}

func main() {
	readInput()
	solve()
}
```

## Problem 4 - [Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/)

```go
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
    tmp := len(nums1) + len(nums2)
    if tmp & 1 == 1 {
        return float64(findKThElement(nums1, nums2, tmp >> 1))        
    } 
    
    x1 := findKThElement(nums1, nums2, tmp >> 1)
    x2 := findKThElement(nums1, nums2, (tmp >> 1) - 1)
    return float64(x1 + x2) / 2.0
}

func findKThElement(nums1 []int, nums2 []int, k int) int {
    var len1, len2, split1, split2 int
    
    if k < 0 || k >= len(nums1) + len(nums2) {
        return 0
    }
    
    for {
        if len1 = len(nums1); len1 == 0 {
            return nums2[k]
        }

        if len2 = len(nums2); len2 == 0 {
            return nums1[k]
        }

        if k == 0 {
            if nums1[0] < nums2[0] {
                return nums1[0]
            } else {
                return nums2[0]
            }
        }

        split1 = len1 * k / (len1 + len2)
        split2 = k - split1 - 1;
   
        if nums1[split1] <= nums2[split2] {
            k -= split1 + 1
            nums1, nums2 = nums1[split1 + 1:], nums2[:split2+1]
        } else {
            k -= split2 + 1
            nums1, nums2 = nums1[:split1 + 1], nums2[split2 + 1:]
        }
    }
    return 0
}
```