# 1. Two Sum

### Approach - HashMap

We will iterate over the `nums` and use a `HashMap<Integer, Integer>` to keep track the value and index of traversed item. For each item, we check the HashMap, if HashMap contains the item which equals to `int remaining = target - nums[i]`, so we can directly return the `new int[]{i, h.get(remaining)`

### Submission

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> h = new HashMap();

        for (int i = 0; i < nums.length; i++) {
            int remaining = target - nums[i];
            if (h.containsKey(remaining)) {
                return new int[]{i, h.get(remaining)};
            } else {
                h.put(nums[i], i);
            }
        }

        return new int[]{0,0}; // never reach here
    }
}
```

### Submission detail

54 / 54 test cases passed.
Status: Accepted
Runtime: 3 ms
Memory Usage: 42.3 MB

### Analyze

- Space complexity O(n)
- Time complexity O(n)

# 20. Valid Parentheses

Firstly, we create a `HashMap<Character, Character>` for storing the pairs.

```java
pairs.put(')', '(');
pairs.put('}', '{');
pairs.put(']', '[');
```
We will go to iterate over the string, and use a stack to keep track the number of opening bracket.
For each character we iterated, if it is a open bracket we will put it in the Stack, otherwise, if it is an close bracket:
- if the stack is already empty, we will immediately return `false` as we can not close the bracket before opening it.
- peek the top of stack, if they are not in pair, return `false`. If not, pop it from the stack

At the end, if the stack is empty, we return `true` otherwise, return `false`.

### Submission

```java
class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        HashMap<Character, Character> pairs = new HashMap<>();
        pairs.put(')', '(');
        pairs.put('}', '{');
        pairs.put(']', '[');

        for (char c: s.toCharArray()) {
            if (c == ')' || c == ']' || c == '}') {
                if (stack.isEmpty())
                    return false;

                if (stack.peek() == pairs.get(c)) {
                    stack.pop();
                } else {
                    return false;
                }
            } else {
                stack.push(c);
            }
        }

        return stack.isEmpty();
    }
}
```

### Submission detail

91 / 91 test cases passed.
Status: Accepted
Runtime: 3 ms

### Analyze

- Space complexity O(n)
- Time complexity O(n)

# 22. Generate Parentheses

Use backtracking.


### Submission

```java
class Solution {
   public List<String> generateParenthesis(int n) {
        List<String> r = new ArrayList<>();
        backtrack(r, "", 0, 0, n);

        return r;
    }

    public void backtrack(List<String> r, String current, int open, int close, int n) {
        if (current.length() == n * 2) {
            r.add(current);
            return;
        }

        if (open < n) backtrack(r, current + "(", open + 1, close, n);
        if (close < open) backtrack(r, current + ")", open, close + 1, n);
    }
}
```

### Submission detail

8 / 8 test cases passed.
Status: Accepted
Runtime: 1 ms

### Analyze

- Time complexity O(2 ^ 2n)
- Space complexity O(n)

# 371. Sum of Two Integers

The idea is using bit mutation istead of directly `+` operator.

Let's examine how the `+` work with Decimal, say that, we have to calculate the sum if `759` and `674`:
- If we try to add each number without the "carry", we have: 759 + 674 = 323
- Without the addtion, just care about carry, we have: 759 + 674 = 1110
- Merge two results together, we have 1433. That's exactly result.

So, we can do the same thing with bits maniplulation.

- Add each number without "carry", we will get `0` in cases, both a[i] and b[i] are the same, both are `0` or `1`. It's XOR manipulation.
- Without addtion, just care about "carry", the `i-th` bit would be `1` if both a[i-1] and b[i-1] are `1`. This is an AND and left shift.

### Submission

```java
class Solution {
    public int getSum(int a, int b) {
        return b == 0 ? a : getSum(a ^ b, (a & b) << 1);
    }
}
```

### Submission detail

Runtime: 0 ms
Memory Usage: 35.9 MB
