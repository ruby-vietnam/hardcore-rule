## Problem 1
```c++
class Solution {
private:
  int find(vector<int>& numbers, int i, int l, int r, int target) {
    if (numbers[i] + numbers[l] == target) return l;
    if (numbers[i] + numbers[r] == target) return r;
    if (l + 1 >= r) return 0;
    int m = (l + r)/2;
    if (numbers[i] + numbers[m] < target)
      return find(numbers, i, m, r, target);
    else
      return find(numbers, i, l, m, target);
  }
public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    for (int i = 0; i < numbers.size() - 1; ++i)
      if (int j = find(numbers, i, i + 1, numbers.size() - 1, target)) {
        return vector<int>{i + 1, j + 1};
      }
    return vector<int>{};
  }
};
```
