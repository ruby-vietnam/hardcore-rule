# 1. Number of Strings That Appear as Substrings in Word

https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/

## 1.1. Summary

 - Loop through pattern and check any pattern is existed in the word.

## 1.2. Code

```go
func numOfStrings(patterns []string, word string) int {
    var count int
    for _, pattern := range patterns {
        if strings.Contains(word, pattern) {
            count++
        }
    }
    return count
}
```

# 2. Check If String Is a Prefix of Array

https://leetcode.com/problems/check-if-string-is-a-prefix-of-array/

## 2.1. Code

```go
func isPrefixString(s string, words []string) bool {
    if len(words) == 0 && len(s) > 0 {
        return false
    }
    if len(s) < len(words[0]) {
        return false
    }
    if len(s) == len(words[0]) {
        return strings.HasPrefix(words[0], s)
    }
    if !strings.HasPrefix(s, words[0]) {
        return false
    }
    return isPrefixString(s[len(words[0]):], words[1:])
}
```

# 3. Check If String Is a Prefix of Array

https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/

## 3.1. Summary

 - Go through item in array `nums` except first and last item.
	 - If the item is equal to the average of its neighbors, then swap it with next item
	 - Continue the looping through all item until no item is equal to the average of its neighbors

## 3.2. Code

```go
func rearrangeArray(nums []int) []int {
    isContinue := true
    for isContinue {
        isContinue = false
        for i:=1; i< len(nums) -1; i++ {
            if (2 * nums[i] == nums[i-1] + nums[i+1]) {
                isContinue = true
                nums[i], nums[i+1] = nums[i+1], nums[i]
            }
        }
    }
    return nums;
}
```

