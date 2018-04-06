# Problem 1:

'''cpp

//4^x = Num, check xem x có là số nguyên hay không

class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num <= 0) return 0;
        return (double)((int) (log(num) / log(4))) == log(num)/log(4);
    }
};
