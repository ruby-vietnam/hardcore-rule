Problem 1

```java
class Solution {    
    // n k
    // n >= k
    int[][] memoize = new int[1000][1000];
    
    public List<Integer> getRow(int rowIndex) {
        memoize[0][0] = 1;
        memoize[1][0] = 1;
        memoize[1][1] = 1;
        memoize[2][0] = 1;
        memoize[2][1] = 2;
        memoize[2][2] = 1;
        List<Integer> ret = new ArrayList<>();
        int n = rowIndex;
        for (int k = 0; k <= n; k++) {
            ret.add(k, comb(n,k));
        }
        return ret;
    }
    
    
    // using recursive function (n k) = (n-1 k-1) + (n-1 k)
    int comb(int n, int k) {
        assert ( n >= 0 );
        assert ( k >= 0 );
        assert ( n >= k );
        if (n == 0 || k == 0 || n == k) { return 1; }
        
        if (memoize[n-1][k-1] == 0) {
            memoize[n-1][k-1] = comb(n-1,k-1);
        }
        if (memoize[n-1][k] == 0) {
            memoize[n-1][k] = comb(n-1,k);
        }
        return memoize[n-1][k-1] + memoize[n-1][k];
    }
}
```

Problem 2

```java
class Solution {
    Stack<Character> stack = new Stack<>();
    public boolean checkValidString(String s) {
      for (char c : s.toCharArray()) {
            if (c == '(' || c == '*') {
                stack.push(c);
            }
            if (c == ')') {
                if (stack.size() == 0) {
                    return false;
                }
                List<Character> buff = new ArrayList<>();
                while (true) {
                    if (stack.size() == 0) {
                        for (char d : buff) {
                            stack.push(d);
                        }
                        stack.push(')');
                        break;
                    }
                    char b = stack.pop();
                    if (b == '(') {
                        for (char d : buff) {
                            stack.push(d);
                        }
                        break;
                    } else {
                        buff.add(b);
                    }
                }
            }
        }
        System.out.println("stack" + "::" +stack);
        if (stack.size() == 0) {return true;}
        Stack<Character> stack2 = new Stack<>();
        while (true) {
            if (stack.size() == 0) {
                break;
            }
            char c = stack.pop();
            if (stack2.size() == 0) {
                stack2.push(c);
            } else {
                char d = stack2.pop();
                if (c == '(' && d == '*') {
                    System.out.println("cancel");
                    continue;
                }
                if (c == '*' && d == ')') {
                    System.out.println("cancel");
                    continue;
                }
                if (c == '*' && d == '*') {
                    stack2.push('*');
                    stack2.push('*');
                    continue;
                }
                if (c == ')' && d == '*') {
                    stack2.push(')');
                    continue;
                }
                System.out.printf("false with c %s, d %s\n", c, d);
                return false;
            }
        }
        if (stack2.size() == 0) {
            return true;
        }
        if (stack2.peek() == '*') {
            return true;
        }
        return false;
    }
}
```
