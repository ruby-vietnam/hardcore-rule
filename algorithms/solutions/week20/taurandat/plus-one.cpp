/*
 *
 * Link: https://leetcode.com/problems/plus-one/
 *
 * 109 / 109 test cases passed.
 * Status: Accepted
 * Runtime: 4 ms
 * Your runtime beats 99.68 % of cpp submissions.
 *
 */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> answer;
        bool carry = true;
        for(int i = digits.size() - 1; i >= 0; i--) {
            if(carry) {
                digits[i]++;
                carry = false;
            }
            if(digits[i] > 9) {
                carry = true;
            }
            answer.push_back(digits[i] % 10);
        }
        if (carry) {
            answer.push_back(1);
        }

        reverse(answer.begin(), answer.end());

        return answer;
    }
};
