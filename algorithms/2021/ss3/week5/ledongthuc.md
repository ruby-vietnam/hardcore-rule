# 1. Excel Sheet Column Title

 - 1  -> 26: A -> Z | 26 / (26 + 1)
 - 27 -> 52: AA -> AZ | 52 / (26 + 1)
 - 53 -> 78: BA -> BZ | 78 / (26 + 1)

```go
func convertToTitle(n int) string {
    var result string
    for n > 0 {
        remain := n % 26
        if remain == 0 {
            result = "Z" + result
            n = (n / 26) -1
        } else {
            result = string(rune(remain - 1 + 65)) + result
            n = n / 26
        }
    }
    return result
}

/*

52 % 26 = 0
52 / 26 = 2

1  -> 26: A -> Z | 26 / (26 + 1)
27 -> 52: AA -> AZ | 52 / (26 + 1)
53 -> 78: BA -> BZ | 78 / (26 + 1)

*/
```

# 2. Climbing Stairs

 - Fibonanci detected
 - N = 3, ways = 1 + 2
 - N = 4, ways = 3 + 2
 - N = 5, ways = 4 + 3
 - etc

```go
func climbStairs(n int) int {
	if n <= 2 {
		return n
	}

	n1 := 1
	n2 := 2
	for i := 2; i < n; i++ {
		n1, n2 = n2, n1+n2
	}

	return n2
}
```

# 3. House Robber

 - Dynamic programming
 - Best property of ropped houses you can do of N is maximum of:
   - Best property of ropped houses of N-1 (skip this turn)
   - Best property of ropped houses of N-2 + N (skip last turn)

```go
func rob(nums []int) int {
    length := len(nums)
    switch length {
    case 0:
        return 0
    case 1:
        return nums[0]
    default:
        bests := make([]int, length)
	    bests[0] = nums[0]
        bests[1] = max(nums[0], nums[1])
        for i := 2; i < length; i++ {
            bests[i] = max(bests[i-1], bests[i-2] + nums[i]);
        }
        return bests[length-1]; 
    }
}

func max(a,b int) int {
    if a>b {
        return a
    }
    return b
}
```

# 4. House Robber II

 - Dynamic programming
 - Best properties you got from 0 to N is maximum of:
   - Best properties you got from 1 to N
   - Best properties you got from 0 to N-1

```go
func rob(nums []int) int {
    if len(nums) == 0 {
        return 0;
    }
    if len(nums) == 1 {
        return nums[0]
    }
    if len(nums) == 2 {
        return max(nums[0], nums[1])
    }

    return max(sub(nums[:len(nums)-1]), sub(nums[1:]))
}

func sub(nums []int) int {
    var currMax, last, tmp int
    for i := range nums {
        tmp = currMax
        currMax = max(currMax, last + nums[i])
        last = tmp
    }
    return currMax
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
```
