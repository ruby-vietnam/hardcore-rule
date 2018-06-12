/*
 *
 * Link: https://leetcode.com/problems/keyboard-row
 *
 * 22 / 22 test cases passed.
 * Status: Accepted
 * Runtime: 3 ms
 * Your runtime beats 79.01 % of cpp submissions.
 *
 */

class Solution {
public:
  vector<string> findWords(vector<string>& words) {
    unordered_set<char> top({'q','Q','w','W','e','E','r','R','t','T','y','Y','u','U','i','I','o','O','p','P'});
		unordered_set<char> mid({'a','A','s','S','d','D','f','F','g','G','h','H','j','J','k','K','l','L'});
		unordered_set<char> bot({'z','Z','x','X','c','C','v','V','b','B','n','N','m','M'});

    vector <string> result;
    for(auto& word: words) {
      bool
        top_row = true,
        mid_row = true,
        bot_row = true;

      for(auto& c: word) {
        if(top_row) {
          if (top.find(c) == top.end()) {
            top_row = false;
          }
        }

        if(mid_row) {
          if (mid.find(c) == mid.end()) {
            mid_row = false;
          }
        }

        if(bot_row) {
          if (bot.find(c) == bot.end()) {
            bot_row = false;
          }
        }
      }

      if (top_row || mid_row || bot_row) {
        result.push_back(word);
      }
    }

    return result;
  }
};
