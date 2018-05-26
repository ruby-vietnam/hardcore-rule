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
https://leetcode.com/problems/new-21-game/description/
Solution by lee215
Explanation:
In a word,
dp[i]: probability of get points i
dp[i] = sum(last W dp values) / W

```
class Solution {
public:
   double new21Game(int N, int K, int W) {
        if (K == 0 || N >= K + W) return 1;
        vector<double> dp(N + 1);
        dp[0] = 1.0;
        double Wsum = 1.0, res = 0.0;
        for (int i = 1; i <= N; ++i) {
            dp[i] = Wsum / W;
            if (i < K) Wsum += dp[i]; else res += dp[i];
            if (i - W >= 0) Wsum -= dp[i - W];
        }
        return res;
    }
};
```

# Bai 4:
https://leetcode.com/problems/max-points-on-a-line/description/
```
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
public:
    struct less_than_y
    {
        inline bool operator() (const Point& p1, const Point& p2)
        {
            if( p1.x == p2.x)
            return (p1.y < p2.y);
            return p1.x < p2.x;
        }
    };
    
    int maxPoints(vector<Point>& points) {
        if(points.size() <= 0) return 0;
        int n = points.size();
        if(n <= 2) return n;
        std::sort(points.begin(), points.end(), less_than_y());
        
    int same, ver, hor, tmp, tmp1, tmp2, max;
    
    for(int i = 0; i < n; i++)
    {
        same = 1; ver = 0; hor = 0;
        std::map<int, std::map<int,int>> m;
        for(int j = i +1; j < n; j++) 
        {
            if(points[i].x == points[j].x && points[i].y == points[j].y)
            {
                same++;
            } else if(points[i].x == points[j].x) 
            {
                ver++;
            } else if (points[i].y == points[j].y)
            {
                hor++;
            } else {
                tmp = __gcd(abs(points[j].x - points[i].x), abs(points[i].y - points[j].y));
                tmp1 = (points[j].y - points[i].y) /tmp;
                tmp2 = (points[j].x - points[i].x) /tmp;
                
                if(m.find(tmp1) == m.end())
                {
                    std::map<int,int> mp;
                    mp[tmp2] = 1;
                    m[tmp1] = mp;
                } else {
                    auto mp = m[tmp1];
                    mp[tmp2]++;
                    m[tmp1] = mp;
                }

            }
        }
        
        if (max < same + hor) {
            max = same + hor;
        }
        
        if (max < same + ver) {
            max = same + ver;
        }
        

        for(auto x : m)
        {
            for (auto y : x.second)
            {
                if (max < same + y.second)
                {
                    max = same + y.second;
                }
            }
        }
        
    }
  
    
    return max;
    }


    
};

```

