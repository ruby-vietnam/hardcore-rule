## Problem 1
```C++
#define vi vector<int>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
  void countEqualSum(int& count, TreeNode* node, vi& sums, int sum) {
    if (node == NULL) return;
    sums.push_back(sums.back() + node->val);
    for (int i = 0; i < sums.size() - 1; ++i)
      if (sums.back() - sums[i] == sum)
        count++;
    countEqualSum(count, node->left, sums, sum);
    countEqualSum(count, node->right, sums, sum);
    sums.pop_back();
  }
public:
  int pathSum(TreeNode* root, int sum) {
    vi sums = {0};
    int count = 0;
    countEqualSum(count, root, sums, sum);
    return count;
  }
};
```

## Problem 2
```C++
class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int i = 0;
    while (i < matrix.size() && matrix[i].size() > 0 && matrix[i][0] <= target) {
      int l = 0, r = matrix[i].size() - 1;
      while (l <= r) {
        if (matrix[i][l] == target || matrix[i][r] == target) return true;
        if (l >= r - 1) break;
        int mid = (l + r)/2;
        if (matrix[i][mid] <= target)
          l = mid;
        else
          r = mid;
      }
      ++i;
    }
    return false;
  }
};
```

## Problem 3
```C++
#define vi vector<int>
#define MAX_TEMPERATURE 101
#define MAX_INDEX 30001

struct Node {
  int val;
  int index;
  Node(int v, int i) : val(v), index(i) {}
};

class Solution {
private:
  void addToStack(vi& result, stack<Node>& nodes, Node& node) {
    while (!nodes.empty() && nodes.top().val < node.val) {
      Node n = nodes.top();
      nodes.pop();
      int delta = (node.index == MAX_INDEX ? 0 : (node.index - n.index)); 
      result[n.index] = delta;
    }
    nodes.push(node);
  }
public:
  vi dailyTemperatures(vi& temperatures) {
    vi result(temperatures.size());
    stack<Node> nodes;
    for (int i = 0; i < temperatures.size(); ++i) {
      Node node = Node(temperatures[i], i);
      addToStack(result, nodes, node);
    }
    Node node = Node(MAX_TEMPERATURE, MAX_INDEX);
    addToStack(result, nodes, node);
    return result;
  }
};
```

## Problem 4
```C++
struct MathNode {
  int val;
  bool number;
  bool opening;
  bool closed;
  char sign;
  MathNode(int x, bool n, bool o, bool c, char s) : val(x), number(n), opening(o), closed(c), sign(s) {}
};

class Solution {
private:
  int getNumber(char c) {
    return (int)c - (int)'0';
  }
  
  bool isNumber(char c) {
    int r = getNumber(c);
    return (0 <= r && r <= 9);
  }
  
  void calculate(vector<MathNode>& nodes) {
    long int sum = 0;
    stack<MathNode> st;
    while (!nodes.empty()) {
      MathNode node = nodes.back();
      nodes.pop_back();
      if (node.number)
        st.push(node);
      if (node.opening) break;
      if (node.sign == '-') {
        sum = sum - st.top().val;
        st.pop();
      }
      if (node.sign == '+') {
        sum = sum + st.top().val;
        st.pop();
      }
    }
    while (!st.empty()) {
      sum = sum + st.top().val;
      st.pop();
    }
    nodes.push_back(MathNode(sum, true, false, false, ' '));
  }
  
  MathNode getMathNode(string& s, int& si) {
    while (si < s.size() && s[si] == ' ') ++si;
    if (s[si] == '(') {
      ++si;
      return MathNode(0, false, true, false, ' ');
    }
    if (s[si] == ')') {
      ++si;
      return MathNode(0, false, false, true, ' ');
    }
    if (s[si] == '-' || s[si] == '+') {
      return MathNode(0, false, false, false, s[si++]);
    }
    if (si == s.size()) return MathNode(0, false, false, false, ' ');
    int r = 0;
    while (si < s.size() && isNumber(s[si]))
      r = r*10 + getNumber(s[si++]);
    return MathNode(r, true, false, false, ' ');
  }
  
public:
  int calculate(string s) {
    long int sum = 0;
    vector<MathNode> nodes;
    
    int si = 0;
    while (si < s.size()) {
      MathNode node = getMathNode(s, si);
      if (node.closed)
        calculate(nodes);
      else
        nodes.push_back(node);
    }
    calculate(nodes);
    return nodes[0].val;
  }
};
```
