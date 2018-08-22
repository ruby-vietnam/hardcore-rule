class Solution {
public:
  int longestValidParentheses(string s) {
    int n = s.length();

    stack<int> indices;
    indices.push(-1);

    int longest = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '(') {
        indices.push(i);
      } else {
        indices.pop();
        if (indices.empty()) {
          indices.push(i);
        } else {
          longest = max(longest, i - indices.top());
        }
      }
    }

    return longest;
  }
};
