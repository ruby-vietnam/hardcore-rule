# Season 4 - Week 3

### 1. N-ary Tree Postorder Traversal
- Problem: https://leetcode.com/problems/n-ary-tree-postorder-traversal/

```JS
var postorder = function(root) {
    let res = [];

    function dfsTraversal(root) {
        if (!root) return;

        for (let child of root.children) {
            dfsTraversal(child);
        }

        res.push(root.val);
    }
    dfsTraversal(root);

    return res;
};
```

### 2. N-ary Tree Preorder Traversal
- Problem: https://leetcode.com/problems/n-ary-tree-preorder-traversal/
``` JS

var preorder = function(root) {
    const res = [];
     
    const dfs = (root,res)=>{

        if(!root) return;
        res.push(root.val);

        const childs =root.children;
        for(let child of childs){
           dfs(child,res); 
        }
    }
    dfs(root,res);
    return res;
};
```

### 3. Binary Tree Level Order Traversal
- Problem:  https://leetcode.com/problems/binary-tree-level-order-traversal/
```JS
var levelOrder = function(root){
    if(!root){
        return []
    };
    let result =[];
    let parent = [root];
    let child = [];
    let data =[];
    while (parent.length > 0){
        const node = parent.shift();
        data.push(node.val);
        if(node.left) child.push(node.left);
        if(node.right) child.push(node.right);
        if(!parent.length){
            parent = [...child];
            child = [];
            result.push([...data]);
            data=[]
        }
        
    }
    return result;
}
```

### 4. 

