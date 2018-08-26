class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    int len_s = s.size();
    unordered_set<string> dict;

    int len_d = wordDict.size();
    for(int i = 0; i < len_d; i++) {
      dict.insert(wordDict[i]);
    }

    vector<bool> f(len_s+1, false);
    f[0] = true;
    for(int i = 1; i <= len_s; i++) {
      for(int j = i - 1; j >= 0; j--) {
        if(f[j] && dict.find(s.substr(j, i-j)) != dict.end()) {
          f[i] = true;
          break;
        }
      }
    }

    return f[len_s];
  }
};
