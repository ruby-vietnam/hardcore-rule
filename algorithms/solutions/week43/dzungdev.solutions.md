Problem1: https://leetcode.com/problems/implement-stack-using-queues/

```java
class MyStack {
    
    LinkedList<Integer> q;

    /** Initialize your data structure here. */
    public MyStack() {
        q = new LinkedList<>();
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        q.add(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        int last = q.getLast();
        q.removeLast();
        return last;
    }
    
    /** Get the top element. */
    public int top() {
        return q.getLast();
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        return q.size() == 0;
    }
}
```

Problem2: https://leetcode.com/problems/minimum-genetic-mutation/

Our idea is for String, we change all character of that String with the choice we can change ('A', 'C', 'G', 'T'), if we have one new string which isn't visited and inside the String bank, then we add it to queue. One String can have some new String which is valid, so we group all String which is generated from one String to one level. Once we loop through all String inside one level, we increase level.

Time complexity is O(n^2) if n is length of String and in the worse case, the bank contains the longest path which is n-1 step to end String.

```java
public int minMutation(String start, String end, String[] bank) {
        if (start.equals(end)) return 0;
        Set<String> bankSet = new HashSet<>();
        for (String b: bank) {
            bankSet.add(b);
        }
        
        char[] choices = new char[] {'A', 'C', 'G', 'T'};
        
        Queue<String> q = new LinkedList<>();
        Set<String> visited = new HashSet<>();
        q.offer(start);
        visited.add(start);
        int level = 0;
        
        while (!q.isEmpty()) {
            int queueSize = q.size();
            while (queueSize-- > 0) {
                String cur = q.poll();
                if (cur.equals(end)) return level;
                
                char[] curChars = cur.toCharArray();
                for (int i = 0; i < curChars.length;i++) {
                    char oldChar = curChars[i];

                    for (char choice: choices) {
                        curChars[i] = choice;
                        String newString = String.valueOf(curChars);
                        if (!visited.contains(newString) && bankSet.contains(newString)) {
                            q.offer(newString);
                            visited.add(newString);
                        }
                    }
                    curChars[i] = oldChar;
                }    
            }
            level++;
        }
        return -1;
    }
```
