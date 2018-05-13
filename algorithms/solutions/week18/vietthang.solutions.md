# Problem 1

```js
Initialize your data structure here.
 */
var MinStack = function() {
    this.data = []    
};

/** 
 * @param {number} x
 * @return {void}
 */
MinStack.prototype.push = function(x) {
    this.data.push(x)    
};

/**
 * @return {void}
 */
MinStack.prototype.pop = function() {
    this.data.splice(this.data.length - 1, 1)    
};

/**
 * @return {number}
 */
MinStack.prototype.top = function() {
    return this.data[this.data.length - 1]
};

/**
 * @return {number}
 */
MinStack.prototype.getMin = function() {
    let min = -Math.max();    
    
    for (let i = 0; i < this.data.length; i++) {
        if (this.data[i] < min) min = this.data[i]
    }
    
    return min
};

/** 
 * Your MinStack object will be instantiated and called as such:
 * var obj = Object.create(MinStack).createNew()
 * obj.push(x)
 * obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.getMin()
 */
```
