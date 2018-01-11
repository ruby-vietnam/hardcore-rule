## Problem 1
Từ dữ kiện của đề bài, ta dễ dàng đưa ra được nhận xét: hai chuỗi được xem là
anagrams khi số lần xuất hiện của từng kí tự trong hai chuỗi là bằng nhau. Như
vậy, muốn biến chuỗi A thành anagrams của chuỗi B, ứng với từng kí tự từ a ->
z, ta chỉ cần bổ sung thêm số lượng kí tự còn thiếu vào chuỗi A hoặc B. Bài giải
tham khảo:

```golang
package main

import (
	"fmt"
)

func main() {
	var str1, str2 string
	fmt.Scanf("%s\n%s", &str1, &str2)

	var flag1, flag2 [26]int
	for i := 0; i < len(str1); i++ {
		flag1[int8(str1[i])-int8('a')]++
	}
	for i := 0; i < len(str2); i++ {
		flag2[int8(str2[i])-int8('a')]++
	}

	distance := 0
	for i := 0; i < 26; i++ {
		if flag1[i] >= flag2[i] {
			distance += flag1[i] - flag2[i]
		} else {
			distance += flag2[i] - flag1[i]
		}
	}
	fmt.Printf("%d", distance)
}
```

## Problem 2
Từ dữ kiện đề bài, ta có một một nhận xét nho nhỏ như sau: `nums2[i] <= nums2[j] với mọi i < j` suy ra `nums1[x] + nums2[i] <= nums1[x] + nums2[j] với mọi i < j và x bất kì`. Điều này có nghĩ là khi chọn một vị trí x bất kì ở nums1 thì thứ tự các cặp theo tứ tự tăng dần sẽ là `[nums1[x], nums2[0]]`, `[nums1[x], nums2[1]]`, `[nums1[x], nums2[2]]`, .. Do đó, ta có thể nghĩ đến cách sử dụng một mảng đánh dấu `pairs[x]`, với `pairs[x]` là vị trí tiếp theo trong nums2 để pair với vị trí x trong nums1. Tại một thời điểm, ta tìm được vị trí x sao cho nums1[x] + nums2[pairs[x]] là nhỏ nhất, đẩy vào mảng kết quả và tăng giá trị của pairs[x]. Nếu ta tìm x theo cách duyệt từ 1 -> length(nums1) thì đột phức tạp của bài toán sẽ là `O(lenth(nums1)^2)`, không đủ nhỏ cho trường hợp input lớn. Để tối ưu bài toán con này, ta có thể sử dụng một min heap. Khi update lại pairs thì ta cũng đẩy vào heap giá trị của pairs và vị trí x. Như vậy độ phức tạp để query tìm x giảm còn `O(log length(nums1))` và độ phức tạp chung của kết quả sẽ là `O((log length(nums1)) ^ 2)`.

Bài giải tham khảo:

```golang
package main

import (
	"fmt"
)

type node struct {
	key int
	val int
}

type heap struct {
	data   []*node
	length int
}

func (h *heap) pop() *node {
	if h.length == 0 {
		return nil
	}
	n := h.data[0]
	h.swap(0, h.length-1)
	h.length--
	h.heapify()
	return n
}

func (h *heap) push(key int, val int) {
	n := &node{
		key: key,
		val: val,
	}
	h.length++
	h.data[h.length-1] = n

	pos := h.length - 1
	for pos > 0 && h.data[pos].val < h.data[(pos-1)/2].val {
		h.swap(pos, (pos-1)/2)
		pos = (pos - 1) / 2
	}
}

func (h *heap) heapify() {
	pos := 0
	for pos < h.length-1 {
		min := h.minNode(pos)
		if min == pos {
			return
		}
		h.swap(pos, min)
		pos = min
	}
}

func (h *heap) swap(i int, j int) {
	tmp := h.data[i]
	h.data[i] = h.data[j]
	h.data[j] = tmp
}

func (h *heap) minNode(i int) int {
	min := i
	if i*2+1 < h.length && h.data[i*2+1].val < h.data[min].val {
		min = i*2 + 1
	}
	if i*2+2 < h.length && h.data[i*2+2].val < h.data[min].val {
		min = i*2 + 2
	}
	return min
}

func smallestPairs(nums1 []int, nums2 []int, k int) [][]int {
	if len(nums1) == 0 || len(nums2) == 0 {
		return [][]int{}
	}
	pairs := make([]int, len(nums1))
	// Init heap
	h := heap{
		data: make([]*node, len(nums1)),
	}
	for index, pair := range pairs {
		h.push(index, nums1[index]+nums2[pair])
	}
	// Process
	results := [][]int{}
	for i := 0; i < k; i++ {
		n := h.pop()
		if n == nil {
			break
		}
		results = append(results, []int{nums1[n.key], nums2[pairs[n.key]]})
		if pairs[n.key] < len(nums2)-1 {
			pairs[n.key]++
			h.push(n.key, nums1[n.key]+nums2[pairs[n.key]])
		}

	}
	return results
}

func main() {
	results := smallestPairs([]int{1, 7, 11}, []int{2, 4, 6}, 3)
	// results := smallestPairs([]int{1, 2, 2}, []int{2, 3, 4}, 4)
	// results := smallestPairs([]int{}, []int{}, 3)
	fmt.Println(results)
}
```

