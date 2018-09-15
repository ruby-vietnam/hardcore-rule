## Problem 1
```c++
class Solution {
public:
  int reverse(int x) {
    long int result = 0;
    while (x) {
      result = result * 10 + (x % 10);
      if (result < INT_MIN || result > INT_MAX) return 0;
      x = x / 10;
    }
    return result;
  }
};
```

## Problem 2
```c++
class Solution {
private:
  bool find(vector<vector<char>>& board, string& word, int l, int i, int j, vector<vector<bool>>& check) {
    vector<int> di = {-1, 0, 0, 1};
    vector<int> dj = {0, -1, 1, 0};
    
    check[i][j] = true;
    if (l == word.length() - 1) return true;
    for (int k = 0; k < 4; ++k) {
      int ni = i + di[k], nj = j + dj[k];
      if (ni >= 0 && ni < board.size())
        if (nj >= 0 && nj < board[0].size())
          if (!check[ni][nj] && board[ni][nj] == word[l + 1])
            if (find(board, word, l + 1, ni, nj, check))
              return true;
    }
    check[i][j] = false;
    return false;
  }
public:
  bool exist(vector<vector<char>>& board, string word) {
    if (board.size() == 0) return false;
    vector<vector<bool>> check(board.size(), vector<bool>(board[0].size(), false));
    
    for (int i = 0; i < board.size(); ++i)
      for (int j = 0; j < board[0].size(); ++j)
        if (board[i][j] == word[0])
          if (find(board, word, 0, i, j, check))
            return true;
    return false;
  }
};
```

## Problem 3
```c++
int _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    int sum = 0;
    unordered_map<int, int> index;
    index[0] = -1;
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      int r = k ? sum % k : sum;
      if (index.find(r) == index.end())
        index[r] = i;
      else
        if (i - index.find(r)->second > 1)
          return true;
    }
    return false;
  }
};
```

## Problem 4
```c++
class Solution {
private:
  int lengthOf(int n) {
    int len = 0;
    while (n) {
      len++;
      n = n / 10;
    }
    return len;
  }
  
  void count(int& p0, int& p1, int& p2, set<int>& d, int n) {
    p0 = p1 = p2 = 0;
    for (auto it : d) {
      if (it < n) p0++;
      if (it == n) p1++;
      if (it > n) p2++;
    }
  }
  
  int getLast(int& n) {
    int last = n % 10;
    n = n / 10;
    return last;
  }
public:
  int atMostNGivenDigitSet(vector<string>& D, int N) {
    if (N <= 0) return 0;
    
    set<int> d;
    for (auto it : D) d.insert((int)(it[0] - '0'));
    
    int sum = 0;
    int nlen = lengthOf(N);
    int sized = d.size();
    
    int t = 1;
    for (int i = 1; i < nlen; ++i) sum += (t *= sized);
    
    int f0, f1, f2, c0, c1, c2;
    count(f0, f1, f2, d, getLast(N));
    f2 += (f0 + f1);
    while (N) {
      count(c0, c1, c2, d, getLast(N));
      int t0, t1, t2;
      t0 = c0 * f2;
      t1 = c1 * (f0 + f1);
      t2 = (c0 + c1 + c2) * f2;
      f0 = t0;
      f1 = t1;
      f2 = t2;
    }
    sum += (f0 + f1);
    return sum;
  }
};
```
