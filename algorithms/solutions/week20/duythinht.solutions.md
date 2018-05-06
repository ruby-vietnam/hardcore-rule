### Problem 1:

https://leetcode.com/problems/plus-one/description/

```C
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int incr = 1;
    *returnSize = digitsSize;
    
    do {
        digitsSize--;
        int val = digits[digitsSize] + incr;
        digits[digitsSize] =  val % 10;
        incr = val / 10;
    } while(digitsSize && incr);
    
    if (incr) {
        digits[(*returnSize)++] = 0;
        digits[0] = incr;
    }
    return digits;
}
```
