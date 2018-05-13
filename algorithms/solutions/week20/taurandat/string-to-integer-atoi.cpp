/*
 *
 * Link: https://leetcode.com/problems/string-to-integer-atoi/
 *
 * 1079 / 1079 test cases passed.
 * Status: Accepted
 * Runtime: 29 ms
 * Your runtime beats 57.57 % of cpp submissions.
 *
 */

class Solution {
public:
    int myAtoi(string str) {
        int answer = 0;

        int index = 0;
        while(str[index] == ' ') index++;

        bool isPositive = true;
        if(str[index] == '-') {
            isPositive = false;
            index++;
        } else if (str[index] == '+') {
            index++;
        }

        for(index; index < str.size(); index++) {
            if(!isNumber(str[index])) {
                break;
            }

            int current = answer;
            for(int i = 0; i < 9; i++) {
                if (isOverflow(isPositive, current, answer)) {
                    return isPositive ? INT_MAX : INT_MIN;
                }
                current += answer;
            }

            int next = int(str[index] - '0');
            if(isOverflow(isPositive, current, next)) {
                return isPositive ? INT_MAX : INT_MIN;
            }
            answer = current + next;
        }

        return isPositive ? answer : -answer;
    }

private:
    bool isNumber(char c) {
        return (c >= '0' && c <= '9');
    }

    bool isOverflow(bool isPositive, int a, int b) {
        if (isPositive && INT_MAX - a < b) {
            return true;
        } else if (!isPositive && INT_MAX - a < b - 1) {
            return true;
        }   return false;
    }
};