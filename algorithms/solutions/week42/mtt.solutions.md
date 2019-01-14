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

## Problem 2
```c++
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
private:
  bool overlap(Interval v1, Interval v2) {
    if (v1.end >= v2.start) return true;
    return false;
  }
  Interval merge2(Interval v1, Interval v2) {
    return Interval(v1.start, max(v1.end, v2.end));
  }
public:
  vector<Interval> merge(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), [](const auto& v1, const auto& v2) {
      return v1.start < v2.start;
    });
    vector<Interval> result;
    int index = 0;
    while (index < intervals.size()) {
      Interval cur = intervals[index];
      index++;
      while (index < intervals.size()) {
        if (overlap(cur, intervals[index])) {
          cur = merge2(cur, intervals[index]);
          index++;
        } else
          break;
      }
      result.push_back(cur);
    }
    return result;
  }
};
```

# Problem 3
```c++
class Solution {
private:
  int vtoi(vector<int>& digits) {
    int result = 0;
    for (int i = digits.size() - 1; i >= 0; --i)
      result = result * 10 + digits[i];
    return result;
  }
public:
  int maximumSwap(int num) {
    vector<int> digits;
    while (num > 0) {
      digits.push_back(num % 10);
      num = num / 10;
    }
    for (int i = digits.size() - 1; i >= 0; --i) {
      int lj = -1, mj = digits[i] + 1;
      for (int j = i - 1; j >= 0; --j)
        if (digits[j] >= mj) {
          mj = digits[j];
          lj = j;
        }
      if (lj >= 0) {
        int t = digits[i];
        digits[i] = digits[lj];
        digits[lj] = t;
        return vtoi(digits);
      }
    }
    return vtoi(digits);
  }
};
```
