/*
 *
 * Link: https://leetcode.com/problems/friend-circles
 *
 * 113 / 113 test cases passed.
 * Status: Accepted
 * Runtime: 25 ms
 * Your runtime beats 37.31 % of cpp submissions.
 *
 */

class Solution {
public:
  int findCircleNum(vector<vector<int>>& M) {
    if (M.empty()) return 0;

    int n = M.size();

    vector<int> leads(n, 0);
    for (int i = 0; i < n; i++) {
      leads[i] = i;
    }

    int groups = n;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (M[i][j]) {
          int lead1 = find(i, leads);
          int lead2 = find(j, leads);
          if (lead1 != lead2) {
            leads[lead1] = lead2;
            groups--;
          }
        }
      }
    }

    return groups;
  }

private:
  int find(int x, vector<int>& parents) {
    return parents[x] == x ? x : find(parents[x], parents);
  }
};
