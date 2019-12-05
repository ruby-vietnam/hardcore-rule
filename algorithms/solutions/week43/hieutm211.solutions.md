##Problem 1

```cpp
class MyStack {
public:
    /** Initialize your data structure here. */
    vector<int> st;
    MyStack() {
        st.clear();
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        st.push_back(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ans = st.back();
        st.pop_back();
        return ans;
    }
    
    /** Get the top element. */
    int top() {
        return st.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return st.size() == 0;
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
```
