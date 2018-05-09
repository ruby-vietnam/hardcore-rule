# Problem 1: #66 Plus One

Status:
```
  ✔ Accepted
  ✔ 109/109 cases passed (0 ms)
  ✔ Your runtime beats 47.88 % of c submissions
```

Solution:

In case the result increased its length, for example `999 + 1 = 1000`, the program need to reallocate new memory blocks and copy all of the exist data into the new one.

This is inefficient, so, to avoid that, I preallocate an extra memory block for all the case (`sizeof(int) * (digitsSize + 1)`), then in the end, if we don't need to use extra space, we just discard it by increasing the result's memory address by 1.

```c
int* plusOne(int* digits, int digitsSize, int* returnSize) {
  *returnSize = digitsSize + 1;
  int* result = (int*)malloc(sizeof(int) * (digitsSize + 1));
  int flag = 1;
  for (int i = digitsSize - 1; i >= 0; i--) {
    result[i + 1] = flag + digits[i];
    if (result[i + 1] > 9) {
      result[i + 1] %= 10;
      flag = 1;
    } else {
      flag = 0;
    }
  }
  result[0] = flag;
  if (!result[0]) {
    result += 1;
    *returnSize -= 1;
  }
  return result;
}
```
