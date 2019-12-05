# Problem 1:
https://leetcode.com/problems/implement-stack-using-queues/submissions/

```java
class MyStack {

    Queue<Integer> queue = new LinkedList<Integer>();
    
    
    public void push(int x) {
        queue.add(x);
    }
    
    public int pop() {
        int top = top();
        for (int i = 0; i < queue.size() - 1; i++)
        {
            queue.add(queue.poll());
        }
        queue.remove();
        
        return top;
    }
    
    public int top() {
        for (int i = 0; i < queue.size() - 1; i++)
        {
            queue.add(queue.poll());
        }
        int ret = queue.remove();
        queue.add(ret);
        return ret;
    }

    public boolean empty() {
        return queue.isEmpty();
    }
}
```

# Problem 3:
https://leetcode.com/problems/range-sum-query-immutable/submissions/
```java
class NumArray {
    
    int[] sums;
    
    public NumArray(int[] nums) {
        if (nums.length == 0) 
            return;
        
        sums = new int[nums.length];
        sums[0] = nums[0];
        for (int i = 1; i < nums.length; i++) {
            sums[i] = sums[i-1] + nums[i];
        }
    }
    
    public int sumRange(int i, int j) {
        if (i == 0)
            return sums[j];
    
        return sums[j] - sums[i - 1];
    }
}
```