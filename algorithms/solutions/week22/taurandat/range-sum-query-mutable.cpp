/*
 *
 * Link: https://leetcode.com/problems/range-sum-query-mutable/
 *
 * 10 / 10 test cases passed.
 * Status: Accepted
 * Runtime: 117 ms
 * Your runtime beats 43.28 % of cpp submissions.
 *
 */

class NumArray {
public:
    int n;
    vector<int> t;
    NumArray(vector<int> nums) {
        n = (int)(nums.size());
        if (n > 0) {
            t.resize(4 * n);
            build(nums, 1, 0, n-1);
        }
    }

    void build(vector<int>& nums, int index, int left, int right) {
        if (left == right) {
            t[index] = nums[left];
        } else {
            int mid = getMid(left, right);
            build(nums, index*2, left, mid);
            build(nums, index*2+1, mid+1, right);
            t[index] = t[index*2] + t[index*2+1];
        }
    }

    void update(int i, int val) {
        updateUtil(i, val, 0, n-1, 1);
    }

    int sumRange(int i, int j) {
        return sumUtil(i, j, 0, n-1, 1);
    }

private:
    int getMid(int left, int right) {
        return (left + right) / 2;
    }

    int sumUtil(int left, int right, int t_left, int t_right, int index) {
        if (left > right) { return 0; }
        if (left == t_left && right == t_right) { return t[index]; }

        int t_mid = getMid(t_left, t_right);
        return sumUtil(left, min(right, t_mid), t_left, t_mid, index*2) +
               sumUtil(max(left, t_mid+1), right, t_mid+1, t_right, index*2+1);
    }

    void updateUtil(int position, int new_val, int t_left, int t_right, int index) {
        if (t_left == t_right) {
            t[index] = new_val;
        } else {
            int t_mid = getMid(t_left, t_right);
            if (position <= t_mid) {
                updateUtil(position, new_val, t_left, t_mid, index*2);
            } else {
                updateUtil(position, new_val, t_mid+1, t_right, index*2+1);
            }
            t[index] = t[index*2] + t[index*2+1];
        }
    }
};
