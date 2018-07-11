# Problem 2
// This solution did not passed, don't know why.. >.<

```java
import java.util.Deque;
import java.util.LinkedList;
import java.util.Scanner;
//
public class Main {
    static class Elem {
        int val;
        int step;
        Elem(int val, int step) {
            this.val = val;
            this.step = step;
        }
    }
    public static void main (String[] args) throws java.lang.Exception {
        try {
            Scanner sc = new Scanner(System.in);
            int f = sc.nextInt();
            int s = sc.nextInt();
            int g = sc.nextInt();
            int u = sc.nextInt();
            int d = sc.nextInt();

            Deque<Elem> queue = new LinkedList<>();
            boolean[] visited = new boolean[10000];
            queue.offer(new Elem(s, 0));
            while (true) {
                if (queue.isEmpty()) {
                    break;
                }
                Elem c = queue.poll();
                int next1 = c.val + u;
                int next2 = c.val - d;
                if (next1 == g || next2 == g) {
                    System.out.print(c.step + 1);
                    return;
                }
                if (next1 <= f && !visited[next1]) {
                    queue.offer(new Elem(next1, c.step + 1));
                    visited[next1] = true;
                }
                if (next2 >= 0 && !visited[next2]) {
                    queue.offer(new Elem(next2, c.step + 1));
                    visited[next2] = true;
                }
            }
            System.out.print("use the stairs");
        } catch (Exception e) {
            System.out.print(e);
        }
    }
}
```

# Problem 3
```java
public class Main {
    public static void main (String[] args) throws java.lang.Exception {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k1 = sc.nextInt();
        int k2 = sc.nextInt();
        int k = k1+k2;
        int[] a = new int[n];
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            b[i] = sc.nextInt();
        }

        int[] c = new int[n];
        long sum = 0;
        for (int i = 0; i < n; i++) {
            c[i] = Math.abs(a[i] - b[i]);
            sum += (long)c[i]*c[i];
        }

        TreeSet<Integer> treeMax = new TreeSet<>(Comparator.reverseOrder()); // tree sort by max
        for (int ci : c) {
            treeMax.add(ci);
        }
        while (true) {
            if (k==0) { // out of move
                long sum2 = 0;
                for (Integer i : treeMax) {
                    sum2 += i * i;
                }
                System.out.println(sum2);
                return;
            }
            k--;
            int m = treeMax.pollFirst();
            if (m == 0) { // max is 0, so all element is 0
                if (k%2==1) {
                    System.out.println(1);
                    return;
                } else {
                    System.out.println(0);
                    return;
                }
            }

            sum -= 2*m;
            treeMax.remove(m);
            treeMax.add(m-1);
        }
    }
}
```
