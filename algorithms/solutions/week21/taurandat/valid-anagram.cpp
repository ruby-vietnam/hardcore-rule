/*
 *
 * Link: https://leetcode.com/problems/valid-anagram/
 *
 * 34 / 34 test cases passed.
 * Status: Accepted
 * Runtime: 10 ms
 * Your runtime beats 99.39 % of cpp submissions.
 *
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        int countS[26]; fill(begin(countS), begin(countS) + 26, 0);
        int countT[26]; fill(begin(countT), begin(countT) + 26, 0);

        if (s.size() != t.size()) {
            return false;
        }

        int n = s.size();
        for(int i = 0; i < n; i++) {
            countS[s[i] - 'a']++;
            countT[t[i] - 'a']++;
        }

        for(int i = 0; i < 26; i++) {
            if(countS[i] != countT[i]) {
                return false;
            }
        }

        return true;
    }
};