class Solution {
public:
    int hammingDistance(int x, int y) {
        return __builtin_popcountll(x ^ y);
    }
};