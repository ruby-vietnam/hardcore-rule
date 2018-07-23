#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int shortestSubarray(vector<int> A, int K) {
    int N = A.size(), res = N + 1;
    vector<int> prefixes(N + 1, 0);

    for (int i = 0; i < N; i++) {
      prefixes[i + 1] += prefixes[i] + A[i];
    }

    deque<int> d;
    for (int i = 0; i < N + 1; i++) {
      while (d.size() > 0 && prefixes[i] - prefixes[d.front()] >= K) {
        res = min(res, i - d.front());
        d.pop_front();
      }

      while (d.size() > 0 && prefixes[i] <= prefixes[d.back()]) {
        d.pop_back();
      }

      d.push_back(i);
    }

    return res <= N ? res : -1;
  }
};
