#Problem 1
``` Java 
class MyStack {

    Queue<Integer> q;
    /** Initialize your data structure here. */
    public MyStack() {
        q = new LinkedList<>();
    }

    /** Push element x onto stack. */
    public void push(int x) {
        q.add(x);
        int n = q.size();
        while (n-- > 1){
            q.add(q.poll());
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        return q.poll();
    }

    /** Get the top element. */
    public int top() {
        return q.peek();
    }

    /** Returns whether the stack is empty. */
    public boolean empty() {
        return q.isEmpty();
    }
}
```

#Problem 3
```Java
class NumArray {

    int[] nums;
    public NumArray(int[] nums) {
        this.nums = nums;
    }
    
    public int sumRange(int i, int j) {
        int sum = 0;
        for(int idx = i ; idx <= j; idx++){
                sum+=nums[idx];
        }
        return sum;
    }
}
```
