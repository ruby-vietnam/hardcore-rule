Tách folder con sau vậy :rofl:

Bài 1: https://www.hackerrank.com/challenges/ctci-making-anagrams/problem

Cách giải là tìm phần chung lớn nhất giữa 2 string, rồi cộng tổng độ dài 2 string lại rồi trừ đi phần chung là xong.
cách tìm thì có thể dùng array hoặc hashtable

    // Cách 1: Dùng hashtable
    int number_needed2(string a, string b) {
        int l = 0;
        unordered_map <char, int> table;

        for(auto c: a)
        {
            if(table.find(c) == table.end())
            { // not found
                table[c] = 1;
            } else 
            { // found
                table[c] = table[c] + 1;
            }
        }

        for(auto c: b)
        {
            if(table.find(c) != table.end() && table[c] > 0)
            {
                    l++;
                    table[c] = table[c] -1;
            }
        }

        return a.length() + b.length() - l*2;
    }

    // Cách 2 dùng array
    int number_needed(string a, string b) {
        int s[26] = {0};
        int l = 0;
        for(auto c: a)
        {
            s[c-'a'] ++;
        }
        for(auto c: b)
        {
            if(s[c-'a'] > 0)
            {
                l++;
                s[c-'a']--;
            }
        }
        return a.length() + b.length() - l*2;
    }
