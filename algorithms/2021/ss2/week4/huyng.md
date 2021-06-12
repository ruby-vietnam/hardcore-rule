## 1. Merge Sorted Array
### 1.1. Summary
| Runtime  | Faster than | Memory   | Less than |
| :----:   | :----:      | :----:   | :----:    |
| 0ms      | 100%        | 9.2 MB   | ???%      |

### 1.2. Source code
```cpp
class Solution {
public:
  void merge(vector<int>& a, const int &m, vector<int>& b, const int &n) {
    if ((m > 0 && n > 0 && a[0] > b[0]) || (m == 0)) {
      vector<int> aa(a), bb(b);
      merge(bb, n, aa, m);
      a = bb;
      return ;
    }

    vector<int> sorted;

    int j = 0;
    for (int i = 0; i < m; i++) {
      sorted.push_back(a[i]);
      if (i + 1 < m) {
        while (j < n && b[j] < a[i + 1]) {
          sorted.push_back(b[j]);
          j++;
        }
      } else {
        while (j < n) {
          sorted.push_back(b[j]);
          j++;
        }
      }
    }

    a = sorted;
  }
};
```

## 2. Shuffle an Array
### 2.1. Summary
| Runtime  | Faster than | Memory   | Less than |
| :----:   | :----:      | :----:   | :----:    |
| 416ms    | 5.35%       | 96.1 MB  | 5.15%     |

### 2.2. Source code
```cpp
struct Int {
  int val;
  int id;
  int random;
  Int(const int &val, const int &id) : val(val), id(id), random(0) {}
};

bool resetComparator(const Int &i1, const Int &i2) {
  return i1.id < i2.id;
}

bool randomComparator(const Int &i1, const Int &i2) {
  return i1.random < i2.random;
}

class Solution {
public:
  vector<Int> v;

  Solution(vector<int>& nums) {
    for (int i = 0; i < (int)nums.size(); i++) {
      this->v.push_back(Int(nums[i], i));
    }
  }

  vector<int> toVector() {
    vector<int> v;
    for (const Int &i : this->v) {
      v.push_back(i.val);
    }
    return v;
  }

  vector<int> reset() {
    sort(this->v.begin(), this->v.end(), resetComparator);
    return toVector();
  }

  vector<int> shuffle() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    for (Int &i : this->v) {
      i.random = uniform_int_distribution<int>(0, 10000)(rng);
    }
    sort(this->v.begin(), this->v.end(), randomComparator);
    return toVector();
  }
};
```
