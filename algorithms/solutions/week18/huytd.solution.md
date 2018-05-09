# Problem 1: Min Stack

Status:
```
  ✔ Accepted
  ✔ 18/18 cases passed (76 ms)
  ✔ Your runtime beats 69.07 % of javascript submissions
```

```
  ✔ Accepted
  ✔ 18/18 cases passed (12 ms)
  ✔ Your runtime beats 63.87 % of c submissions

```

Approach: 

- For JavaScript version, I'm using two stack, one for storing data, another one for storing minum value.
- For C version, I'm using two array

Both of them are O(1) for all actions.

JavaScript version
```javascript
/**
 * initialize your data structure here.
 */
var MinStack = function(m) {
    this.data = [];
    this.min = [];
    this.cap = m ? m : 0x7FFFFFFF;
};

Array.prototype.peek = function() {
    return this[this.length - 1];
};

/** 
 * @param {number} x
 * @return {void}
 */
MinStack.prototype.push = function(x) {
    if (this.data.length < this.cap) {
        if (this.min.peek() != undefined) {
            if (this.min.peek() >= x) {
                this.min.push(x);
            }
        } else {
            this.min.push(x);
        }
        this.data.push(x);
    }
};

/**
 * @return {void}
 */
MinStack.prototype.pop = function() {
    let last = this.data.peek();
    if (this.min.peek() != undefined && this.min.peek() >= last) {
        this.min.pop();
    }
    this.data.pop();
};

/**
 * @return {number}
 */
MinStack.prototype.top = function() {
    return this.data.peek();
};

/**
 * @return {number}
 */
MinStack.prototype.getMin = function() {
    return this.min.peek();
};
```

C version

```c
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct {
  int* data;
  int* min;
  int cap;
  int data_size;
  int min_size;
} MinStack;

MinStack* minStackCreate(int maxSize) {
  MinStack* self = (MinStack*)malloc(sizeof(MinStack));
  self->data = (int*)malloc(sizeof(int) * maxSize);
  self->min = (int*)malloc(sizeof(int) * maxSize);
  self->data_size = -1;
  self->min_size = -1;
  self->cap = maxSize;
  return self;
}

void minStackPush(MinStack* obj, int x) {
  if (obj->data_size < obj->cap) {
    if (obj->min_size > -1) {
      if (obj->min[obj->min_size] >= x) {
        obj->min_size += 1;
        obj->min[obj->min_size] = x;
      }
    } else {
      obj->min_size = 0;
      obj->min[obj->min_size] = x;
    }
    obj->data_size += 1;
    obj->data[obj->data_size] = x;
  }
}

void minStackPop(MinStack* obj) {
  int last = obj->data[obj->data_size];
  int min = obj->min[obj->min_size];
  if (min >= last) {
    obj->min_size -= 1;
  }
  obj->data_size -= 1;
}

int minStackTop(MinStack* obj) {
  return obj->data[obj->data_size];
}

int minStackGetMin(MinStack* obj) {
  return obj->min[obj->min_size];
}

void minStackFree(MinStack* obj) {
  obj->data_size = -1;
  obj->min_size = -1;
  obj->data = (int*)malloc(sizeof(int) * obj->cap);
  obj->min = (int*)malloc(sizeof(int) * obj->cap);
}
```

# Problem 2: Restore IP Addresses

Status:

```
  ✔ Accepted
  ✔ 147/147 cases passed (0 ms)
  ✔ Your runtime beats 44.44 % of c submissions
```

Approach: Try and fail, we build each component by grabbing 1..3 characters each, then check if its a valid IP address or not.

```c
int len(char* s) {
  int size = 0;
  while (s[size]) {
    size++;
  }
  return size;
}

char* substr(char* src, int start, int len) {
  char* dst = (char*)malloc(sizeof(char) * (len));
  strncpy(dst, src+start, len);
  dst[len] = '\0';
  return dst;
}

int is_valid(char* node) {
  if (atoi(node) > 255) return 0;
  if (len(node) > 1 && node[0] == '0') return 0;
  return 1;
}

char** restoreIpAddresses(char* ip, int* returnSize) {
  char** result = (char**)calloc(1024, sizeof(void*));
  *returnSize = 0;
  int size = len(ip);
  for (int fi = 1; fi <= 3; fi++) {
    int first_index = fi;
    if (size - first_index > 0) {
      for (int si = 1; si <= 3; si++) {
        int second_index = first_index + si;
        if (size - second_index > 0) {
          for (int ti = 1; ti <= 3; ti++) {
            int sum = fi + si + ti;
            int remaining = size - sum;
            if (remaining <= 3 && remaining >= 1) {
              char* p1 = substr(ip, 0, fi);
              char* p2 = substr(ip, first_index, si);
              char* p3 = substr(ip, second_index, ti);
              char* p4 = substr(ip, sum, remaining);
              if (is_valid(p1) && is_valid(p2) && is_valid(p3) && is_valid(p4)) {
                int chunk_size = fi + si + ti + remaining + 3;
                *returnSize += 1;
                int newSize = *returnSize;
                result[newSize-1] = (char*)malloc(sizeof(char)*chunk_size);
                sprintf(result[newSize-1], "%s.%s.%s.%s", p1, p2, p3, p4);
              }
            }
          }
        }
      }
    }
  }
  return result;
}
```

# Problem 3: Wildcard Matching

Status:
```
  ✔ Accepted
  ✔ 1808/1808 cases passed (32 ms)
  ✔ Your runtime beats 41.46 % of c submissions
```

Man, I like how C using pointer incremental to consume a string. It's brilliant!!!

```c
bool isMatch(char* s, char* p) {
  int ls = len(s);
  int lp = len(p);
  char* star = NULL;
  char* smatch = s;
  while (*s) {
    // the simple case: matching any single character
    if (*p == '?' || *p == *s) {
      s++;
      p++;
      continue;
    }
    // the hard case: matching star
    if (*p == '*') {
      star = p;
      smatch = s;
      p++;
      continue;
    }
    // if we're having a star matching
    if (star) {
      p = star + 1;
      smatch++;
      s = smatch;
      continue;
    }
    // nothing matched
    return false;
  }

  // if no character remaining in s
  // but p still has some pattern
  // we just discard it
  while (*p == '*') p++;

  return !*p;
}
```

# Bonus Problem: Edit Distance

Status:
```
  ✔ Accepted
  ✔ 1146/1146 cases passed (192 ms)
  ✔ Your runtime beats 0 % of c submissions
```

Nothing to say, this is a classical dynamic programming problem.

```c
int min(int a, int b, int c) {
  if (a > b) {
    return b > c ? c : b;
  } else {
    return a > c ? c : a;
  }
}

int minDistance(char* word1, char* word2) {
  int l1 = strlen(word1);
  int l2 = strlen(word2);
  if (!l1 && !l2) return 0;
  if (!l1) return l2;
  if (!l2) return l1;
  int D[l1+1][l2+1];

  for (int i = 0; i <= l1; i++) {
    for (int j = 0; j <= l2; j++) {
      if (i == 0) {
        D[i][j] = j;
      } else if (j == 0) {
        D[i][j] = i;
      } else if (word1[i-1] == word2[j-1]) {
        D[i][j] = D[i-1][j-1];
      } else {
        D[i][j] = 1 + min(D[i][j-1],   // Insert
                          D[i-1][j],   // Remove
                          D[i-1][j-1]);// Replace
      }
    }
  }

  return D[l1][l2];
}
```
