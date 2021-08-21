# 1961. Check If String Is a Prefix of Array

### Approach

We use a StringBuilder `sb` to concatenate word in `words` array.
And then take a loop on the `words` array, for each word, we append the it to the `sb` and increase the length of `sb`.
The loop ends when the length of `sb` is greater than `s.length()`.

Finally, we check if `sb` equals to `s` or not.

### Submission

```java
class Solution {
    public boolean isPrefixString(String s, String[] words) {
        int l = s.length();
        StringBuilder sb = new StringBuilder();
        int c = 0;
        int i = 0;
        while (c < l && i < words.length) {
            c += words[i].length();
            sb.append(words[i]);
            i++;
        }
        
        if (c == l && s.equals(sb.toString()))
            return true;
        
        return false;
    }
}
```

### Submission detail

349 / 349 test cases passed.
	Status: Accepted
Runtime: 1 ms
Memory Usage: 39.5 MB

### Analyze

- Time complexity: O(n)
- Space complexity: O(n)


# 1967. Number of Strings That Appear as Substrings in Word

### Approach

Just go through of `patterns` and check if `word.indexOf(patterns[i]) > 0`

### Submission

```java
class Solution {
    public int numOfStrings(String[] patterns, String word) {
        int c = 0;
        for (String p: patterns) {
            if (word.indexOf(p) >= 0) {
                c++;
            }
        }
        
        return c;
    }
}
```

### Submission detail

82 / 82 test cases passed.
	Status: Accepted
Runtime: 0 ms
Memory Usage: 39.2 MB

### Analyze

- Time complexity: O(n * m * k)
- Space comlexity: O(1)

# 1968. Array With Elements Not Equal to Average of Neighbors


### Approach

To guarantee the element doesn't equal the average of neighbors, we have two options:

- `nums[i-1] > nums[i] < nums[i+1]`

e.g. 

```
       1
      / \
     2   3  
```
- `nums[i] < nums[i] > nums[i+1]`

e.g.

```
       3
      / \
     1   2
```
     
To do that, we go through the `nums` and swap elements to keep the increasing order and decreasing order sequence.

```
      3   5
     / \ / \
    1   2   4 
``` 

### Submission

```java
class Solution {
    public int[] rearrangeArray(int[] nums) {
        boolean isIncreasing = nums[0] < nums[1]; // determine the increasing/decreasing order
        for (int i = 1; i < nums.length - 1; i++) {
            if ((isIncreasing && nums[i] < nums[i+1]) || (!isIncreasing && nums[i] > nums[i+1])) {
                int tmp = nums[i];
                nums[i] = nums[i+1];
                nums[i+1] = tmp;
            }

            isIncreasing = !isIncreasing; // toggle the increasing/decreasing sequence
        }

        return nums;
    }
}
```

### Submission detail

249 / 249 test cases passed.
	Status: Accepted
Runtime: 8 ms
Memory Usage: 151.8 MB

### Analyze

- Time comlexity: O(n)
- Space complexity: O(1)


