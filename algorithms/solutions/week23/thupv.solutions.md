
Link: https://leetcode.com/problems/intersection-of-two-linked-lists

 * 42 / 42 test cases passed.
 * Status: Accepted
 * Runtime: 88 ms
 * Your runtime beats 97.70 % of javascript submissions.


```javascript
var getIntersectionNode = function(headA, headB) {
  var diff = 0
  var nodeA = headA, nodeB = headB;
  while(nodeA){
    diff++
    nodeA = nodeA.next
  }

  while(nodeB){
    diff--
    nodeB = nodeB.next
  }
  nodeA = headA
  nodeB = headB

  if(diff < 0) {
    diff = diff * (-1)
    nodeA = headB;
    nodeB = headA;
  }

  for(var i=0; i< diff; i++){
    nodeA = nodeA.next
  }

  while(nodeA){
    if(nodeA.val === nodeB.val){
      return nodeA
    }
    nodeA = nodeA.next
    nodeB = nodeB.next
  }
  return null;

};
```

Link: https://leetcode.com/problems/simplify-path/description/

 * 252 / 252 test cases passed.
 * Status: Accepted
 * Runtime: 64 ms
 * Your runtime beats 98.55 % of javascript submissions.


```javascript
function Stack(){
  this.data = [];
  this.push = function(str){
    this.data.push(str);
  }
  this.pop = function(){
    this.data = this.data.slice(0, this.data.length-1);
  }
}
var simplifyPath = function(path) {
  var stack = new Stack();
  var folders = path.split('/');
  var i;
  for(i=0; i<folders.length; i++){
    if(folders[i] === '..'){
      stack.pop();
    } else {
      if(folders[i] !== '' && folders[i] !== '.'){
        stack.push(folders[i]);
      }
    }
  }
  var str = '/';
  for(i=0; i<stack.data.length; i++){
    str = str + stack.data[i] + '/';
  }

  return str.length > 1 ? str.slice(0, -1): str;
};
```