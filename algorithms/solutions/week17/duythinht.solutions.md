### Problem 1

https://leetcode.com/problems/isomorphic-strings/description/

```C
bool isIsomorphic(char* s, char* t) {
    char ch_map_s[256] = {0};
    char ch_map_t[256] = {0};
    int index = 0;
    while (s[index] != '\0') {
        if (ch_map_s[s[index]] == 0 && ch_map_t[t[index]] == 0) {
            ch_map_s[s[index]] = t[index];
            ch_map_t[t[index]] = s[index];
        } else {
            if (ch_map_s[s[index]] != t[index] || ch_map_t[t[index]] != s[index]) {
                return false;
            }
        }
        ++index;
    }
    return true;
}
```

### Problem 2

https://leetcode.com/problems/rotate-list/description/

```C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {  
    struct ListNode **indirect = &head;
    int length = 0;
    while (*indirect != NULL) {
        indirect = &(*indirect)->next;
        ++length;
    }
    *indirect = head;
    
    int moveleft = length?length - k % length: 0;
    
    while (moveleft--) {
        indirect = &(*indirect)->next;
    }
    
    head = (*indirect);
    (*indirect) = NULL;
    return head;
}
```
