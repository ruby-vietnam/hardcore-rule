# Easy: Toeplitz Matrix

The goal is to check if every diagonal values from top-left to bottom-right is equals.
Instead of run through each diagonal lines, we can just check if each element in the matrix equals to its upper left element.

Submission Details

```
483 / 483 test cases passed.
Status: Accepted
Runtime: 80 ms
Memory Usage: 40.4 MB
```

Implementation:

```javascript
/**
 * @param {number[][]} matrix
 * @return {boolean}
 */
var isToeplitzMatrix = function(matrix) {
    const rows = matrix.length;
    const cols = matrix[0].length;
    for (let r = 0; r < rows; r++) {
        for (let c = 0; c < cols; c++) {
            if (r - 1 >= 0 && c - 1 >= 0) {
                if (matrix[r][c] !== matrix[r-1][c-1]) return false;
            }
        }
    }
    return true;
};
```

# Medium: Group Anagrams

There are two things need to be done in this problem:
1) Have a way to determine if a string is an anagram of some other string
2) Group the anagrams in to the same group

If we take two strings that is an anagram of each other, and sort them somehow, we will end up with the same string, for example:

```
s1 = "bat" => sorted_s1 = "a,b,t"
s2 = "tab" => sorted_s2 = "a,b,t"
```

If we use a hashtable to group the anagrams, we can use this sorted string as a key.

So the idea is:
1. Create a hash table for grouping the anagrams
2. For each string in the input array:
	3. Compute the key (or hash code) from the current string, it can be done by sort all the characters in the string.
	4. Insert the current string to the hash table with the computed key
5. Eventually, return the groups found in the hashtable.

Submission Details:

```
114 / 114 test cases passed.
Status: Accepted
Runtime: 164 ms
Memory Usage: 51.1 MB
```

Implementation:

```javascript
const encode = s => s.split('').sort();

/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
    const group = {};
    const ret = [];
    for (let i = 0; i < strs.length; i++) {
        const key = encode(strs[i]);
        if (!group[key]) group[key] = [];
        group[key].push(strs[i]);
    }
    for (let key in group) {
        ret.push(group[key]);
    }
    return ret;
};
```

# Medium: Partition List

Use two linked list, one to store the nodes that smaller than `x`, and another list to store the nodes that equal or larger than `x`.

Iterate through the list and add each of the node to the proper list, eventually, merge the two lists, so that the head of the `right` list will be connected to the tail of the `left` list.

The `left` list become the result.

Since we're not allocate any new data, but actually moving the nodes around from the original linked list, the space complexity is `O(1)`. Time complexity is `O(n)`.

Submission Details:

```
168 / 168 test cases passed.
Status: Accepted
Runtime: 72 ms
Memory Usage: 40.3 MB
```

Implementation:

```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} x
 * @return {ListNode}
 */
var partition = function(head, x) {
    let left = new ListNode();
    let head_left = left;
    let right = new ListNode();
    let head_right = right;
    while (head !== null) {
        if (head.val < x) {
            head_left.next = new ListNode(head.val);
            head_left = head_left.next;
        } else {
            head_right.next = new ListNode(head.val);
            head_right = head_right.next;
        }
        head = head.next;
    }
    head_left.next = right.next;
    return left.next;
};
```
