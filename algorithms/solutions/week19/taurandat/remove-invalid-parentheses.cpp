/*
 * Link: https://leetcode.com/problems/remove-invalid-parentheses/
 *
 * 125 / 125 test cases passed.
 * Status: Accepted
 * Runtime: 111 ms
 * Your runtime beats 12.73 % of cpp submissions.
 *
 */

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> answers;

        set<string> visited;
        visited.insert(s);

        bool stopAcceptingMore = false;
        queue<string> q;
        q.push(s);
        while(!q.empty()) {
            s = q.front(); q.pop();
            if(isValid(s)) {
                answers.push_back(s);
                stopAcceptingMore = true;
            }

            if(stopAcceptingMore) {
                continue;
            }

            for(int i = 0; i < s.size(); i++) {
                if(s[i] == '(' || s[i] == ')') {
                    string temp = s.substr(0, i) + s.substr(i + 1);

                    if (visited.find(temp) == visited.end()) {
                        visited.insert(temp);
                        q.push(temp);
                    }
                }
            }
        }

        if (answers.size() == 0) {
            answers.push_back("");
        }

        return answers;
    }

private:
    bool isValid(string s) {
        int count = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') count++;
            if(s[i] == ')') count--;
            if(count < 0) return false;
        }
        return (count == 0);
    }
};
