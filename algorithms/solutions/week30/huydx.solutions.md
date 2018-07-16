# Problem 1
Idea: trivial

```java
import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the miniMaxSum function below.
    static void miniMaxSum(int[] arr) {
        long sum = 0;
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        for (int a : arr) {
            sum += a;
            if (a <= min) {
                min = a;
            }
            if (a >= max) {
                max = a;
            }
        }
        System.out.printf("%d %d", sum-max, sum-min);
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int[] arr = new int[5];

        String[] arrItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < 5; i++) {
            int arrItem = Integer.parseInt(arrItems[i]);
            arr[i] = arrItem;
        }

        miniMaxSum(arr);

        scanner.close();
    }
}
```

# Problem 2

Idea: trie with stored count number at leaf

```java
import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    static class Node {
        char val;
        boolean leaf;
        int num;
        Map<Character, Node> childs;

        Node(char val, int num) {
            this.val = val;
            this.num = num;
            this.childs = new HashMap<>();
        }
    }

    static void insert(Node cur, String in) {
        for (int i = 0; i < in.length(); i++) {
            char c = in.charAt(i);
            if (cur.childs.get(c) != null) {
                cur = cur.childs.get(c);
                if (i == in.length()-1) {
                    if (cur.leaf) {
                        cur.num += 1;
                    }
                }
            } else {
                Node n = new Node(c, 0);
                cur.childs.put(c, n);
                cur = n;
            }
        }
        cur.leaf = true;
        if (cur.num == 0) {
            cur.num = 1;
        }
    }

    static int search(Node cur, String in) {
        for (char c : in.toCharArray()) {
            Node next = cur.childs.get(c);
            if (next == null) {
                return 0;
            } else {
                cur = next;
            }
        }

        // only found if cur is leaf
        if (cur.leaf) {
            return cur.num;
        } else {
            return 0;
        }
    }

    // Complete the matchingStrings function below.
    static int[] matchingStrings(String[] strings, String[] queries) {
        int[] ret = new int[queries.length];
        Node tree = new Node('x', 0); //root
        for (String s : strings) {
            insert(tree, s);
        }
        for (int i = 0; i < queries.length; i++) {
            ret[i] = search(tree, queries[i]);
        }
        return ret;
    }


    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int stringsCount = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        String[] strings = new String[stringsCount];

        for (int i = 0; i < stringsCount; i++) {
            String stringsItem = scanner.nextLine();
            strings[i] = stringsItem;
        }

        int queriesCount = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        String[] queries = new String[queriesCount];

        for (int i = 0; i < queriesCount; i++) {
            String queriesItem = scanner.nextLine();
            queries[i] = queriesItem;
        }

        int[] res = matchingStrings(strings, queries);

        for (int i = 0; i < res.length; i++) {
            bufferedWriter.write(String.valueOf(res[i]));

            if (i != res.length - 1) {
                bufferedWriter.write("\n");
            }
        }

        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}

```
