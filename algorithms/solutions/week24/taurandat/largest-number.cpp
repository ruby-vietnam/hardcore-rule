/*
 *
 * Link: https://leetcode.com/problems/sum-of-square-numbers
 *
 * 222 / 222 test cases passed.
 * Status: Accepted
 * Runtime: 10 ms
 * Your runtime beats 34.71 % of cpp submissions.
 *
 */

class Solution {
public:
    static bool compare(const string s1, const string s2){
        return s1 + s2 > s2 + s1;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for(int i = 0; i < nums.size(); i++) {
            strs.push_back(to_string(nums[i]));
        }
        sort(strs.begin(), strs.end(), compare);

        string result;
        for (int i = 0; i < strs.size(); i++) {
            result += strs[i];
        }

        while(result[0] == '0' && result.length() > 1) {
            result.erase(result.begin());
        }

        return result;
    }
};
