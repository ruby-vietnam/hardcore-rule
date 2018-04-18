# Problem 1: Min Stack

Status:
```
  ✔ Accepted
  ✔ 18/18 cases passed (76 ms)
  ✔ Your runtime beats 69.07 % of javascript submissions
```

Approach: Using two stack, one for storing data, another one for storing minum value.

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
