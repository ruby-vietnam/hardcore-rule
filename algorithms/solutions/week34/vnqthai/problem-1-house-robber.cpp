class Solution {
  public:
    int rob(vector<int>& nums) {
      int N = nums.size();
      if (N == 0) { return 0; }
      else if (N == 1) { return nums[0]; }
      else if (N == 2) { return max(nums[0], nums[1]); }
      else {
        vector<int> dp(N);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < N; i++) {
          dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        }
        return dp[N-1];
      }
    }
};
