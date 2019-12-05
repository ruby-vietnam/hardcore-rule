## Problem 1
```c++
class MyStack {
private:
  queue<int> store;
public:
  /** Initialize your data structure here. */
  MyStack() {
  }
    
  /** Push element x onto stack. */
  void push(int x) {
    queue<int> t;
    t.push(x);
    while (!store.empty()) {
      int e = store.front();
      t.push(e);
      store.pop();
    }
    store = t;
  }
    
  /** Removes the element on top of the stack and returns that element. */
  int pop() {
    int t = store.front();
    store.pop();
    return t;
  }
    
  /** Get the top element. */
  int top() {
    return store.front();
  }
    
  /** Returns whether the stack is empty. */
  bool empty() {
    return store.empty();
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

## Problem 2
```c++
class Solution {
private:
  bool mutate(string s1, string s2) {
    int diffs = 0;
    for (int i = 0; i < 8; ++i)
      if (s1[i] != s2[i])
        diffs++;
    return diffs == 1;
  }
public:
  int minMutation(string start, string end, vector<string>& bank) {
    queue<int> store;
    vector<int> fx(bank.size(), 0);
    
    for (int i = 0; i < bank.size(); ++i)
      if (mutate(start, bank[i])) {
        store.push(i);
        fx[i] = 1;
      }
    
    while (!store.empty()) {
      int i = store.front();
      if (bank[i] == end) return fx[i];
      store.pop();
      for (int j = 0; j < bank.size(); ++j)
        if (!fx[j])
          if (mutate(bank[i], bank[j])) {
            fx[j] = fx[i] + 1;
            store.push(j);
          }
    }
    return -1;
  }
};
```

# Problem 3
```c++
class NumArray {
private:
  vector<int> s;
public:
  NumArray(vector<int> nums) {
    if (nums.empty()) return;
    s.push_back(nums[0]);
    for (int i = 1; i < nums.size(); ++i)
      s.push_back(s.back() + nums[i]);
  }
    
  int sumRange(int i, int j) {
    if (i)
      return s[j] - s[i-1];
    else
      return s[j];
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
```
