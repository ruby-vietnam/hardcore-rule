# bai 1 :
https://leetcode.com/problems/intersection-of-two-linked-lists

Your runtime beats 98.66 % of cpp submissions

```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p = headA;
        int sizeA = 0;
        while(p)
        {
            sizeA++;
            p = p->next;
        }
        p = headB;
        int sizeB = 0;
        while(p)
        {
            sizeB++;
            p = p->next;
        }
        
        ListNode *q = nullptr;
        if(sizeA < sizeB)
        {
            int x= sizeB - sizeA;
            p = headB;
            do{
                p = p->next;
                x--;
            }while(x>0);
            q = headA;
        }
        else if( sizeB < sizeA)
        {
            int x= sizeA - sizeB;
            p = headA;
            do{
                p = p->next;
                x--;
            }while(x>0);
            q = headB;
        }
        else {
            p = headA;
            q = headB;
        }
        
        while(p != q && p && q)
        {
            p = p->next;
            q = q->next;
        }
        if( p == nullptr || q == nullptr)
            return nullptr;
        else return p;
    }
};
```

# Bai 2:
https://leetcode.com/problems/simplify-path/

63% ... optimize later...
```
class Solution {
public:
    string simplifyPath(string paths) {
        stack<string> path;
        string temp = "";
        for(auto c: paths)
        {
            if(c == '/')
            {
                if(temp != "")
                {
                    if(temp == "..")
                    {
                        if(path.size()>0)
                            path.pop();
                    } 
                    else if( temp == ".")
                    {   
                        temp = "";
                        continue;
                    }
                    else path.push(temp);
                    temp = "";
                }
                continue;
            }
            else {
                temp += c;
            }
        }
        if(temp != "" && temp != ".")
        {
            if(temp == ".." )
            {
                if (path.size() > 0)
                path.pop();
            }
            else path.push(temp);
        }         
            
        string result = "";
        if(path.size() == 0) return "/";
        while(!path.empty()){
            result = "/" + path.top()  + result;
            path.pop();
        }
        return  result;
    }
};
```

# Bai 3: 
Working later

# Bai 4:
https://leetcode.com/problems/max-points-on-a-line/description/
```
```

