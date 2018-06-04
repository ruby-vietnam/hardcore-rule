### Prolem 1 - [Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/description/)

Status:
```
  ✔ Accepted
```

```javascript
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
    var pA = headA, pB = headB, switchA = false, switchB = false;
    for (;;) {
        if (pA == pB)
            return pA;
        if (pA == null || pB == null)
            return null;
        pA = pA.next;
        pB = pB.next;
        if (pA == null && !switchA) {
            pA = headB;
            switchA = true;
        }
        if (pB == null && !switchB) {
            pB = headA;
            switchB = false;
        }
    }

};

```

### Prolem 2 - [Simplify Path](https://leetcode.com/problems/simplify-path/description/)
Status:
```
  ✔ 252 / 252 test cases passed.
  ✔ Status: Accepted
  ✔ Runtime: 44 ms
```

```ruby
# @param {String} path
# @return {String}
def simplify_path(path)
  paths = []
  path.split('/').each do |directive|
    navigate(paths, directive)
  end
  '/' + paths.join('/')
end

def navigate(paths, directive)
  case directive
  when '.', ''
    # do nothing
  when '..'
    paths.pop
  else
    paths.push(directive)
  end
end
```