## Problem 1
```cpp
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
      vector<string> v;
      map<string, int> m;
      for(string s : cpdomains){
        int i = s.find_first_of(' ');
        int c = stoi(s.substr(0, i));
        auto w = s.substr(i+1);
        counter(m, w, c);
      }

      for(auto p : m){
        v.push_back(to_string(p.second) + " " + p.first);
      }
      return v;


    }

    void counter(map<string, int>& m, string s, int c){
      auto i = s.find_first_of('.');
      m[s] += c;
      if (i != string::npos){
        counter(m, s.substr(i+1), c);
      }
    }

};
```


