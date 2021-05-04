# Problem 1
```js
/**
 * Initialize your data structure here.
 */
var MyStack = function() {
    this.items = [];
};

/**
 * Push element x onto stack.
 * @param {number} x
 * @return {void}
 */
MyStack.prototype.push = function(x) {
    this.items.push(x);
};

/**
 * Removes the element on top of the stack and returns that element.
 * @return {number}
 */
MyStack.prototype.pop = function() {
    return this.items.pop();
};

/**
 * Get the top element.
 * @return {number}
 */
MyStack.prototype.top = function() {
    return this.items[this.items.length - 1];
};

/**
 * Returns whether the stack is empty.
 * @return {boolean}
 */
MyStack.prototype.empty = function() {
    return !this.items.length;
};

```

# Problem 2
```js
const canMutate = (current, next) => {
  let count = 0
  for (let i = 0; i < current.length; i++) {
    if (current[i] !== next[i]) {
      count++;
    }
  }
  return count === 1;
}

var minMutation = function(start, end, bank) {
  const uniqueBank = new Set(bank);
  if (!uniqueBank.has(end)) {
    return -1;
  }
  const visited = new Set();
  visited.add(start);

  const queue = [];
  queue.push(start);
  let mutationCount = 0;

  while (queue.length) {
    const length = queue.length;
    for (let i = 0; i < length; i++) {
      const currentMutation = queue.shift();
      if (visited.has(end)) {
        return mutationCount;
      }
      uniqueBank.forEach(nextMutation => {
        if (!visited.has(nextMutation) && canMutate(currentMutation, nextMutation)) {
          queue.push(nextMutation);
          visited.add(nextMutation);
        }
      });
    }

    mutationCount++;
  }

  if (!visited.has(end)) {
    return -1;
  }
  return mutationCount;
};
```

# Problem 3
```js
/**
 * @param {number[]} nums
 */
var NumArray = function(nums) {
    this.nums = nums;
};

/**
 * @param {number} i
 * @param {number} j
 * @return {number}
 */
NumArray.prototype.sumRange = function(i, j) {
    return Math.sum(...this.nums.slice(i, j + 1));
};
```

# Problem 4
```js
var FreqStack = function() {
    this.stacks = [];
    this.frequencyTable = {};
    this.topFreq = 0;
};
FreqStack.prototype.push = function(x) {
    if (!this.frequencyTable[x]) {
      this.frequencyTable[x] = 0;
    }
    this.frequencyTable[x]++;

    if(this.frequencyTable[x] > this.topFreq) {
       this.topFreq = this.frequencyTable[x];
    }
    if (!this.stacks[this.frequencyTable[x]]) {
      this.stacks[this.frequencyTable[x]] = [];
    }
    this.stacks[this.frequencyTable[x]].push(x);
};
FreqStack.prototype.pop = function() {
	const res = this.stacks[this.topFreq].pop();
  this.frequencyTable[res]--;

  if (this.stacks[this.topFreq].length === 0) {
    this.topFreq--;
  }

  return res;
};
```
