## Problem 1

```javascript
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
const middleNode = (head) => {
  let size = 0;
  let node = head;
  const arr = [];
  while (node) {
    arr.push(node);
    size++;
    node = node.next;
  }
  return arr[Math.floor(size/2)];
};
```

## Problem 2

```javascript
function SJF(jobs, index) {
  const job = jobs[index];
  let cc = job;
  for (i = 0; i < jobs.length; i++) {
    if ((jobs[i] < job) || (jobs[i] === job && i < index)) {
      cc += jobs[i];
    }
  }

  return cc;
}
```
