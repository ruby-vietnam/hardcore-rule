## Problem 1

O(nLog(n))
```
func maximumProduct(nums []int) int {
	sort.Ints(nums)
	a := nums[0] * nums[1] * nums[len(nums)-1]
	b := nums[len(nums)-1] * nums[len(nums)-2] * nums[len(nums)-3]
	if a < b {
		return b
	}
	return a
}
```

O(n)
```
func maximumProductO(nums []int) int {
	var maxIndex0, maxIndex1, maxIndex2, minIndex0, minIndex1 = 0, 1, 2, 0, 1
	if nums[maxIndex0] < nums[maxIndex1] {
		maxIndex0, maxIndex1 = maxIndex1, maxIndex0
	}
	if nums[maxIndex0] < nums[maxIndex2] {
		maxIndex2, maxIndex0 = maxIndex0, maxIndex2
	}
	if nums[maxIndex1] < nums[maxIndex2] {
		maxIndex2, maxIndex1 = maxIndex1, maxIndex2
	}
	/*for i, num := range nums {
		if num > nums[maxIndex0] {
			maxIndex0 = i
		}
	}*/
	maxIndex0 = findMax(nums, maxIndex0, -1, -1)
	maxIndex1 = findMax(nums, maxIndex1, maxIndex0, -1)
	maxIndex2 = findMax(nums, maxIndex2, maxIndex0, maxIndex1)
	if nums[minIndex0] > nums[minIndex1] {
		minIndex0, minIndex1 = minIndex1, minIndex0
	}
	for i, num := range nums {
		if num < nums[minIndex0] {
			minIndex0 = i
		}
	}
	minIndex1 = findMin(nums, minIndex1, minIndex0)
	fmt.Println(maxIndex0, maxIndex1, maxIndex2, minIndex0, minIndex1)

	a := nums[maxIndex0] * nums[minIndex1] * nums[minIndex0]
	b := nums[maxIndex0] * nums[maxIndex1] * nums[maxIndex2]
	if a < b {
		return b
	}
	return a

}

func findMin(nums []int, init, minIndex1 int) int {
	minIndex := init
	for i, num := range nums {
		if num < nums[minIndex] && num >= nums[minIndex1] && i != minIndex1 {
			minIndex = i
		}
	}
	return minIndex
}

func findMax(nums []int, init, maxIndex1, maxIndex2 int) int {
	maxIndex := init
	for i, num := range nums {
		if num > nums[maxIndex] {
			if maxIndex1 >= 0 && (i == maxIndex1 || num > nums[maxIndex1]) {
				continue
			}

			if maxIndex2 >= 0 && (i == maxIndex2 || num > nums[maxIndex2]) {
				continue
			}
			maxIndex = i
		}
	}
	return maxIndex
}
```


## Problem 2
Division binary

https://en.wikipedia.org/wiki/Division_algorithm#Integer_division_(unsigned)_with_remainder

```go
func divide(dividend int, divisor int) int {
	maxInt := 1<<31 - 1
	minInt := -(1 << 31)

	if dividend > maxInt || dividend < minInt {
		return maxInt
	}

	if divisor > maxInt || divisor < minInt {
		return maxInt
	}

	t := 1
	if dividend < 0 {
		dividend = -dividend
		t = -t
	}
	if divisor < 0 {
		divisor = -divisor
		t = -t
	}

	if divisor == 0 {
		return maxInt
	}

	// https://en.wikipedia.org/wiki/Division_algorithm#Integer_division_(unsigned)_with_remainder
	quotation := 0
	remain := 0
	nBit := bitCount(dividend)
	if nBit == 0 {
		return 0
	}
	/*fmt.Println(nBit)*/
	var i uint
	for i = nBit - 1; i >= 0; i-- {
		remain = remain << 1                    // Left shift
		if getBitAtPosition(dividend, i) == 1 { // if dividend's bit at position i is 1 then update remain significant bit
			remain = remain | 1 // OR with 1
		}
		if remain >= divisor {
			remain = remain - divisor
			quotation = toggleBitAtPosition(quotation, i)
		}
		/*fmt.Println("Bits:", i)
		printBit("Remain:", remain)
		printBit("Quotation:", quotation)*/
		if i == 0 {
			break
		}

	}
	if t < 0 {
		quotation = -quotation
	}
    
    	if quotation > maxInt || quotation < minInt {
		return maxInt
	}


	return quotation
}

func toggleBitAtPosition(number int, i uint) int {
	return number | (1 << i) // left shift 1 to i then OR with number. Ex: i=3, n=5=101 => 1 << 3 = 1000; 0101 | 1000 = 1101
}

func bitCount(n int) uint {
	var count uint
	for n > 0 {
		count++
		n = n >> 1 // Left shift
	}
	return count
}

func getBitAtPosition(number int, i uint) int {
	return getLeastSignificantBit(number >> i)
}

func getLeastSignificantBit(number int) int {
	return number & 1
}
```
