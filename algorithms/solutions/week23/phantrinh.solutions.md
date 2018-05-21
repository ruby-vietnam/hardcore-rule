### Prolem 1 - [Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/description/)

Status:
```
  ✔ Accepted
  ✔ 42/42 test cases passed (36 ms)
```

```cpp
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
        int n = 0;
        ListNode *p = headA;
        while (p) {
            ++n;
            p = p->next;
        }
        int m = 0;
        p = headB;
        while (p) {
            ++m;
            p = p->next;
        }
        if (n < m) {
            swap(m, n);
            swap(headA, headB);
        }
        n -= m;
        while (n--) {
            headA = headA->next;
        }
        while (headA != headB && headA) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};
```

### Prolem 2 - [Simplify Path](https://leetcode.com/problems/simplify-path/description/)

Status:
```
  ✔ Accepted
  ✔ 252/252 test cases passed (7 ms)
```

```cpp
class Solution {
public:
    string simplifyPath(string path) {
        path += "/";
        vector<string> st;
        int x = -1, y = -1;
        for (int i = 0; i < path.size(); ++i) {
            if (path[i] == '/') {
                x = y;
                y = i;
                if (x != -1) {
                    if (y == x + 1) continue;
                    string cur = path.substr(x + 1, y - x - 1);
                    if (cur == ".") continue;
                    if (cur == "..") {
                        if (!st.empty()) st.pop_back();
                        else continue;
                    }
                    else st.push_back(cur);
                }
            }
        }
        string ret = "";
        for (int i = 0; i < st.size(); ++i) {
            ret += "/" + st[i];
        }
        if (ret.empty()) return "/";
        return ret;
    }
};
```

### Problem 4 - [Max Points on a Line](https://leetcode.com/problems/max-points-on-a-line/description/)

Status:
```
  ✔ Accepted
  ✔ 36/36 test cases passed (16 ms)
```

Code:
```cpp
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
private:
    bool isColinear(Point a, Point b, Point c) {
        return 1LL * (a.x - b.x) * (a.y - c.y) == 1LL * (a.y - b.y) * (a.x - c.x);
    }    
public:
    int maxPoints(vector<Point>& points) {
        int ret = min(2, (int) points.size());
        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                int t = 2;
                
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    for (int k = j + 1; k < points.size(); ++k) {
                        if (points[i].x == points[k].x && points[i].y == points[k].y) ++t;
                    }
                    ret = max(ret, t);
                    continue;
                }
                
                for (int k = 0; k < points.size(); ++k) {
                    if (k == i || k == j) continue;
                    if (isColinear(points[i], points[j], points[k])) {
                        ++t;
                    }
                }
                ret = max(ret, t);
            }
        }
        return ret;
    }
};
```