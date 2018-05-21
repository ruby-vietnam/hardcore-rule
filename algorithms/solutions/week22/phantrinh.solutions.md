### Prolem 1 - [Majority Element](https://leetcode.com/problems/majority-element/description/)

Status:
```
  ✔ Accepted
  ✔ 44/44 test cases passed (21 ms)
```

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> cnt;
        for (int num : nums) {
            if (++cnt[num] > nums.size() / 2)
                return num;
        }
    }
};
```

### Prolem 2 - [Bulb Switcher](https://leetcode.com/problems/bulb-switcher/description/)

Status:
```
  ✔ Accepted
  ✔ 35/35 test cases passed (2 ms)
```

```cpp
class Solution {
public:
    int bulbSwitch(int n) {
        return (int) sqrt(n + 0.5);
    }
};
```

### Problem 3 - [Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/description/)

Status:
```
  ✔ Accepted
  ✔ 2080/2080 test cases passed (89 ms)
```

Code:

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = (nums1.size() + nums2.size());
        if (n == 0) return 0;
        int m = (n + 2) / 2;
        int l = 0, r = min((int)nums1.size(), m);
        
        while (l <= r) {
            int h = (l + r) >> 1;
            int k = m - h;
            if (k > nums2.size()) {
                l = h + 1;
                continue;
            }
            if (k < nums2.size() && h > 0 && nums1[h - 1] > nums2[k]) {
                r = h - 1;
                continue;
            }
            if (h < nums1.size() && k > 0 && nums2[k - 1] > nums1[h])  {
                l = h + 1;
                continue;
            }
            if (n & 1) {
                if (h == 0) return nums2[k - 1];
                if (k == 0) return nums1[h - 1];
                return 1.0 * max(nums1[h - 1], nums2[k - 1]);
            } else {
                if (h == 0) {
                    return 0.5 * (nums2[k - 1] + nums2[k - 2]);
                }
                if (k == 0) {
                    return 0.5 * (nums1[h - 1] + nums1[h - 2]);
                }
                if (k == 1 && h == 1) {
                    return 0.5 * (nums1[0] + nums2[0]);
                }
                if (h == 1) {
                    return 0.5 * (nums2[k - 1] + max(nums1[0], nums2[k - 2]));
                }
                if (k == 1) {
                    return 0.5 * (nums1[h - 1] + max(nums2[0], nums1[h - 2]));
                }
                vector<int> v;
                v.push_back(nums1[h - 1]);
                v.push_back(nums1[h - 2]);
                v.push_back(nums2[k - 1]);
                v.push_back(nums2[k - 2]);
                sort(v.begin(), v.end());
                return 0.5 * (v[2] + v[3]);
            }
        }
        return 0;
    }
};
```

### Problem 4 - [Range Sum Query - Mutable](https://leetcode.com/problems/range-sum-query-mutable/description/)

Status:
```
  ✔ Accepted
  ✔ 10/10 test cases passed (468 ms)
```

Code:
```cpp
class NumArray {
private:
    int n;
    map<int, long long> bit;
    map<int, int> a;
    void up(int i, int val) {
        for (; i <= n; i += i & -i) {
            bit[i] += val; 
        }
    }
    long long get(int i) {
        if (!i) return 0;
        long long ret = 0;
        for (; i; i -= i & -i) {
            ret += bit[i];
        }
        return ret;
    }
    void build() {
        for (int i = 1; i <= n; ++i) {
            up(i, a[i]);
        }
    }
    
public:    
    NumArray(vector<int> nums) {
        n = nums.size();
        for (int i = 0; i < nums.size(); ++i) a[i + 1] = nums[i];
        if (n) {
            build();
        }
    }
    
    void update(int i, int val) {
        n = max(n, i + 1);
        ++i;
        int s = val - a[i];
        a[i] = val;
        up(i, s);
    }
    
    int sumRange(int i, int j) {
        return get(j + 1) - get(i);
    }
};
```
