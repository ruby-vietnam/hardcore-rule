#Bai 1:

```
class Solution {
public:
    int rob(vector<int> &num) {

			if (num.size() == 0)
				return 0;
			else if (num.size() == 1)
				return num[0];
        
			vector<int> cash(num.size(), 0);			    			
			for (int i = 0; i < num.size(); i++) {

				int prev1 = 0;
				if (i >= 3)
					prev1 = cash[i - 3];

				int prev2 = 0;
				if (i >= 2)
					prev2 = cash[i - 2];

				cash[i] = max(prev1, prev2) + num[i];
			}
			
			return max(cash[num.size() - 1], cash[num.size() - 2]);
    }
};
```

#Bai 2:
```
class Solution {
    public:
    unordered_map<string, bool> m;

    bool wordBreak(string s, vector<string>& wordDict) {
        for (auto word : wordDict) m.emplace(word, true);
        return wBreak(s, wordDict);
    }

    bool wBreak(string &s, vector<string>& wordDict) {
        if (m.count(s)) return m[s]; 

        for (auto word : wordDict) {
            string left = s.substr(0, word.size());
            if (!m.count(left) || m[left] == false) continue; 

            string right = s.substr(word.size());
            if (wBreak(right, wordDict)) return m[s]=true;
        }
        return m[s]=false;
    }
};
```
