## Problem 1

```js
// Use more memory

var hasCycle = function(head) {
    var result = new WeakMap;
    var iterator = head;

    if (iterator == null) {
        return false;
    }

    while (iterator != null && result.get(iterator) == undefined) {
        result.set(iterator, 1);
        iterator = iterator.next;
    }

    return iterator != null;
};

// Use less memory

var hasCycle = function(head) {
    var fast = head;
    var slow = head;

    while (fast != null && slow != null) {
        if (fast.next == null) {
            return false;
        } else if (fast.next == slow) {
            return true;
        }
        fast = fast.next.next
        slow = slow.next

        if (fast == slow) {
            return true;
        }
    }

    return false;
};
```
