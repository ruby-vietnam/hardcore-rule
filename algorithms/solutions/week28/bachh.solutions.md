# Problem 1
``` cpp
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
      int c = 0;
      stack<int> st;
      for(int i = 0; i < (int) nums.size(); i++){
        if(!st.empty()){
          if(nums[i] < st.top()){
            c++;
            auto temp = st.top(); st.pop();
            std::cout << nums[i] << std::endl;
            if(!st.empty() && nums[i] < st.top()){
              st.push(temp);
            }
            else {
              st.push(nums[i]);
            }
          }
          else{
            st.push(nums[i]);
          }
        }
        else{
          st.push(nums[i]);
        }
      }
      return c < 2;
    }
};
```
