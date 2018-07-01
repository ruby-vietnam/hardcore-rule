#bai1 :
```
class Solution {
public:
 vector<string> subdomainVisits(vector<string>& cpdomains) 
    {
        unordered_map<string, int> visits;
        for(const auto& cur : cpdomains)
        {
            int num = 0;
            int i = 0;
            for(; cur[i] != ' '; ++i)
            {
                num = num * 10 + cur[i] - '0';
            }
            
            for(; i < cur.size(); ++i )
            {
                if(cur[i - 1] == '.' || cur[i - 1] == ' ')
                {
                    visits[cur.substr(i, cur.size() - i)] += num;
                }
            }            
        }
        vector<string> result;
        for(const auto& pair : visits)
        {
            result.push_back(to_string(pair.second) + " " + pair.first);
        }
        return result;
    }
};

```
