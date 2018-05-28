# 160

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *tempHeadA, *tempHeadB;
    tempHeadA = headA;
    tempHeadB = headB;
    
    while(tempHeadA != tempHeadB) {
        if (tempHeadA)
            tempHeadA = tempHeadA->next;
        else
            tempHeadA = headB;
        if (tempHeadB)
            tempHeadB = tempHeadB->next;
        else
            tempHeadB = headA;
    }
    
    return tempHeadA;
}
```

#71

```ruby
# @param {String} path
# @return {String}
def simplify_path(path)
    parts = path.split('/')
    result = []
    parts.each do |p|
        if p == ""
            next
        end
        if p == "."
            next
        end
        if p == ".."
            result = result[0..-2]
            next
        end
        result.push p
    end
    '/' + result.join('/')
end
```
