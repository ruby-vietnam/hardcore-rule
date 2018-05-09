/*
 * Link: https://leetcode.com/problems/hamming-distance
 *
 * 149 / 149 test cases passed.
 * Status: Accepted
 * Runtime: 6 ms
 * Your runtime beats 72.58 % of cpp submissions.
 *
 */

class Solution {
public:
    int hammingDistance(int x, int y) {
        return __builtin_popcountll(x ^ y);
    }
};