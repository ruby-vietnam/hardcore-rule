/**
 * Initialize your data structure here.
 */
var Queue = function() {
    this.queue = []
    
    const pushToBack = (item) => {
        this.queue.push(item)
    }
    const peekFromFront = () => this.queue[0]
    const popFromFront = () => this.queue.splice(0, 1)[0]
    const size = () => this.queue.length
    const isEmpty = () => this.queue.length === 0
    return {
        pushToBack, peekFromFront, popFromFront, size, isEmpty
    }
}
var MyStack = function() {
    this.queue1 = new Queue()
    this.queue2 = new Queue()
};

/**
 * Push element x onto stack. 
 * @param {number} x
 * @return {void}
 */
MyStack.prototype.push = function(x) {
    this.queue1.pushToBack(x)
};

/**
 * Removes the element on top of the stack and returns that element.
 * @return {number}
 */
MyStack.prototype.pop = function() {
    const queueSize = this.queue1.size()
    for (let i = 0; i < queueSize - 1; i++) {
        this.queue2.pushToBack(this.queue1.popFromFront())
    }
    var ret = this.queue1.popFromFront()
    this.queue1 = this.queue2
    this.queue2 = new Queue()
    return ret
};

/**
 * Get the top element.
 * @return {number}
 */
MyStack.prototype.top = function() {
    const queueSize = this.queue1.size()
    for (let i = 0; i < queueSize - 1; i++) {
        this.queue2.pushToBack(this.queue1.popFromFront())
    }
    var ret = this.queue1.popFromFront()
    this.queue2.pushToBack(ret)
    this.queue1 = this.queue2
    this.queue2 = new Queue()
    return ret
};

/**
 * Returns whether the stack is empty.
 * @return {boolean}
 */
MyStack.prototype.empty = function() {
    return this.queue1.size() == 0
};

/** 
 * Your MyStack object will be instantiated and called as such:
 * var obj = Object.create(MyStack).createNew()
 * obj.push(x)
 * var param_2 = obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.empty()
 */
