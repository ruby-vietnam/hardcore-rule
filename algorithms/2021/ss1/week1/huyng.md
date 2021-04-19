## 1. Palindrome Linked List
### 1.1. Summary
Split the linked list into two half then reverse the second half.
The given linked list is palindrome when each node in two half
completely identity.

### 1.2. Solution summary
| Runtime  | Faster than | Memory   | Less than |
| :----:   | :----:      | :----:   | :----:    |
| 180ms    | 71.72%      | 114.1 MB | 64.86%    |

### 1.3. Source code
```cpp
class Solution {
public:
  bool isPalindrome(ListNode* head) {
    int nElement = 0;
    for (ListNode* cur = head; cur != NULL; cur = cur->next, nElement++) {}

    if (nElement <= 1) {
      return true;
    }

    ListNode* secondHead = head;
    for (int i = nElement / 2 + (nElement&1); i >= 1; i--) {
      secondHead = secondHead->next;
    }

    // Reverse the second chain
    {
      ListNode* prevNode = NULL;
      ListNode* nextNode = NULL;
      while (secondHead != NULL) {
        nextNode = secondHead->next;
        secondHead->next = prevNode;
        prevNode = secondHead;
        secondHead = nextNode;
      }
      secondHead = prevNode;
    }

    for (int i = 1; i <= nElement / 2; i++) {
      if (head->val != secondHead->val) {
        return false;
      }
      head = head->next;
      secondHead = secondHead->next;
    }

    return true;
  }
};
```

## 2. Palindrome Pairs
### 2.1. Summary
| Runtime  | Faster than | Memory   | Less than |
| :----:   | :----:      | :----:   | :----:    |
| 484ms    | 11.25%      | 53.7 MB  | 66.49%    |

### 2.2. Solution summary
There are three cases:

1. If the list contains an empty string, that empty string matches
   all palindrome strings.
2. Pair of a string with its reversed in the list.
3. Pair of strings that the combination is a palindrome.
    1. Imagine you have a string `abaxyz`, you can split it into
       `aba` and `xyz` then you can see `aba` is already a palindrome.
       If the list contains reversed of `xyz`, you can make a
       palindrome string by adding it at the prefix, like
       `zyx` + `abaxyz` = `zyxabaxyz`.
    2. Like an above, but a little different, imagine your
       string now is `xyzaba`. Very easy to see that it can be
       split into two string `xyz` and `aba`. Now `aba` is already
       a palindrome string. If the list contains `zyx`, it can be
       added at the end of the string like
       `xyzaba` + `zyx` = `xyzabazyx` then you have a palindrome string.

I used Rolling Hash for checking palindrome in *O(1)* and easy
to check whether the string is existing in the list or not.

If you guys are not familiar with Rolling Hash, just read it here:
[Hash: A String Matching Algorithm](https://vnoi.info/wiki/algo/string/hash.md).

### 2.3. Source code
```cpp
const int64_t MOD = 1000000003;

class Solution {
public:
  vector<int64_t> pow31;
  vector< vector<int64_t> > hash, revHash;

  bool isPalindrome(const int& hashIdx, const int& i, const int& j, const int& n) {
    int med = (j - i + 1) >> 1;
    return getHash(hashIdx, 0, i, i + med - 1) == getHash(hashIdx, 1, n - j + 1, n - (j - med + 1) + 1);
  }

  int64_t getHash(const int& hashIdx, const bool& isRev, const int& i, const int& j) {
    return isRev
      ? (revHash[hashIdx][j] - revHash[hashIdx][i - 1] * pow31[j - i + 1] + MOD * MOD) % MOD
      : (hash[hashIdx][j] - hash[hashIdx][i - 1] * pow31[j - i + 1] + MOD * MOD) % MOD;
  }

  vector<vector<int>> palindromePairs(vector<string>& words) {
    int nWords = words.size();

    int maxLength = 0;
    for (string word : words) {
      maxLength = max(maxLength, (int)word.size());
    }

    pow31.resize(maxLength + 1);
    pow31[0] = 1;
    for (int i = 1; i <= maxLength; i++) {
      pow31[i] = (pow31[i - 1] * 31) % MOD;
    }

    // Build hash arrays
    hash.resize(nWords + 1);
    revHash.resize(nWords + 1);

    for (int i = 0; i < nWords; i++) {
      int n = words[i].size();

      hash[i].resize(n + 1);
      for (int j = 1; j <= n; j++) {
        hash[i][j] = (hash[i][j - 1] * 31 + words[i][j - 1] - 'a' + 1) % MOD;
      }

      // Build hash array for reversed string
      revHash[i].resize(n + 1);
      for (int j = 1; j <= n; j++) {
        revHash[i][j] = (revHash[i][j - 1] * 31 + words[i][n - j] - 'a' + 1) % MOD;
      }
    }

    // Memoize reversed hashes
    unordered_map<int64_t, int> m;
    for (int i = 0; i < nWords; i++) {
      int n = words[i].size();
      m[revHash[i][n]] = i;
    }

    vector< vector<int> > palinPairs;

    for (int i = 0; i < nWords; i++) {
      int n = words[i].size();

      if (n == 0) {
        for (int j = 0; j < nWords; j++) {
          int len = words[j].size();
          if (i != j && isPalindrome(j, 1, len, len)) {
            palinPairs.push_back({ i, j });
            palinPairs.push_back({ j, i });
          }
        }
      }

      if (i < nWords - 1) {
        for (int j = i + 1; j < nWords; j++) {
          if ((int)words[j].size() != n) continue;
          if (getHash(i, 0, 1, n) == getHash(j, 1, 1, n)) {
            palinPairs.push_back({ i, j });
            palinPairs.push_back({ j, i });
          }
        }
      }

      for (int j = 1; j <= n - 1; j++) {
        if (isPalindrome(i, 1, j, n) && m.find(getHash(i, 0, j + 1, n)) != m.end()) {
          palinPairs.push_back({ m[getHash(i, 0, j + 1, n)], i });
        }
      }

      for (int j = 2; j <= n; j++) {
        if (isPalindrome(i, j, n, n) && m.find(getHash(i, 0, 1, j - 1)) != m.end()) {
          palinPairs.push_back({ i, m[getHash(i, 0, 1, j - 1)] });
        }
      }
    }

    return palinPairs;
  }
};
```
