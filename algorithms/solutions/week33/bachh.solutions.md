# Problem 1
```cpp
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int len  = 0;
        ListNode* temp = head;
        while(temp != NULL){
            temp = temp->next;
            len++;
        }
        len /= 2;
        while(len--){
            head = head->next;
        }
        return head;
    }
};
```

# Problem 2
```cpp
int SJF(std::vector <int> jobs, int index){
    int len = 0;
    for( int i  =0 ; i < jobs.size(); ++i){
        if (jobs[i] < jobs[index]){
            len += jobs[i];
        }
        else if (jobs[i] == jobs[index] && i <= index){
            len += jobs[i];
        }
    }
    return len;
}
```

# Problem 4

This is a bit of a hack, but essentially we need a datastructure that
has the Set property and also lookup min value better than O(N)

We can implement a full tree here, but I guess C++'s std::set is a tree
underneath

``` cpp
#include <set>
using namespace std;
class DoubleLinear
{
public:
    static int dblLinear(int n){
        set<int, less<int>> st;
        int s = 1; st.insert(s);
        while(n--){
            s = *st.begin();
            if (st.count(2*s + 1) == 0 ){
                st.insert(2*s + 1);
            }
            if (st.count(3*s + 1) == 0 ){
                st.insert(3*s+1);
            }
            st.erase(st.begin());
        }
        return *st.begin();
    }
};
```
