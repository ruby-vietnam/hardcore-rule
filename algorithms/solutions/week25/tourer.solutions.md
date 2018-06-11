# Problem 1

## [Keyboard Row](https://leetcode.com/problems/keyboard-row/description/)
```java
class Solution {
    public String[] findWords(String[] words) {
        char[][] a = new char[3][];
        a[0] = new char[]{'q','w','e','r', 't', 'y', 'u', 'i', 'o', 'p'};
        a[1] = new char[]{'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
        a[2] = new char[]{'z', 'x', 'c', 'v', 'b', 'n', 'm'};
        
        boolean[] ok = new boolean[words.length];
        int cnt = 0;
        for(int i = 0; i < words.length; i++) {
            ok[i] = canTypeOneLine(words[i].toLowerCase(), a);
            cnt += ok[i] ? 1 : 0;
        }
        
        String[] result = new String[cnt];
        for(int i = 0, ridx = 0; i < words.length && ridx < cnt; i++) {
            if(ok[i]) {
                result[ridx++] = words[i];
            }
        }
        
        return result;
    }
    
    private boolean canTypeOneLine(String word, char[][] keyboard) {
        int line = findLine(word.charAt(0), keyboard);
        for(int i = 1; i < word.length(); i++) {
            if(line != findLine(word.charAt(i), keyboard)) {
                return false;
            }
        }
        
        return true;
    }
    
    private int findLine(char a, char[][] keyboard) {
        for(int line = 0; line < keyboard.length; line++) {
            for(int i = 0; i < keyboard[line].length; i++) {
                if(keyboard[line][i] == a) {
                    return line;
                }
            }
        }
        throw new IllegalArgumentException("Character not found");
    }
}
```
# Problem 2

## [Friend Circles](https://leetcode.com/problems/friend-circles/description/)
```java
class Solution {
    public int findCircleNum(int[][] M) {
        UnionSet set = new UnionSet(M.length);
        for(int i = 0; i < M.length; i++) {
            for(int j = i+1; j < M.length; j++) {
                if(M[i][j] == 1) {
                    set.union(i,j);
                }
            }
        }
        int count = 0;
        Set<Integer> circle = new HashSet<>();
        for(int i = 0; i < M.length; i++) {
            circle.add(set.find(i));
        }
        
        return circle.size();
    }
}

class UnionSet {
    private int[] p;
    
    public UnionSet(int n) {
        p = new int[n];
        for(int i = 0; i < n; i++) {
            p[i] = i;
        }
    }
    
    public int find(int a) {
        if(p[a] == a) {
            return p[a];
        }
        p[a] = find(p[a]);
        return p[a];
    }
    
    public void union(int a, int b) {
        p[find(a)] = find(p[b]);
    }
}
```
# Problem 4

## [QMAX](http://vn.spoj.com/problems/QMAX/)
```java
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;
 
/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        QMAX solver = new QMAX();
        solver.solve(1, in, out);
        out.close();
    }
}
 
class QMAX {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        SegmentTree st = new SegmentTree(n);
        int u,v,k;
        for (int i = 0; i < m; i++) {
            u = in.nextInt()-1;
            v = in.nextInt()-1;
            k = in.nextInt();
            st.update(u,v,k);
        }
        int q = in.nextInt();
        for (int i = 0; i < q; i++) {
            u = in.nextInt() - 1;
            v = in.nextInt() - 1;
            out.println(st.getMax(u,v));
        }
    }
}
 
class SegmentTree{
    private long[] tree;
    private long[] lazy;
    int n;
 
    SegmentTree(int n){
        tree = new long[4*n+5];
        lazy = new long[4*n+5];
        this.n = n;
    }
 
    void update(int l, int r, int value){
        update(0,0,n-1,l,r,value);
    }
 
    private void update(int node, int lo, int hi, int l, int r,int value){
        if(lazy[node] != 0){
            tree[node] += lazy[node];
            if(lo != hi){
                lazy[node*2+1] += lazy[node];
                lazy[node*2+2] += lazy[node];
            }
            lazy[node] = 0;
        }
        if(hi < l || lo > r) return;
        if(l <= lo && hi <= r){
            tree[node] += value;
            if(lo != hi){
                lazy[node*2+1] += value;
                lazy[node*2+2] += value;
            }
            return;
        }
        int mid = (lo + hi) >> 1;
        update(node*2+1,lo,mid,l,r,value);
        update(node*2+2,mid+1,hi,l,r,value);
        tree[node] = Math.max(tree[node*2+1],tree[node*2+2]);
    }
 
    long getMax(int l, int r){
        return internalQuery(0,0,n-1,l,r);
    }
 
    private long internalQuery(int node, int lo, int hi, int l, int r){
        if(hi < l || lo > r) return 0;
        if(lazy[node] != 0){
            tree[node] += lazy[node];
            if(lo != hi){
                lazy[node*2+1] += lazy[node];
                lazy[node*2+2] += lazy[node];
            }
            lazy[node] = 0;
        }
        if(l <= lo && hi <= r){
            return tree[node];
        }
        int mid = (lo + hi) >> 1;
        long leftNode = internalQuery(node*2+1,lo,mid,l,r);
        long rightNode = internalQuery(node*2+2,mid+1,hi,l,r);
        return Math.max(leftNode,rightNode);
    }
}
 
class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;
 
    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream), 32768);
        tokenizer = null;
    }
 
    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }
 
    public int nextInt() {
        return Integer.parseInt(next());
    }
 
}
```
