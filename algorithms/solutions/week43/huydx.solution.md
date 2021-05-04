# Problem 1
```java
class MyStack {
    private Queue<Integer> in;
    private Queue<Integer> out;
    
    /** Initialize your data structure here. */
    public MyStack() {
        in = new LinkedList<>();
        out = new LinkedList<>();
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        out.add(x);
        while (!in.isEmpty()) {
            out.add(in.poll());
        }
        // swap
        Queue tmp = out;
        out = in;
        in = tmp;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        return in.remove();
    }
    
    /** Get the top element. */
    public int top() {
        return in.peek();
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        return in.isEmpty() && out.isEmpty();
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */
 ```
 
# Problem 2
```java
class Solution {
    static class Node {
        String val;
        int depth;
        Node(String val, int depth) {
            this.val = val;
            this.depth = depth;
        }
    }
    
    public int minMutation(String start, String end, String[] bank) {
        
        List<Character> options = Arrays.asList('A', 'C', 'G', 'T');
        Queue<Node> next = new LinkedList<>();
        Map<String, Boolean> visited = new HashMap<>();
        next.offer(new Node(start, 0));
        int step = 0;
        
        //bfs
        while (!next.isEmpty()) {
            Node cur = next.poll();
            visited.put(cur.val, true);
            for (int i = 0; i < cur.val.length(); i++) {
                for (char option : options) {
                    String n = cur.val.substring(0, i) + option + cur.val.substring(i+1); // mutate
                    if (visited.get(n) == null && ) {
                        next.offer(new Node(n, cur.depth+1));
                        System.out.println(n);
                        System.out.println(cur.depth+1);
                        System.out.println("..");
                    }
                    if (n.equals(end)) {
                        return cur.depth+1;
                    }
                }
            }
        }
        return -1;
    }
}
```

# Problem 3
```java
class NumArray {
    private int[] sum;
    
    public NumArray(int[] nums) {
        if (nums.length == 0) {
            return;
        }
        sum = new int[nums.length];
        sum[0] = nums[0];
        for (int i = 1; i < nums.length; i++) {
            sum[i] = sum[i-1] + nums[i];
        }
    }
    
    public int sumRange(int i, int j) {
        if (sum == null) {return -1;}
        if (i == 0) {return sum[j];}
		else {return sum[j] - sum[i - 1];}
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
 ```
