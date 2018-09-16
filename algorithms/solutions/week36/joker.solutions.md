## Problem 4: [Sum of Subsequence Widths] (https://leetcode.com/problems/sum-of-subsequence-widths/description/)
```c++
#include <cstdlib>
#include <vector>
#include <stdio.h>
#include <stdint.h>
using namespace std;
#define MOD 1000000007
#define MAX 20000

class Solution {
public:
    int sumSubseqWidths(vector<int>& a) {
        vector<int> c(20010, 0);
                vector<uint64_t> power2(20010, 0);

                power2[0] = 1;
                for (int i = 1; i <= MAX; ++i) {
                        power2[i] = (power2[i - 1]*2) % MOD;
                }

                int n = a.size();

                for (int i = 0; i < n; ++i) {
                        c[a[i]]++;
                }

                uint64_t lt, gt, last_gt = 0, tmp, res = 0;

                for (int i = 1; i <= MAX; ++i) {
                        gt = last_gt + c[i - 1];
                        lt = n - (gt + c[i]);
                        last_gt = gt;
                        if (c[i] > 0) {
                                tmp = (((MOD + power2[gt] - power2[lt]) * i) % MOD) * (power2[c[i]] - 1) % MOD;
                                res = (res + tmp) % MOD;
                        }
                }

                return res;
    }
};
