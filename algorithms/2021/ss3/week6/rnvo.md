# 1. Linked List Cycle

https://leetcode.com/problems/linked-list-cycle/

## 1.1 Summary

Traverse linked list using two pointers

Move one pointer(slow) 1 step and the other is 2 steps

If theses pointers meet at the same node then there is a loop

## 1.2. Code

```js
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {boolean}
 */
var hasCycle = function(head) {
    if (!head) return false
    let slow  = head
    let fast = head
    
    while(fast.next && fast.next.next) {
        slow = slow.next;
        fast = fast.next.next;
        if (slow === fast) return true
    }
    return false
};
```

# 2. Intersection of Two Linked Lists

https://leetcode.com/problems/intersection-of-two-linked-lists/

## 2.1 Summary

Traverse from A -> B (and vice versa for B) until A = B (val | null)


## 2.2. Code

```js
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */
var getIntersectionNode = function(headA, headB) {
    if (!headA || !headB) return null;
    let a = headA;
    let b = headB;

    while(a !== b) {
        a = a ? a.next : headB;
        b = b ? b.next : headA;
    }
    
    return a;
};
```


# 3. Binary Search Tree Iterator

https://leetcode.com/problems/binary-search-tree-iterator/

## 3.1 Summary

Same approach with inorder travesal of Tree

Push root push every left node to the arr until its null

Get the value and continue with the right node

## 3.2. Code

```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 */
let arr = [];
let node;
var BSTIterator = function(root) {
    node = root;
};

/**
 * @return {number}
 */
BSTIterator.prototype.next = function() {
    while(node !== null) {
        arr.push(node);
        node = node.left;
    }
    node = arr.pop();
    const result = node.val;
    node = node.right;
    return result;
};

/**
 * @return {boolean}
 */
BSTIterator.prototype.hasNext = function() {
    return  node !== null ||arr.length > 0;
};

/** 
 * Your BSTIterator object will be instantiated and called as such:
 * var obj = new BSTIterator(root)
 * var param_1 = obj.next()
 * var param_2 = obj.hasNext()
 */
```


# 4. Implement Trie (Prefix Tree)

https://leetcode.com/problems/implement-trie-prefix-tree/

## 4.1 Summary

```
Treat word as a tree -> push every character into that tree and mark endWord breakpoint to search later

            a
        i   c   p
    m       t       p
                        l
                            e

```


## 4.2. Code

```js
/**
 * Initialize your data structure here.
 */

var Trie = function() {
    this.root = {}
};

/**
 * Inserts a word into the trie. 
 * @param {string} word
 * @return {void}
 */
Trie.prototype.insert = function(word) {
    let node = this.root
    
    for(const ch of word){
        if (node[ch] === null) node[ch] = {}
        node = node[ch]
    }
    node.endWord = true
};

/**
 * Returns if the word is in the trie. 
 * @param {string} word
 * @return {boolean}
 */
Trie.prototype.search = function(word) {
    const node = this.traverse(word)
    return node !== null && node.endWord === true
};

/**
 * Returns if there is any word in the trie that starts with the given prefix. 
 * @param {string} prefix
 * @return {boolean}
 */
Trie.prototype.startsWith = function(prefix) {
    return this.traverse(prefix) !== null
};

Trie.prototype.traverse = function (word) {
    let node = this.root
    for (const ch of word) {
        node = node[ch]
        if (node === null) return null
    }
    return node
}

/** 
 * Your Trie object will be instantiated and called as such:
 * var obj = new Trie()
 * obj.insert(word)
 * var param_2 = obj.search(word)
 * var param_3 = obj.startsWith(prefix)
 */
```