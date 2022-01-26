# 1. Binary Tree Inorder Traversal

https://leetcode.com/problems/binary-tree-inorder-traversal/

## 1.1 Summary

## 1.2. Code

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
 * @return {number[]}
 */
var inorderTraversal = function(root) {
    if (!root) return []
    const arr = []
    const result = []
    let node = root;
    while(node !== null || arr.length > 0) {
        while(node !== null) {
            arr.push(node)
            node = node.left;    
        }
        const temp = arr.pop()
        result.push(temp.val)
        node = temp.right
    }
    return result
};
```

# 2. Same Tree

https://leetcode.com/problems/same-tree/

## 2.1 Summary

## 2.2. Code

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
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {boolean}
 */
var isSameTree = function(p, q) {
    if (!p && !q) {
        return true;
    }
    
    if (!p || !q || p.val !== q.val) {
        return false;
    }
    
    return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
}
```


# 3. Remove Duplicates from Sorted List II

https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/submissions/

## 3.1 Summary

## 3.2. Code

```js
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var deleteDuplicates = function(head) {
    let curr = head,
    prev = null;
    
    while(curr && curr.next) {
        // If the value has been duplicated
        if(curr.val === curr.next.val) {
            // Loop until its unique
            while(curr && curr.next && curr.val === curr.next.val) {
                curr = curr.next;
            }
            // it will stop at the last duplicated node so we have to set to the next node
            curr = curr.next;
			
			// In case the duplicated node is in the beginning
            if(prev == null) {
                head = curr;
            } else { // else set prev to current
                prev.next = curr;    
            }
        } else { 
			// set prev as the current node and move to the next node
            prev = curr;
            curr = curr.next;    
        }
    }
    return head;
};
```
