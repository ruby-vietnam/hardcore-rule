/*
 *
 * Link: https://leetcode.com/problems/string-to-integer-atoi/
 *
 * 39 / 39 test cases passed.
 * Status: Accepted
 * Runtime: 9 ms
 * Your runtime beats 90.33 % of cpp submissions.
 *
 */

class Solution {
public:
    unordered_map<string, vector<string>> memo;
    vector<string> wordBreak(string s, vector<string>& dict) {
        if (memo.count(s)) {
            return memo[s];
        }

        vector<string> result;
        if (find(dict.begin(), dict.end(), s) != dict.end()) {
            result.push_back(s);
        }

        for(int i = 1; i < s.size(); i++){
            string word = s.substr(i);

            if(find(dict.begin(), dict.end(), word) != dict.end()) {
                string prefix = s.substr(0, i);
                vector<string> prev = combine(word, wordBreak(prefix, dict));
                result.insert(result.end(), prev.begin(), prev.end());
            }
        }

        memo[s] = result;
        return result;
    }

private:
    vector<string> combine(string word, vector<string> prev){
        for(int i = 0; i < prev.size(); i++) {
            prev[i] += " " + word;
        }
        return prev;
    }
};
