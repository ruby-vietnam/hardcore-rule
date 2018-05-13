# 66

```c
int* plusOne(int* digits, int digitsSize, int* returnSize) {
  int remand = 0;
  int index = digitsSize - 1;
  int sum = 0;
  *returnSize = digitsSize;
  int *result = malloc(sizeof(int) * (*returnSize + 1));
  memcpy(result, digits, sizeof(int) * digitsSize);

  while (index >= 0) {
    sum = result[index] + 1;
    if (sum < 10) {
      result[index] = sum;
      remand = 0;
      break;
    } else {
      result[index] = sum - 10;
      remand = 1;
      index--;
    }
  }

  if (remand != 0) {
    *returnSize = *returnSize + 1;
    memmove(result + 1, result, sizeof(int) * digitsSize);
    result[0] = 1;
  }

  return result;
}
```
