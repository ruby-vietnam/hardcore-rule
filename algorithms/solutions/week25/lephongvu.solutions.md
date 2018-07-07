#Bai 1:

```
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> result ;
        std::unordered_map<char, int> a;
        string l1 = "QWERTYUIOPqwertyuiop";
        string l2 = "ASDFGHJKLasdfghjkl";
        string l3 = "ZXCVBNMzxcvbnm";
        for(auto c: l1)
        {
            a[c]= 1;
        }
        for(auto c: l2)
        {
            a[c]= 2;
        }
        for(auto c: l3)
        {
            a[c]= 3;
        }
        
        
        for(int i = 0; i < words.size(); i++)
        {
            bool flag = false;
            int x = a[words[i][0]];
            for(int j = 1; j < words[i].length(); j++)
            {
                if (x != a[words[i][j]])
                {
                    break;
                }
                if(j == words[i].length()-1) flag = true;        
            }
            if(flag || words[i].length() == 1)
            result.push_back(words[i]);
        }
        return result;
    }
};
```
