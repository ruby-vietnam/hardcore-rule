class NumArray {
    vector<int> n;
public:
    NumArray(vector<int> nums) {
        n = nums;
    }
    
    int sumRange(int i, int j) {
        int s = 0;
        for (int ii = i; ii <= j; ii++) {
            s += n[ii];
        }
        return s;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
