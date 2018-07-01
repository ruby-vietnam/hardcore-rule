### Prolem 1 - [Subdomain Visit Count](https://leetcode.com/problems/subdomain-visit-count/description/)
```cpp
class Solution {
public:
  vector<string> subdomainVisits(vector<string>& cpdomains) {
    unordered_map<string, int> f;
    vector<string> ret;
    for (string s : cpdomains) {
      int cnt = stoll(s.substr(0, s.find(' ')));
      string domain = s.substr(s.find(' ') + 1);
      do {
        f[domain] += cnt;
        int pos = domain.find('.') + 1;
        if (!pos) break;
        domain = domain.substr(pos);
      } while (true);
    }
    for (auto it = f.begin(); it != f.end(); ++it) {
      ret.push_back(to_string(it->second) + " " + it->first);
    }
    return ret;
  }
};
```

### Prolem 2 - [Directions Reduction](https://www.codewars.com/kata/directions-reduction)
```cpp
#include <unordered_map>

using namespace std;

class DirReduction {
public:
  static std::vector<std::string> dirReduc(std::vector<std::string> &arr) {
    unordered_map<string, string> rev;
    rev["NORTH"] = "SOUTH";
    rev["SOUTH"] = "NORTH";
    rev["EAST"] = "WEST";
    rev["WEST"] = "EAST";
    vector<string> st;
    for (string dir : arr) {
    if (!st.empty() && st.back() == rev[dir]) {
      st.pop_back();
    } else st.push_back(dir);
    }
    return st;
  }
};
```

### Problem 4 - [Sum by Factors](https://www.codewars.com/kata/sum-by-factors)
```cpp
#include <string>
#include <vector>
#include <map>

using namespace std;

class SumOfDivided {
public:
  static std::string sumOfDivided(std::vector<int> &lst) {
    map<int, int> f;
    for (int m : lst) {
      int n = m;
      if (n < 0) n = -n;
      for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
          f[i] += m;
          do {
            n /= i;
          } while (n % i == 0);
        }
      }
      if (n > 1) f[n] += m;
    }
    string ret = "";
    for (auto it : f)
      ret += "(" + to_string(it.first) + " " + to_string(it.second) + ")";
    return ret;
  }
};
```
