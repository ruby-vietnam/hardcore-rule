# Bai 1: https://leetcode.com/problems/valid-anagram/description/
You are here! 
Your runtime beats 99.39 % of cpp submissions
```
class Solution {
public:
    bool isAnagram(string s, string t) {
        // simple way
        /*int check[26] = {0};
        if(s.length() != t.length()) return false;
        
        for(int i = 0; i < s.length(); i++)
        {
            check[s[i]-'a']++;
            check[t[i]-'a']--;
        }
        
        for(int i = 0;i< 26; i++)
        {
            if(check[i] != 0)
                return false;
        }
        return true;*/
        
        // trick method
        int s1 = 0, s2 = 0, s3 = 0;
        if(s.length() != t.length()) return false;
        
        for(int i =0;i < s.length(); i++)
        {
            s1 += s[i] - t[i];
            s2 += s[i] * s[i] - t[i] * t[i];
            s3 += s[i] * s[i]* s[i] - t[i] * t[i]* t[i];
        }
        if(!s1 && !s2 && !s3) return true;
        return false;
    }
};
```

# Bai 2 : https://leetcode.com/problems/encode-and-decode-tinyurl/description/
```
class Solution {
public:

    // Encodes to a string with length is 6. Include number, lower case char and upper case char.
    unordered_map<long long, string> db ;
   
    
    string encode(string longUrl) {
        // Calculate a number reperset for URL
         char char_map[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        srand (time(NULL));
        long long y = 0;
        
       
           do
        {
            y = rand() % 1000000;
        } while (db.find(y) != db.end());
        db[y] = longUrl;       
        
        // Short the number to character
        string shortUrl = "";
        while(y)
        {
            shortUrl.push_back(char_map[y%62]);
            y /= 62;
        }
        std::reverse(shortUrl.begin(), shortUrl.end());
        return shortUrl;
        
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        long long id = 0;
 
        for (int i=0; i < shortUrl.length(); i++)
        {
            if ('a' <= shortUrl[i] && shortUrl[i] <= 'z')
              id = id*62 + shortUrl[i] - 'a';
            if ('A' <= shortUrl[i] && shortUrl[i] <= 'Z')
              id = id*62 + shortUrl[i] - 'A' + 26;
            if ('0' <= shortUrl[i] && shortUrl[i] <= '9')
              id = id*62 + shortUrl[i] - '0' + 52;
        }
        return db[id];
        
    }
};

```

# Bai 3: https://leetcode.com/problems/merge-k-sorted-lists/description/
beat 92%

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

    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        ListNode dummy = ListNode(0);
        ListNode *h1 = &dummy;

        auto cmp = [](pair<int,int> left, pair<int,int> right) { return left.first > right.first;};
        std::priority_queue<pair<int, int>, std::vector<pair<int,int>>, decltype(cmp)> q(cmp);
               
        for(int i = 0; i < k; i++)
        {
            if(lists[i] != nullptr)
            {
                pair<int,int> P {lists[i]->val, i};
                q.push(P);
                lists[i] = lists[i]->next;
            }
        }
        
        // Get top
        while ( !q.empty())
        {
            ListNode *temp = new ListNode(q.top().first);
            h1->next = temp;
            h1 = temp;
            int id = q.top().second;
            q.pop();               
            if(lists[id] != nullptr)
            {
                int temp = lists[id]->val;
                pair<int, int> P {temp, id};
                q.push(P);
                lists[id] = lists[id]->next;
            }   
        }

        return dummy.next;
    }
};
```
