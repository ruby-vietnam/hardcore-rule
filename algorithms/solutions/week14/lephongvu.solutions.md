# Bai1:  https://leetcode.com/problems/power-of-four

```
class Solution {
public:
    bool isPowerOfFour(int num) {
        return ((num-1)&num)==0 && (num-1)%3==0;
    }
};
```
Explain:
a convert a number power of 4 we will have a binary with format 10....0 with the numbers of zero is even.
Then Check (num-1) & num == 0 to check if the number have format  10...0 in binary.
And (num-1)%3 to check if number is power of 4, not 2.
(4 ^ k -1) % 3 == 0 // Because 4^k - 1 = (4 -1 ) (4^ k-1 + .....+ 1)
while (2^k -1 ) %3 != 0
Beside that, we could use (num & 0x55555555) != 0 instead calculate modulo of 3. 

# Bai 2: https://leetcode.com/problems/number-of-islands/description/
