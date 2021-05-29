## 1. Add Binary
### 1.1. Summary
| Runtime  | Faster than | Memory   | Less than |
| :----:   | :----:      | :----:   | :----:    |
| 0ms      | 100%        | 7.1 MB   | ???%      |

### 1.3. Source code
```cpp
class Solution {
public:
  string addBinary(const string &a, string b) {
    if ((int)a.size() < (int)b.size()) {
      return addBinary(b, a);
    }

    while ((int)b.size() < (int)a.size()) b = '0' + b;

    int carry = 0;
    string res = "";
    for (int i = (int)a.size() - 1; i >= 0; i--) {
      int r = (a[i] == '1') + (b[i] == '1') + carry;
      res = ((r % 2 == 0) ? '0' : '1') + res;
      carry = r > 1;
    }

    if (carry) res = '1' + res;

    return res;
  }
};
```

## 2. Multiply Strings
### 2.1. Summary
| Runtime  | Faster than | Memory   | Less than |
| :----:   | :----:      | :----:   | :----:    |
| 224ms    | 5.01%       | 73.4 MB  | 5.01%     |

### 2.3. Source code
```cpp
class Solution {
public:
  string add(const string &num1, string num2) {
    if ((int)num1.size() < (int)num2.size()) {
      return add(num2, num1);
    }

    while ((int)num2.size() < (int)num1.size()) {
      num2 = '0' + num2;
    }

    int len = num1.size();
    int carry = 0;
    string res = "";
    for (int i = len - 1; i >= 0; i--) {
      int x = num1[i] - '0';
      int y = num2[i] - '0';
      int sum = x + y + carry;
      res = to_string(sum % 10) + res;
      carry = sum / 10;
    }

    if (carry > 0) {
      res = to_string(carry) + res;
    }

    return res;
  }

  string multiply(const string &num1, const string &num2) {
    if ((int)num1.size() < (int)num2.size()) {
      return multiply(num2, num1);
    }

    vector<string> nums;

    int lena = num1.size();
    int lenb = num2.size();
    for (int i = lenb - 1, pad = 0; i >= 0; i--, pad++) {
      string r = "";
      for (int j = 0; j < pad; j++) r += '0';

      int carry = 0;
      int x = num2[i] - '0';
      for (int j = lena - 1; j >= 0; j--) {
        int y = num1[j] - '0';
        int mul = x * y + carry;
        r = to_string(mul % 10) + r;
        carry = mul / 10;
      }

      if (carry > 0) {
        r = to_string(carry) + r;
      }

      nums.push_back(r);
    }

    string res = nums[0];
    for (int i = 1; i < (int)nums.size(); i++) {
      res = add(res, nums[i]);
    }

    while (res[0] == '0' && (int)res.size() > 1) {
      res.erase(0, 1);
    }

    return res;
  }
};
```

## 3. Minimum Window Substring
### 3.1. Summary
| Runtime  | Faster than | Memory   | Less than |
| :----:   | :----:      | :----:   | :----:    |
| 112ms    | 12.25%      | 7.6 MB   | 76.79%    |

### 3.2. Solution summary
Use two pointers to manage all sliding windows that sastify the statement.

### 3.3. Source code
```cpp
const int NUM_CHARS = 26;

class Solution {
public:
  inline int toInt(const char &s) {
    assert(('A' <= s && s <= 'Z') || ('a' <= s && s <= 'z'));
    if ('A' <= s && s <= 'Z') {
      return s - 'A';
    }
    return NUM_CHARS + s - 'a';
  }

  string minWindow(const string &s, const string &t) {
    int n = s.size();
    int m = t.size();

    vector<int> need(NUM_CHARS * 2);
    for (int i = 0; i < m; i++) {
      need[toInt(t[i])]++;
    }

    int rr = 0;
    int totalMeet = 0;
    vector<int> cntMeet(NUM_CHARS * 2);

    cntMeet[toInt(s[rr])]++;
    if (need[toInt(s[rr])] > 0) {
      totalMeet++;
    }

    int minLength = n + 1;
    int saveLL = -1, saveRR = -1;
    if (totalMeet == m) {
      saveLL = 0;
      saveRR = rr;
    }

    for (int ll = 0; ll < n; ll++) {
      while (rr + 1 < n && totalMeet < m) {
        int c = toInt(s[rr + 1]);
        cntMeet[c]++;
        if (need[c] > 0 && cntMeet[c] <= need[c]) {
          totalMeet++;
        }
        rr++;
      }

      if (totalMeet >= m && minLength > (rr - ll + 1)) {
        minLength = rr - ll + 1;
        saveLL = ll;
        saveRR = rr;
      }

      int c = toInt(s[ll]);
      assert(cntMeet[c] > 0);
      cntMeet[c]--;
      if (need[c] > 0 && cntMeet[c] < need[c]) {
        totalMeet--;
      }
    }

    if (saveLL == -1) {
      return "";
    }

    string res = "";
    for (int i = saveLL; i <= saveRR; i++) {
      res += s[i];
    }

    return res;
  }
};
```
