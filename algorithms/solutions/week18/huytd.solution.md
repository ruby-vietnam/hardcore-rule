# Problem 1: Min Stack

Status: Segmentation Fault T_T

Approach: Using two stack, one for storing data, another one for storing minum value.

```c
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _stack {
  int *data;
  int last;
  int capacity;
} Stack;

Stack* stack_init(int size) {
  Stack* stack = (Stack*)malloc(sizeof(Stack*));
  stack->data = (int*)malloc(sizeof(int) * size);
  for (int i = 0; i < size; i++) {
    stack->data[i] = -0x7FFFFFFF;
  }
  stack->last = -1;
  stack->capacity = size;
  return stack;
}

void stack_push(Stack* target, int value) {
  if (target->last < target->capacity - 1) {
    target->last += 1;
    target->data[target->last] = value;
  }
}

void stack_pop(Stack* target) {
  if (target->last >= 0) {
    target->data[target->last] = -0x7FFFFFFF;
    target->last -= 1;
  }
}

int stack_empty(Stack* target) {
  return target->last == -1;
}

int stack_peek(Stack* target) {
  if (target->last != -1) {
    return target->data[target->last];
  }
  return -0x7FFFFFFF;
}

void stack_free(Stack* target) {
  target->last = -1;
  target->data = (int*)malloc(sizeof(int) * target->capacity);
}

typedef struct {
  Stack* data_stack;
  Stack* min_stack;
} MinStack;

MinStack* minStackCreate(int maxSize) {
  MinStack* self = (MinStack*)malloc(sizeof(MinStack*));
  self->data_stack = stack_init(maxSize);
  self->min_stack = stack_init(maxSize);
  return self;
}

void minStackPush(MinStack* obj, int x) {
  stack_push(obj->data_stack, x);
  if (stack_empty(obj->min_stack)) {
    stack_push(obj->min_stack, x);
  } else {
    if (stack_peek(obj->min_stack) >= x) {
      stack_push(obj->min_stack, x);
    }
  }
}

void minStackPop(MinStack* obj) {
  int data = stack_peek(obj->data_stack);
  int min = stack_peek(obj->min_stack);
  if (data == min) {
    stack_pop(obj->data_stack);
    stack_pop(obj->min_stack);
  } else {
    stack_pop(obj->data_stack);
  }
}

int minStackTop(MinStack* obj) {
  return stack_peek(obj->data_stack);
}

int minStackGetMin(MinStack* obj) {
  return stack_peek(obj->min_stack);
}

void minStackFree(MinStack* obj) {
  stack_free(obj->data_stack);
  stack_free(obj->min_stack);
}
```
