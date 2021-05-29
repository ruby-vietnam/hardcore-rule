# 67. Add Binary

### Approach

Our naive approach follows the simple follwing table:

| a   | b           | sum      | accumulator |
| --- | ----------- | -------- | ---------   |
| 0   | 0           | 0        | 0           |
| 0   | 1           | 1        | 0           |
| 1   | 1           | 0        | 1           |

In case, the number of binary of two string is not equal, we have to keep the accumulator and add the the remaining binary.

At the end, if the accumulator is `1` we just need to simply add it to the start of result string.

### Submission

```java
public String addBinary(String a, String b) {
        int i = a.length() - 1;
        int j = b.length() - 1;
        int curr = '0';
        StringBuilder result = new StringBuilder();

        if (i < j) {
            String temp = a;
            a = b;
            b = temp;
        }

        while (i >= 0 && j >= 0) {
            char ai = a.charAt(i);
            char bj = b.charAt(j);
            if (ai == bj) {
                result.insert(0, (char) curr);
                if (ai == '0') {
                    curr = '0';
                } else {
                    curr = '1';
                }
            } else {
                if (curr == '0') {
                    result.insert(0, '1');
                } else {
                    result.insert(0, '0');
                }
            }
            i--;
            j--;
        }

        if (i >= 0) {
            if (curr == '0') {
                result.insert(0, a.substring(0, i+1));
            } else {
                while (i >= 0) {
                    char ai = a.charAt(i);
                    if (ai == '1') {
                        if (curr == '0') {
                            result.insert(0, '1');
                        } else {
                            result.insert(0, '0');
                        }
                    } else {
                        result.insert(0, (char) curr);
                        curr = '0';
                    }
                    i--;
                }
            }
        }

        if (curr == '1') {
            result.insert(0, (char) curr);
        }

        return result.toString();
    }
}
```

### Submission detail

| Status   | Runtime     | Memory   | Language  |
| ---      | ----------- | -------- | --------- |
| Accepted | 2ms         | 37.6 MB  | java      |

### Analyze
- Time complexity: O(m + n), n and m is the length of a and b
- Space complexity: O(1)

# 43. Multiply Strings

### Approach

As we've been tought in the school how to multiply two numbers, we're gonna use the same technique
![multiply](https://user-images.githubusercontent.com/25602820/120076548-4d725080-c0d0-11eb-8425-a5d1385976cf.png)

But first, we have to write a helper function which helps us to sum two numbers.

```java
public static String addTwoString(String num1, String num2) {
    StringBuilder ret = new StringBuilder();

    if (num1.length() < num2.length()) { // swap
        String temp = num1;
        num1 = num2;
        num2 = temp;
    }

    int l1 = num1.length() - 1;
    int l2 = num2.length() - 1;
    int curr = 0;

    while (l1 >= 0 && l2 >= 0) {
        int temp = Integer.parseInt(String.valueOf(num1.charAt(l1))) + Integer.parseInt(String.valueOf(num2.charAt(l2))) + curr;
        if (temp >= 10) {
            ret.insert(0, (temp - 10));
            curr = 1;
        } else {
            ret.insert(0, temp);
            curr = 0;
        }

        l1--;
        l2--;
    }

    if (l1 >= 0) {
        while (l1 >= 0) {
            int temp = Integer.parseInt(String.valueOf(num1.charAt(l1))) + curr;
            if (temp >= 10) {
                ret.insert(0, (temp - 10));
                curr = 1;
            } else {
                ret.insert(0, temp);
                curr = 0;
            }
            l1--;
        }
    }

    if (curr > 0) {
        ret.insert(0, curr);
    }

    return ret.toString();
}
```

We use the same technique with an accumulator as the first problem.

And how to multiple a string with one-length string? Just add it and itself `n` times.

After we have the result with each number, we have to add these values together to have the correctly value. We need to add `0`s to the end of each numbers as:
![adding 0](https://user-images.githubusercontent.com/25602820/120076772-7c3cf680-c0d1-11eb-8cae-e5e637613648.png)

And we sum these strings together.

### Submission

```java
class Solution {
    public String multiply(String num1, String num2) {
        String ret = "0";

        for (int i = 0; i < num2.length(); i++) {
            String tmp = multiplyWithSingleNumber(num1, Integer.parseInt(String.valueOf(num2.charAt(i))));
            if (!tmp.equals("0")) {
                for (int j = 0; j < num2.length() - i - 1; j++) {
                    tmp = tmp.concat("0");
                }
            }

            ret = addTwoString(ret, tmp);
        }

        return ret;
    }

    private static String multiplyWithSingleNumber(String num1, int n) {
        String ret = "0";
        for (int i = 0; i < n; i++) {
            ret = addTwoString(ret, num1);
        }

        return ret;
    }

    private static String addTwoString(String num1, String num2) {
        //   7 3 8
        // 6 1 5 0
        // 6 8 8 8

        StringBuilder ret = new StringBuilder();

        if (num1.length() < num2.length()) { // swap
            String temp = num1;
            num1 = num2;
            num2 = temp;
        }

        int l1 = num1.length() - 1;
        int l2 = num2.length() - 1;
        int curr = 0;

        while (l1 >= 0 && l2 >= 0) {
            int temp = Integer.parseInt(String.valueOf(num1.charAt(l1))) + Integer.parseInt(String.valueOf(num2.charAt(l2))) + curr;
            if (temp >= 10) {
                ret.insert(0, (temp - 10));
                curr = 1;
            }  else {
                ret.insert(0, temp);
                curr = 0;
            }

            l1--;
            l2--;
        }

        if (l1 >= 0) {
            while (l1 >= 0) {
                int temp = Integer.parseInt(String.valueOf(num1.charAt(l1))) + curr;
                if (temp >= 10) {
                    ret.insert(0, (temp - 10));
                    curr = 1;
                }  else {
                    ret.insert(0, temp);
                    curr = 0;
                }
                l1--;
            }
        }

        if(curr > 0) {
            ret.insert(0, curr);
        }

        return ret.toString();
    }
}
```

### Submission detail 

| Status   | Runtime     | Memory   | Language  |
| ---      | ----------- | -------- | --------- |
| Accepted | 229ms       | 114.4 MB | java      |

### Analyze

- Time complexity: O(m*n) as m and n is the number of num1 and num2
- Space complextiy: O(1)
