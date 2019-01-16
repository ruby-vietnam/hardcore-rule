class MyStack {
    queue<int> q;
public:
    /** Initialize your data structure here. */
    MyStack() {
        q = queue<int>();
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        queue<int> temp;
        while (q.size() > 1) {
            temp.push(q.front());
            q.pop();
        }
        while (!temp.empty()) {
            q.push(temp.front());
            temp.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
