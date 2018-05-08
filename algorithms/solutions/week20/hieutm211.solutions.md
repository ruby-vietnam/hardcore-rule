##problem 1

//cpp code

class Solution {
public:
    vector<int> plusOne(vector<int>& digits){
        int i = digits.size()-1;
        while (i >= 0 && digits[i] == 9) --i;

        if (i == -1){
            i = 0;
            digits[0] = 0;
            digits.push_back(0);
        }
        
        ++digits[i];
        for(int j = i+1; j < digits.size(); ++j) digits[j] = 0;
        return digits;
    }
};
