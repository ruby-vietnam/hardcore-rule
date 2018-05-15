/*
 *
 * Link: https://leetcode.com/problems/majority-element
 *
 * 44 / 44 test cases passed.
 * Status: Accepted
 * Runtime: 22 ms
 * Your runtime beats 71.03 % of cpp submissions.
 *
 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int score, index;
        score = index = 0;
        for(int i = 0; i < nums.size(); i++) {
            if (score == 0) {
                index = i;
            }
            if (nums[index] == nums[i]) {
                score++;
            } else {
                score--;
            }
        }

        return nums[index];

        /*
         *
         * should have the following check if the majority outcome is not guaranteed
         *
         * if (checkCandidate(nums, nums[index])) {
         *     return nums[index];
         * }
         * return -1;
         *
         */
    }

private:
    bool checkCandidate(vector<int>& nums, int candidate) {
        int count = 0;

        int n = nums.size();
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == candidate) {
                count++;
            }
        }

        if (count > n / 2) {
            return true;
        }   return false;
    }
};