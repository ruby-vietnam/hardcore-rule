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
