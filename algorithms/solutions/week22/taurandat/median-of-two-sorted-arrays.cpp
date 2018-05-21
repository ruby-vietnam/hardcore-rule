/*
 *
 * Link: https://leetcode.com/problems/median-of-two-sorted-arrays/
 *
 * 2080 / 2080 test cases passed.
 * Status: Accepted
 * Runtime: 62 ms
 * Your runtime beats 86.84 % of cpp submissions.
 *
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        if (m > n) {
            using std::swap;
            swap(nums1, nums2);
            swap(m, n);
        }

        int i_min = 0;
        int i_max = m;
        int half_length = (m + n + 1) / 2;
        while (i_min <= i_max) {
            int i = (i_min + i_max) / 2;
            int j = half_length - i;

            if (i < m && nums2[j-1] > nums1[i]) {
                i_min = i + 1;
            } else if (i > 0 && nums1[i-1] > nums2[j]) {
                i_max = i - 1;
            } else {
                int max_left = 0;
                if (i == 0) {
                    max_left = nums2[j-1];
                } else if (j == 0) {
                    max_left = nums1[i-1];
                } else {
                    max_left = max(nums1[i-1], nums2[j-1]);
                }

                if ((m + n) % 2 == 1) {
                    return (double)(max_left);
                }

                int min_right = 0;
                if (i == m) {
                    min_right = nums2[j];
                } else if (j == n) {
                    min_right = nums1[i];
                } else {
                    min_right = min(nums1[i], nums2[j]);
                }

                return (max_left + min_right) / double(2.0);
            }
        }
    }
};