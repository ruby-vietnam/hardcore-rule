class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<int> f(K + 1, 0);
        int result;
        for (result = 0; f[K] < N; result++) {
            int k = K;
            for (int k = K; k > 0; k--) {
                f[k] += f[k - 1] + 1;
            }
        }
        return result;
    }
};