## Problem 3
Một chuỗi palindrome hai đầu là tứ tự `x` được hình thành từ một chuỗi palindrome nhỏ hơn bất kể kí tự bắt đầu và kết thúc. Từ nhận xét trên, ta có thể sử dụng quy hoạch động (DP) để giải bài toán này. Gọi `T[x][i][j]` là số lượng palindrome bắt đầu và kết thúc bằng kí tự x trong khoảng S[i -> j]. Công thức quy hoạch động:

```
T[x][i][j] = sum(k: a -> d, T[k][i-1][j-1]) if S[i] == S[j] && S[i] == x
T[x][i][j] = T[x][i-1][j] if S[j] == x
T[x][i][j] = T[x][i][j-1] if S[i] == x
T[x][i][j] = T[x][i-1][j-1] in other cases
```

Bài giải tham khảo:

```golang
package main

import (
	"fmt"
)

const LIMIT = 1000000007

var counts = [][][]int{}
var instructions = 0

func initialize(n int) {
	counts = make([][][]int, 4)
	for i := 'a'; i <= 'd'; i++ {
		counts[i-'a'] = make([][]int, n)
		for j := 0; j < n; j++ {
			counts[i-'a'][j] = make([]int, n)
		}
	}
}

func countPalindromicSubsequences(s string) int {
	initialize(len(s))
	sum := 0
	instructions = 0
	for char := 'a'; char <= 'd'; char++ {
		sum = (sum%LIMIT + count(char, 0, len(s)-1, s)%LIMIT) % LIMIT
	}
	fmt.Printf("Instructions: %d\n", instructions)
	return sum
}

func count(char rune, i int, j int, s string) int {
	instructions = instructions + 1
	if i == j && s[i] == s[j] && rune(s[i]) == char {
		return 1
	}
	if i >= j {
		return 0
	}
	if rune(s[i]) == char && rune(s[j]) == char {
		if counts[char-'a'][i][j] != 0 {
			return counts[char-'a'][i][j]
		}
		sum := 0
		for c := 'a'; c <= 'd'; c++ {
			sum = (sum%LIMIT + count(c, i+1, j-1, s)%LIMIT) % LIMIT
		}
		sum = (sum + 2) % LIMIT
		counts[char-'a'][i][j] = sum
		return sum
	} else if rune(s[i]) == char {
		if counts[char-'a'][i][j-1] != 0 {
			return counts[char-'a'][i][j-1]
		}
		result := count(char, i, j-1, s)
		counts[char-'a'][i][j-1] = result
		return result
	} else if rune(s[j]) == char {
		if counts[char-'a'][i+1][j] != 0 {
			return counts[char-'a'][i+1][j]
		}
		result := count(char, i+1, j, s)
		counts[char-'a'][i+1][j] = result
		return result
	} else {
		if counts[char-'a'][i+1][j-1] != 0 {
			return counts[char-'a'][i+1][j-1]
		}
		result := count(char, i+1, j-1, s)
		counts[char-'a'][i+1][j-1] = result
		return result
	}
}

func main() {
	// fmt.Println(countPalindromicSubsequences("bccb"))
	// fmt.Println(countPalindromicSubsequences("bbccb"))
	// fmt.Println(countPalindromicSubsequences("bbccbb"))
	// fmt.Println(countPalindromicSubsequences("bbccbbc"))
	fmt.Println(countPalindromicSubsequences("abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba"))
}
```

## Problem 4
Chúng ta sẽ nhìn bài toán theo cách khác. Thay vì tìm đường thẳng cắt số viên gạch ít nhất, chúng ta sẽ tìm điểm x có số "khoảng không" nhiều nhất. Ở một dòng bất kì, để xác định được điểm x có khoảng không hay không, chúng ta cần tìm một số i, sao cho tổng chiều ngang của viên gạch từ 0 -> j bằng x. Để giải quyết được bài toán này, có một cách là sinh ra tất cả các điểm x có thể và tìm điểm x có số lần xuất hiện nhiều nhất. Bài giải tham khảo:

```golang
package main

import (
	"fmt"
)

func leastBricks(wall [][]int) int {
	width := 0
	for _, brick := range wall[0] {
		width += brick
	}

	values := make([]int, 20000)
	lines := make([]int, width)

	for _, row := range wall {
		line := 0
		// Ignore the last brick
		for i := 0; i < len(row)-1; i++ {
			line += row[i]
			lines[line]++
			values = append(values, line)
		}
	}

	max := 0
	for _, value := range values {
		if lines[value] > max {
			max = lines[value]
		}
	}

	if max == 0 {
		return len(wall)
	}
	return len(wall) - max
}

func main() {
	result := leastBricks([][]int{
		[]int{1, 2, 2, 1},
		[]int{3, 1, 2},
		[]int{1, 3, 2},
		[]int{2, 4},
		[]int{3, 1, 2},
		[]int{1, 3, 1, 1},
	})
	// result := leastBricks([][]int{
	// 	[]int{1},
	// 	[]int{1},
	// 	[]int{1},
	// })
	// result := leastBricks([][]int{
	// 	[]int{7, 1, 2},
	// 	[]int{3, 5, 1, 1},
	// 	[]int{10},
	// })
	fmt.Println(result)
}
```


