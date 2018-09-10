## Problem 1
```c++
class Solution {
public:
  bool isPowerOfThree(int n) {
    long int t = 3486784401;
    if (n <= 0) return false;
    return (t % n == 0);
  }
};
```

## Problem 2
```c++
class Solution {
public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    deque<int> dq;
    for (auto it : arr)
      if (dq.size() < k)
        dq.push_back(it);
      else {
        if (abs(x - dq.front()) > abs(x - it)) {
          dq.pop_front();
          dq.push_back(it);
        }
      }
    vector<int> result(dq.begin(), dq.end());
    return result;
  }
};
```

## Problem 3
```c++
class Solution {
private:
  void getMinCloset(int& closet, int target, vector<int>& nums, int i, int j, int k) {
    int sum = nums[i] + nums[j] + nums[k];
    if (abs(closet - target) > abs(sum - target))
      closet = sum;
  }
public:
  int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int closet = nums[0] + nums[1] + nums[2];
    
    for (int i = 0; i < nums.size() - 2; ++i) {
      int j = i + 1, k = nums.size() - 1;
      while (j < k) {
        getMinCloset(closet, target, nums, i, j, k);
        if (j == k - 1) break;
        if (nums[i] + nums[j] + nums[k] > target) {
          int mid = (j + k)/2;
          while (mid < k - 1)
            if (nums[i] + nums[j] + nums[mid] > target)
              break;
            else
              mid = (mid + k)/2;
          k = mid;
        }
        else {
          int mid = (j + k)/2;
          while (mid > j)
            if (nums[i] + nums[mid] + nums[k] <= target)
              break;
            else
              mid = (j + mid)/2;
          j = (j == mid) ? j + 1 : mid;
        }
      }
    }
    return closet;
  }
};
```

## Problem 4
```c++
```
