# Problem 1
Idea: dp with formula: state == the ability of the robber to rob current room.
If it's able to rob from current room --> it could rob from 2 prev room + this room.
If it's not able to rob from current room --> it could rob from prev room + 0.
Therefore, what the robber could rob == max(it could rob from 2 prev room + this room, it could rob from prev room + 0)
The array start with index 1 because we need initial state.

```java
class Solution {
    public int rob(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        int[] dp = new int[nums.length + 1];
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 2; i <= nums.length; i++) {
            dp[i] = Math.max(dp[i-1], dp[i-2] + nums[i-1]);
        }
        return dp[nums.length];
    }
}
```

# Problem 2
Idea: dp with formula: state[i] == the ability to break input string from 0~i-1.
So we just need to confirm from i~end to match any word from dict.

```java
class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        boolean[] state = new boolean[s.length()+1];
        state[0] = true;
        
        for (int i = 0; i < s.length(); i++) {
            if (!state[i]) continue;
            for (String word : wordDict) {
                int l = word.length();
                int end = i + l;
                if (end > s.length()) {
                    continue;
                }
                if (state[end]) {
                    continue;
                }
                if (s.substring(i, end).equals(word)) {
                    state[end] = true;
                }
            }
        }
        
        return state[s.length()];
    }
}
```
