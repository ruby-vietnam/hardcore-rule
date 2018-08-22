# Problem 1

## [K-based Numbers](http://acm.timus.ru/problem.aspx?space=1&num=1009)
```java
static class Task {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        long[][] f = new long[n][2];
        f[0][0] = 0;
        f[0][1] = k - 1;
        for (int i = 1; i < f.length; i++) {
            // is zero
            f[i][0] = f[i - 1][1];
            // not zero
            f[i][1] = (f[i - 1][1] + f[i - 1][0]) * (k - 1);
        }

        out.println(f[f.length - 1][0] + f[f.length - 1][1]);
    }

}
```
