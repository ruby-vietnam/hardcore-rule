# Easy: Add Binary

https://leetcode.com/problems/add-binary/

### Approach

Interate through two strings together in reverse order, adding their values and calculate the carry after every iteration. The iteration will stop when all characters in two strings have been iterated or when there is no carry left.

Since two values are either 0 or 1 at each interation, the carry is calculated as follow:
```
sum = num1[i] + num2[i] + carry
carry = sum / 2
```

Similar problem: https://leetcode.com/problems/add-two-numbers/.

### Code (Go)

```go
import "strconv"

func addBinary(a string, b string) string {
	res, len1, len2, carry := "", len(a), len(b), 0

	for len1 > 0 || len2 > 0 || carry != 0 {
		sum := carry
		if len1 > 0 {
			sum += int(a[len1-1] - '0')
			len1--
		}
		if len2 > 0 {
			sum += int(b[len2-1] - '0')
			len2--
		}
		res, carry = strconv.Itoa(sum%2)+res, sum/2
	}
	return res
}
```

Time complexity: O(max(num1.length, num2.length)).

### Submission Detail

```
294 / 294 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 2.6 MB
```

# Medium: Multiply Strings

https://leetcode.com/problems/multiply-strings/

### Approach

The approach is based on school mathematics:

![image](https://gblobscdn.gitbook.com/assets%2F-M1hB-LnPpOmZGsmxY7T%2F-M1hLFkgfil-EhOB1ON_%2F-M1hLHas_CYivhmCvw6L%2F3.jpg?alt=media)

### Code (Go)

```go
func multiply(num1 string, num2 string) string {
	if num1 == "0" || num2 == "0" {
		return "0"
	}

	len1, len2 := len(num1), len(num2)
	result := make([]byte, len1+len2)
	for i := range result {
		result[i] = '0'
	}

	for i := len1 - 1; i >= 0; i-- {
		for j := len2 - 1; j >= 0; j-- {
			mul := (num1[i] - '0') * (num2[j] - '0')
			sum := result[i+j+1] - '0' + mul
			result[i+j+1] = sum%10 + '0'
			result[i+j] = (result[i+j] - '0' + sum/10) + '0'
		}
	}

	if result[0] == '0' {
		return string(result[1:])
	}
	return string(result)
}
```

Time complexity: O(num1.length * num2.length), space complexity: O(num1.length + num2.length).

### Submission Detail

```
311 / 311 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 2.3 MB
```
