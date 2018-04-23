# Problem 1 

```
class segmentTree{
private:
    int st[400005];

    void update(int k, int l, int r, int& i, int& x){
        if (i < l || r < i) return;
        if (l == r){
            st[k] = x;
            return;
        }
        int mid = (l+r)/2;
        update(2*k, l, mid, i, x);
        update(2*k+1, mid+1, r, i, x);
        st[k] = min(st[2*k], st[2*k+1]);
    }
    
    int get(int k, int l, int r, int u, int& v){
        if (r < u || v < l) return INT_MAX;
        if (u <= l && r <= v) return st[k];
        int mid = (l+r)/2;
        return min(get(2*k, l, mid, u, v), get(2*k+1, mid+1, r, u, v));
    }
    
public:
    void update(int i, int& x){ update(1, 1, 100000, i, x); }   //update gia tri o vi tri i thanh x
    int get(int i){ return get(1, 1, 100000, 1, i); }           //lay min doan 1..i
};


class MinStack {
public:
    /** initialize your data structure here. */
    
    segmentTree st;
    vector<int> Stack;
    
    MinStack() {
        Stack.clear();
    }
    
    void push(int x) {
        Stack.push_back(x);
        st.update(Stack.size(), x);    
    }
    
    void pop() {
        Stack.pop_back(); 
    }
    
    int top() {
        return Stack.back();
    }
    
    int getMin() {
        return st.get(Stack.size());
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
```
