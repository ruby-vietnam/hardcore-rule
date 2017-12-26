Tách folder con sau vậy :rofl:


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

int number_needed(string s, string b) {
    int a[26] = {0};
    int l = 0;
    for(auto c: s)
    {
        a[c-'a'] ++;
    }
    for(auto c: b)
    {
        if(a[c-'a'] > 0)
        {
            l++;
            a[c-'a']--;
        }
    }
    return s.length() + b.length() - l*2;
}
