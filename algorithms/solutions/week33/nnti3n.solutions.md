# Problem 1

```javascript
/** 
 * @param {ListNode} head
 * @return {ListNode}
 */
var middleNode = function(head) {
  let node = head;
  let length = 1;
  while (node.next) {
    node = node.next;
    length++;
  }
  if (length > 0 ) {
    length = parseInt(length/2);
    console.log("length", length);
    node = head;
    for (let i = 0; i < length; i++) {
      node = node.next;
    }
    return node;
  }
  return head
};
```

# Problem 2

```javascript
function SJF(jobs, index){
  //Implment Shortest Job First
  var temp_jobs = jobs.map((item, index) => {
    return [index, item];
  })
  temp_jobs = temp_jobs.sort(function(a,b) { return a[1] - b[1]; });
  let cc = 0;
  temp_jobs.find(item => {
    cc += item[1];
    if (item[0] === index) {
      return cc;
    }
  });
  return cc;
}
```
