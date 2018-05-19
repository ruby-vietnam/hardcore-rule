# Problem #1: 242 - Valid Anagram

Status: 
```
  ✔ Accepted
  ✔ 34/34 cases passed (0 ms)
  ✔ Your runtime beats 86.14 % of c submissions
```

Naive solution:

```
bool isAnagram(char* s, char* t) {
  int* cs = (int*)calloc(26, sizeof(int));
  int* ct = (int*)calloc(26, sizeof(int));

  while (*s != '\0') {
    cs[*s - 97] += 1;
    s++;
  }

  while (*t != '\0') {
    ct[*t - 97] += 1;
    t++;
  }

  for (int i = 0; i < 26; i++) {
    if (cs[i] != ct[i]) return false;
  }

  return true;
}
```
