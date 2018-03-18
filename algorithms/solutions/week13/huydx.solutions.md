# Problem 1

```java
class Solution {

    public int maximumProduct(int[] nums) {
        int[] max = new int[3];
        int[] min = new int[2];
        System.arraycopy(nums, 0, max, 0, 3);
        System.arraycopy(nums, 0, min, 0, 2);

        if (nums.length == 3) { return nums[0] * nums[1] * nums[2]; }

        for (int n = 0; n < nums.length; n++) {
            if (n >= 3) {
                // maintain max 3
                maintainMax(max, nums[n]);
            }
            if (n >= 2) {
                // maintain min 2
                maintainMin(min, nums[n]);
            }
        }
        return max(max[0]*max[1]*max[2], max[2]*min[0]*min[1]);
    }

    public void maintainMax(int[] windows, int num) {
        int tmp;
        for (int i = windows.length-1; i >= 0; i--) {
            if (num > windows[i]) {
                tmp = windows[i];
                windows[i] = num;
                num = tmp;
            }
        }
    }


    public void maintainMin(int[] windows, int num) {
        int tmp;
        for (int i = 0; i < windows.length; i++) {
            if (num < windows[i]) {
                tmp = windows[i];
                windows[i] = num;
                num = tmp;
            }
        }
    }

    public int max(int a, int b) {
        return a >= b ? a : b;
    }
}
```


# Problem 3

```java
class Solution {
    static class ParseException extends RuntimeException {
        public ParseException(String message) {
            super(message);
        }
    }
    

    public boolean isNumber(String s) {
        s = s.trim(); // trim space
        if (s.length() == 0) { return false; }

        try {
            if (s.charAt(0) == '+' || s.charAt(0) == '-') {
                parseNumAny(s.substring(1, s.length()));
            } else {
                parseNumAny(s);
            }
        } catch (ParseException ignored) {
            System.out.println(ignored + s);
            return false;
        }
        return true;
    }

    public static void parseNumAny(String s) {
        for (int i = 0; i < s.length(); i++) {
            if (isNum(s.charAt(i))) {
                continue;
            }
            if (s.charAt(i) == '.') {
                parseFraction(s.substring(0, i), s.substring(i+1, s.length()));
                return;
            }
            if (s.charAt(i) == 'e') {
                parsePower(s.substring(0, i), s.substring(i+1, s.length()));
                return;
            }
            throw new ParseException(String.format("unexpected %c at parseNumAny", s.charAt(i)));
        }
    }

    public static void parseFraction(String first, String s) {
        if (first.length() > 0 && s.length() == 0) { return; }
        if (s.length() == 0) {
            throw new ParseException("unexpected length 0 string at parseFraction");
        }
        if (first.length() == 0 && !isNum(s.charAt(0))) {
            throw new ParseException(String.format("unexpected %c at parseFraction", s.charAt(0)));
        }
        for (int i = 0; i < s.length(); i++) {
            if (isNum(s.charAt(i))) {
                continue;
            }
            if (s.charAt(i) == 'e') {
                parsePower(first + "." + s.substring(0, i), s.substring(i+1, s.length()));
                return;
            }
            throw new ParseException(String.format("unexpected %c at parseFraction", s.charAt(i)));
        }
    }

    public static void parsePower(String first, String s) {
        if (first.length() == 0) {
            throw new ParseException("unexpected length 0 string at parsePower");
        }
        if (s.length() == 0) {
            throw new ParseException("unexpected length 0 string at parsePower");
        }
        if (s.charAt(0) == '-' || s.charAt(0) == '+') {
            parseSeqNumber(s.substring(1, s.length()));
            return;
        }
        for (int i = 0; i < s.length(); i++) {
            if (isNum(s.charAt(i))) {
                continue;
            }
            throw new ParseException(String.format("unexpected %c at parsePower", s.charAt(i)));
        }
    }

    public static void parseSeqNumber(String s) {
       if (s.length() == 0) {
           throw new ParseException("unexpected empty string at parseSeqNumber");
       }
       for (int i = 0; i < s.length(); i++) {
            if (isNum(s.charAt(i))) {
                continue;
            }
            throw new ParseException(String.format("unexpected %c at parseSeqNumber", s.charAt(i)));
        }
    }

    public static boolean isNum(char c) {
        return c >= '0' && c <= '9';
    }
}
```
