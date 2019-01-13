## Problem 1
```c++
class Solution {
public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int i = 0, j = numbers.size() - 1;
    while (true) {
      if (numbers[i] + numbers[j] == target) return vector<int>{i + 1, j + 1};
      if (numbers[i] + numbers[j] < target) i++;
      if (numbers[i] + numbers[j] > target) j--;
    }
  }
};
```
