## 1. [225] Implement Stack using Queues

https://leetcode.com/problems/implement-stack-using-queues/description/

### 1.1 Approach

- Prepare a queue structure to fulfill the issue requirement
- When pushing, take the queue which is not empty to push into, keep track the value every push to make the `top` up to date
- When popping, take all n-1 first element from one queue to another and return the last element.

### 1.2 Code

```js
 var Queue = function () {
  const data = []
  this.push = (val) => {
    data.push(val)
  }
  this.pop = () => data.shift()
  this.top = () => data[0];
  this.empty = () => data.length === 0
  this.size = () => data.length
  this.toString = () => JSON.stringify(data)
}

var MyStack = function () {
  this.queue1 = new Queue();
  this.queue2 = new Queue();
  this.popper = (q1, q2) => {
    while (q1.size() !== 1) {
      this.topV = q1.pop();
      q2.push(this.topV);
    }
    return q1.pop()
  }
};

/**
 * Push element x onto stack.
 * @param {number} x
 * @return {void}
 */
MyStack.prototype.push = function (x) {
  this.topV = x;
  if (this.queue1.empty()) {
    return this.queue2.push(x)
  }
  this.queue1.push(x)
};

/**
 * Removes the element on top of the stack and returns that element.
 * @return {number}
 */
MyStack.prototype.pop = function () {
  if (this.queue1.empty()) {
    return this.popper(this.queue2, this.queue1)
  }
  return this.popper(this.queue1, this.queue2)
};

/**
 * Get the top element.
 * @return {number}
 */
MyStack.prototype.top = function () {
  return this.topV
};

/**
 * Returns whether the stack is empty.
 * @return {boolean}
 */
MyStack.prototype.empty = function () {
  return this.queue1.empty() && this.queue2.empty()
};
```

## 2. [232] Implement Queue using Stacks

https://leetcode.com/problems/implement-queue-using-stacks/description/

### 2.1 Approach
- Prepare a stack structure to fulfill the issue's requirement
- Use stack 1 only for pushing.
- When popping, if stack 2 is empty, move all elements from stack 1 to stack 2 (using stack push,pop), pop from stack 2.
- To get peak element, we use the same method as pop, but not remove the peak element.

### 2.2 Code

```js
class MyStack {
  constructor() {
    const data = []
    this.pop = () => data.pop()
    this.push = (val) => {
      data.push(val)
    }
    this.top = () => data.slice(-1)[0]
    this.empty = () => data.length === 0
    this.size = () => data.length
  }
}

var MyQueue = function () {
  this.stack1 = new MyStack();
  this.stack2 = new MyStack();
};

/**
 * Push element x to the back of queue.
 * @param {number} x
 * @return {void}
 */
MyQueue.prototype.push = function (x) {
  this.stack1.push(x)
};

/**
 * Removes the element from in front of queue and returns that element.
 * @return {number}
 */
MyQueue.prototype.pop = function () {
  if (this.stack2.empty()) {
    while (!this.stack1.empty()) {
      this.stack2.push(this.stack1.pop())
    }
  }
  return this.stack2.pop()
};

/**
 * Get the front element.
 * @return {number}
 */
MyQueue.prototype.peek = function () {
  if (this.stack2.empty()) {
    while (!this.stack1.empty()) {
      this.stack2.push(this.stack1.pop())
    }
  }
  return this.stack2.top();
};

/**
 * Returns whether the queue is empty.
 * @return {boolean}
 */
MyQueue.prototype.empty = function () {
  return this.stack1.empty() && this.stack2.empty()
};
```

## 3. [950] Reveal Cards In Increasing Order

https://leetcode.com/problems/reveal-cards-in-increasing-order/description/

### 3.1 Approach
- Rule of the issue would be taken from example:
```
The deck starts as [2,13,3,11,5,17,7], where 2 is the top of the deck.
We reveal 2, and move 13 to the bottom. The deck is now [3,11,5,17,7,13]. 
We reveal 3, and move 11 to the bottom. The deck is now [5,17,7,13,11]. 
We reveal 5, and move 17 to the bottom. The deck is now [7,13,11,17]. 
We reveal 7, and move 13 to the bottom. The deck is now [11,17,13]. 
We reveal 11, and move 17 to the bottom. The deck is now [13,17]. 
We reveal 13, and move 17 to the bottom. The deck is now [17]. 
We reveal 17.
```
- Sort the deck DESC, prepare an empty array (namely `result`)
- Loop through the sorted deck, 
  - push each element into `result`
  - take the last element of `result` move to top

### 3.2 Code

```js
/**
 * @param {number[]} deck
 * @return {number[]}
 */
var deckRevealedIncreasing = function (deck) {
    const sortedDeck = deck.sort((a, b) => b - a);
    let result = []
    while (sortedDeck.length !== 0) {
      result = result.length !== 0 ? [result.pop(), ...result] : []
      result = [sortedDeck.shift(), ...result]
    }
    return result
  };
```

## 4. [622] Design Circular Queue

https://leetcode.com/problems/design-circular-queue/description/
### 4.1. Approach
- Straightforward

### 4.2 Code

```js
var Node = function (val) {
  this.val = val;
  this.next = null
}
/**
 * @param {number} k
 */
var MyCircularQueue = function (k) {
  this.capacity = k
  this.size = 0;
  this.front = null;
  this.rear = null;
};

/**
 * @param {number} value
 * @return {boolean}
 */
MyCircularQueue.prototype.enQueue = function (value) {
  if (this.capacity === this.size) {
    return false
  }
  if (this.front == null) {
    this.front = new Node(value)
    this.rear = this.front;

  } else {
    this.rear.next = new Node(value);
    this.rear = this.rear.next;
  }
  this.size++;
  return true;
};

/**
 * @return {boolean}
 */
MyCircularQueue.prototype.deQueue = function () {
  if (this.size === 0) {
    return false;

  }
  if (this.size === 1) {
    this.front = null;
    this.rear = null;

  } else {
    const next = this.front.next;
    this.front.next = null;
    this.front = next;
  }

  this.size--;
  return true;
};

/**
 * @return {number}
 */
MyCircularQueue.prototype.Front = function () {
  if (this.size === 0) {
    return -1;
  }
  return this.front.val
};

/**
 * @return {number}
 */
MyCircularQueue.prototype.Rear = function () {
  if (this.size === 0) {
    return -1;
  }

  return this.rear.val
};

/**
 * @return {boolean}
 */
MyCircularQueue.prototype.isEmpty = function () {
  return this.size === 0
};

/**
 * @return {boolean}
 */
MyCircularQueue.prototype.isFull = function () {
  return this.size === this.capacity
};
```

