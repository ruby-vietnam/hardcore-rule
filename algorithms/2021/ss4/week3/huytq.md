# N-ary Tree Postorder Traversal

``` typescript
/**
 * Definition for node.
 * class Node {
 *     val: number
 *     children: Node[]
 *     constructor(val?: number) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.children = []
 *     }
 * }
 */

function postorder(root: Node | null): number[] {
    let result = []
    let dfs = (current) => {
        if(!current) return
        for(let child of current.children) {
            dfs(child)
        }
        result.push(current.val)
    }
    dfs(root)
    return result
};
```

#  N-ary Tree Preorder Traversal

``` typescript
/**
 * Definition for node.
 * class Node {
 *     val: number
 *     children: Node[]
 *     constructor(val?: number) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.children = []
 *     }
 * }
 */

function preorder(root: Node | null): number[] {
    let result = []
    let dfs = (current) => {
        if(!current) return
        result.push(current.val)
        for(let child of current.children) {
            dfs(child)
        }
    }
    dfs(root)
    return result
};
```

# Binary Tree Level Order Traversal

``` typescript
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function levelOrder(root: TreeNode | null): number[][] {
    if(!root) return []
    let result = []
    let queue: any = [[root, 0]]
    while(queue.length) {
        let [node, level] = queue.shift()
        if(result.length < level + 1) {
            result.push([])
        }
        result[level].push(node.val)
        if(node.left) queue.push([node.left, level + 1])
        if(node.right) queue.push([node.right, level + 1])
    }
    return result
};
```

# Find Duplicate Subtrees

## Summary
- Save the tree as postorder or preorder. Dont save as inorder

``` typescript
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function findDuplicateSubtrees(root: TreeNode | null): Array<TreeNode | null> {
    let seen = new Map()
    let result = []
    let dfs = (current) => {
        if(!current) return ""
        let left = dfs(current.left)
        let right = dfs(current.right)
        
        let tree = `${current.val}#${left}#${right}`
        if(seen.has(tree) && seen.get(tree) === false) {
            seen.set(tree, true)
            result.push(current)
        }
        if(!seen.has(tree)) {
            seen.set(tree, false)
        }
        return tree
    }
    dfs(root)
    return result
    
};
```



