class Solution {
  public:
    int climbStairs(int n) {
      vector<int> a(n+1);
      a[1] = 1;
      a[2] = 2;
      for (int i = 3; i <= n; i++) {
        a[i] = a[i-1] + a[i-2];
      }
      return a[n];
    }
};
