# 202. Happy Number

## Approach - Hash map

We use a `HashMap<Integer, Boolean>` to keep track checked numbers. If a number is already in the HashMap, we can immediately return false since it loops endlessly in a cycle.
If the computed square is `1`, return true.

### Submission

```java
class Solution {
    public boolean isHappy(int n) {
        HashMap<Integer, Boolean> checked = new HashMap<>();
        
        checked.put(n, true);
        
        while (true) {
            int squared = computeSquare(n);
            
            if (squared == 1) return true;
            
            if (checked.getOrDefault(squared, false)) {
                return false;
            } else {
                checked.put(squared, true);
            }
            
            n = squared;
        }
    }

    public static int computeSquare(int n) {
        int sum = 0;
        while (n > 0) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }

        return sum;
    }
}
```

### Submission detail

402 / 402 test cases passed.
	Status: Accepted
Runtime: 1 ms
Memory Usage: 36.1 [MB](MB)

### Analyze

- Space complextiy: not O(1)

## Approach - Floyd Cycle Detection

We use *Floyd Cycle Detection* algorithm to detect an endless loop. For everything computeSquare value computed, we check if it equals to 1 or not. Our loop ends when we see `1` or endless loop detected.

### Submission

```java
class Solution {
    public boolean isHappy(int n) {
        int slow = n;
        int fast = n;

        while (slow != 1 && fast != 1) {
            slow = computeSquare(slow);
            fast = computeSquare(computeSquare(fast));
            if (slow == fast && slow != 1)
                return false;
        }

        return true;
    }

    public static int computeSquare(int n) {
        int sum = 0;
        while (n > 0) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }

        return sum;
    }
}
```

### Analyze

402 / 402 test cases passed.
	Status: Accepted
Runtime: 1 ms
Memory Usage: 35.8 MB

### Analyze

- Space complexity: O(1) as we don't need a HashMap to keep track.

# 1415. The k-th Lexicographical String of All Happy Strings of Length n 

## Approach - Recursion

We can simply have a tree as following:

![1415](https://user-images.githubusercontent.com/25602820/124357109-fa963680-dc43-11eb-80e0-1b663eb6beed.png)

With k = 1, we have an array as ["a", "b", "c"]
With k = 2, for each element in the above result, we append the corresponding next character as ["ab", "ac", "ba", "bc", "ca", "cb"]
...
With k = n, we have an array with 2^n length.

### Submission

```java
class Solution {
    HashMap<Character, String[]> h = new HashMap<>();
    public String getHappyString(int n, int k) {
        h.put('a', new String[]{"b", "c"});
        h.put('b', new String[]{"a", "c"});
        h.put('c', new String[]{"a", "b"});

        String[] r = recursive(n, h);
        if (r.length < k) {
            return "";
        }

        return r[k-1];
    }

    public static String[] recursive(int n, HashMap<Character, String[]> h) {
        if (n == 1) {
            return new String[]{"a", "b", "c"};
        }

        String[] child = recursive(n-1, h);
        String[] r = new String[child.length * 2];
        for (int i = 0; i < child.length; i++) {
            r[i*2] = child[i].concat(h.get(child[i].charAt(child[i].length() - 1))[0]);
            r[i*2+1] = child[i].concat(h.get(child[i].charAt(child[i].length() - 1))[1]);
        }

        return r;
    }
}
```

### Submission detail

345 / 345 test cases passed.
	Status: Accepted
Runtime: 17 ms

### Analyze

- Time complextiy 2^n
- Space complextiy 2^n

# 1405. Longest Happy String

## Approach - Greedy

We will add a valid character step by step, we have `total = a + b + c` steps.
For each step, we check if a character is valid to be add to final result.

We use 3 variables `countA`, `countB`, `countC` to keep track number of continous of each `a`, `b`, `c`.

An character, for example `a`, is valid to be added if:
- Remaining `a` is greater or equal than `b` or `c` and `countA` is not equal to 2.
- Or, we still have remaining `a` and `countB` or `countC` is equal to 2, we can not add `b` or `c` anymore.

After adding the character to final string, we remove it from store.

### Submission

```java
class Solution {
    public String longestDiverseString(int a, int b, int c) {
        StringBuilder str = new StringBuilder();
        int total = a + b + c;
        int countA = 0;
        int countB = 0;
        int countC = 0;
        for (int i = 0; i < total; i++) {
            if ((a >= b && a >= c && countA != 2) || (a > 0 && (countB == 2 || countC == 2))) {
                a--;
                countA++;
                str.append("a");
                countB = 0;
                countC = 0;
            } else if ((b >= a && b >= c && countB != 2) || (b > 0 && (countA == 2 || countC == 2))) {
                b--;
                countB++;
                str.append("b");
                countA = 0;
                countC = 0;
            } else if ((c >= b && c >= a && countC != 2) || (c > 0 && (countB == 2 || countA == 2))) {
                c--;
                countC++;
                str.append("c");
                countA = 0;
                countB = 0;
            }
        }

        return str.toString();
    }
}
```

### Submission detail

33 / 33 test cases passed.
	Status: Accepted
Runtime: 0 ms

### Analyze

- Space complexity: O(n) with n = a + b + c
- Time complexity: O(n) with n = a + b + c

# 1392. Longest Happy Prefix

## Approach

Use an array `lps` to keep track length of `Longest Happy Prefix`, and initialize `lps[0] = 0` as we don't see any same character before.

We also use a variable `len` to keeptrack the index of the last current longest length, and initilize it as `0`.


![step1](https://user-images.githubusercontent.com/25602820/124357916-18659a80-dc48-11eb-8211-d21b9a76ee1b.png)

Step by step, interate over the string `s`.

- If `s[i] == s[len]`, it means we have a new longest length. For example, with string `AAACAAAA` following:

![step2](https://user-images.githubusercontent.com/25602820/124358176-4bf4f480-dc49-11eb-96dd-56b0c807ba10.png)

we have new `len = 1`

- If not, we have to check it with previous character in string, by decrease the `len` until we see the same character or `len` is zero as we didn't see this character before.

![step3](https://user-images.githubusercontent.com/25602820/124358462-9cb91d00-dc4a-11eb-978f-ad5b72d5f31e.png)

Keep interate over the string, we have the following result

![final](https://user-images.githubusercontent.com/25602820/124358524-e6a20300-dc4a-11eb-8c6e-9018d0516262.png)


As you can see, the last `lps` is 2, it means we have the longest happy prefix string length is 2.

And you just return it.

### Submission

```java
class Solution {
    public String longestPrefix(String s) {
        int n = s.length();
        if (n == 1) {
            return "";
        }
        int[] lps = new int[n];
        lps[0] = 0;
        int len = 0;
        int i = 1;
        while (i < n) {
            if (s.charAt(i) == s.charAt(len)) {
                len++;
                lps[i++] = len;
            } else {
                if (len != 0) {
                    len = lps[len-1];
                } else {
                    lps[i++] = 0;
                }
            }
        }

        return s.substring(0, lps[n-1]);
    }
}
```

### Submission detail

74 / 74 test cases passed.
	Status: Accepted
Runtime: 8 ms

### Analyze

- Space complexity O(n)
- Time complexity O(n)

