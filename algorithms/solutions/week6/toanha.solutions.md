# Problem 1: Degree of an Array

URL: https://leetcode.com/problems/degree-of-an-array/description/

Status:
```
  ✔ Accepted
  ✔ 89/89 cases passed (72 ms)
  ✔ Your runtime beats 40.63 % of golang submissions
```

<details>
Sử dụng 3 map, và 1 biến để lưu max degree
  1. Lưu tần số xuất hiện
  2. Vị trí bắt đầu của 1 phần tử phân biệt trong mảng
  3. Vị trí kết thúc của 1 phần tử phân biệt trong mảng

Sau đó mình duyệt trong mảng tần số và lấy độ dài ngắn nhất của 1 số trong mảng

Ví dụ:
Mảng `[2, 1, 1, 2, 1, 3, 3, 3, 1, 3, 1, 3, 2]`

Sẽ có mảng tần số là:
`map[2:3 1:5 3:5]`

Mảng vị trí bắt đầu
`map[2:0 1:1 3:5]`

Mảng vị trí kết thúc
`map[2:12 1:10 3:11]`

Quan tâm 1 và 3 với degree là 5 mình sẽ có độ dài của 2 mảng đó tương ứng là 10 và 7

Vậy kết quả chấp nhận là 7

```golang
package main

import "fmt"

func findShortestSubArray(nums []int) int {
  var mCount = map[int]int{}
  var mFist = map[int]int{}
  var mLast = map[int]int{}
  var degree = 0

  for i := 0; i < len(nums); i++ {
    if val, ok := mCount[nums[i]]; ok {
      mCount[nums[i]] = val + 1
    } else {
      mCount[nums[i]] = 1
      mFist[nums[i]] = i
    }

    if mCount[nums[i]] > degree {
      degree = mCount[nums[i]]
    }
    mLast[nums[i]] = i
  }

  var minLen = len(nums)

  for k, v := range mCount {
    if v == degree {
      minLen = min(minLen, mLast[k]-mFist[k]+1)
    }
  }

  return minLen
}

func min(x, y int) int {
  if x > y {
    return y
  }
  return x
}

func main() {
  fmt.Println(findShortestSubArray([]int{2, 1, 1, 2, 1, 3, 3, 3, 1, 3, 1, 3, 2}))
}

```
</details>
