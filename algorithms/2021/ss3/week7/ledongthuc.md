# 1. Majority Element

https://leetcode.com/problems/majority-element/

## 1.1. Summary

 - Use a counter to check major number.
 - If a checking number appears in next number, counter + 1
 - If an other numbers appear in next number, counter - 1
 - if counter = 0, change checking number to another number.

## 1.2. Code

```go
/* func majorityElement(nums []int) int {
    n := len(nums) / 2
    m := make(map[int]int)
    for _, num := range nums {
        m[num] = m[num] + 1
        if m[num] > n {
            return num
        }
    }
    return -1
} */

func majorityElement(nums []int) int {
    var maybeMajor, count int
    for _, num := range nums {
        if 0 == count {
            maybeMajor = num
            count++
        } else if maybeMajor == num {
            count++
        } else {
            count --
        }
    }
    return maybeMajor
}
```

# 2. Sort Array By Parity

https://leetcode.com/problems/sort-array-by-parity/

## 2.1. Summary

 - Use 2 pointers:
	 - One starts from beginning of the array
	 - One starts from ending of the array
 - Loop until 2 pointer points to same element
	 - If beginning pointer is pointing to odd number, swap it to ending pointer. Then ending pointer walks back 1 item
	 - If beginning pointer is pointing to even number, skip it and walk forward 1 item
 - End of the loop, the array will be sort 2 parts, even and odd numbers

## 2.2. Code

```go
func sortArrayByParity(nums []int) []int {
    left, right := 0, len(nums) - 1
    for {
        if left == right {
            break
        }
        
        if isOdd(nums[left]) {
            nums[left], nums[right] = nums[right], nums[left]
            right--
            continue
        }
        
        left++
    }
    return nums
}

func isEven(i int) bool {
    return i % 2 == 0
}

func isOdd(i int) bool {
    return i % 2 != 0
}
```

# 3. 3Sum

https://leetcode.com/problems/3sum/

## 3.1. Summary

- Break the big problem to smaller problems
- Big problem: find `i, j, k` with `i + j + k = 0`
- With each `i` as item in the array, find `j, k` with `j + k = -i`
- With each `i, k` as 2 items in the array, find `k` with `k = -i - j`

## 3.2. Code

```go
func threeSum(nums []int) [][]int {
    sort.Ints(nums)
    
    r := [][]int{}
    var previous int
    for index, item := range nums {
        if index > len(nums) - 3 {
            break
        }
        if index > 0 && previous == item {
            continue
        }
        previous = item
        
        if nums[index+1] + nums[index+2] > -item {
            continue
        }
        
        r2 := twoSum(0 - item, nums[index+1:])
        for index2 := range r2 {
            r2[index2] = append(r2[index2], item)
        }
        r = append(r, r2...)
    }
    return r
}

func twoSum(total int, nums []int) [][]int {
    r := [][]int{}
    var previous int
    for index, item := range nums {
        if index > len(nums) - 2 {
            break
        }
        if index > 0 && previous == item {
            continue
        }
        previous = item
        remaining := total - item
        
        if nums[index+1] > remaining {
            break
        }
        
        if findItem(remaining, nums[index+1: len(nums)]) {
            r = append(r, []int{item, remaining})
        }
    }
    return r
}

func findItem(v int, nums []int) bool {
    for _, item := range nums {
        if item > v {
            return false
        }
        if item == v {
            return true
        }
    }
    return false
}
```

# 4. 3Sum Closest

https://leetcode.com/problems/3sum-closest/

## 4.1. Summary

- Break the big problem to smaller problems
- Big problem: find `min = i + j + k`
- With each `i` as item in the array, find `j, k` with `j + k = min - i`
- With each `i, k` as 2 items in the array, find `k` with `k = min - i - j`

## 4.2. Code

```go
func threeSumClosest(nums []int, target int) int {
    sort.Ints(nums)
    
    min := int(math.MaxInt32)
    number := 0
    for i := 0; i < len(nums) - 2; i++ {
        for j := i+1; j < len(nums) - 1; j++ {
            for k := j+1; k < len(nums) - 0; k++ {
                sum := nums[i] + nums[j] + nums[k]
                remain := int(math.Abs(float64(sum - target)))
                if remain < min {
                    min = remain
                    number = sum
                }
            }
        }
    }
    return number
}
```
