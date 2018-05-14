Problem 1: 

Use counter:
```go
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

Use map:
```go
func majorityElement(nums []int) int {
    n := len(nums) / 2
    m := make(map[int]int)
    for _, num := range nums {
        m[num] = m[num] + 1
        if m[num] > n {
            return num
        }
    }
    return -1
}
```

Problem 2:

```go
func bulbSwitch(n int) int {
	var index, previous, current, multiple int
    index = 1
    multiple = 1

	for index <= n {
		for index < multiple*multiple && index <= n {
			current = previous
			index++
		}
		
		if index <= n {
			current = previous + 1
		}
        
        index++
        multiple++
		previous = current
	}
	return current
}
```

```
- Gọi N là số đèn 
- I là số lần switch đèn. I -> K
- Với 1 cái đèn bất kì K, nó chỉ dc switch khi I là thừa số của K. 
- Vd: đèn k = 10 chỉ dc đụng tới khi I là 2, 5, 10  => 2 * 5  = 10. => trong trường hợp này bị đụng 3 lần: 2 lúc I = thừa số là 1 lần lúc I=10). đèn K sẽ tắt.
- Vd khác: đèn k = 100, sẽ tách ra thành các cặp thừa số: (2*50),  (4*25), (5*20),  (10*10) =>  dc đụng 8 lần, 7 lần lúc I = thừa số và 1 lần lúc I= 100. Đèn K mở. Trong trường hợp này, do thừa số 10 lúc này chỉ dc gọi 1 lần thôi :)

- Tổng quát lại là đèn K chỉ khi  K = a ^ 2. Tức là bài này đi tìm có bao nhiêu số nhỏ hơn hoặc bằng và có K = a ^ 2
```

```go
func bulbSwitch(n int) int {
    i := 1
    for i*i <= n {
        i++
    }
    return i-1
}
```

```go

func bulbSwitch(n int) int {
    return int(math.Sqrt(float64(n)))
}
```
