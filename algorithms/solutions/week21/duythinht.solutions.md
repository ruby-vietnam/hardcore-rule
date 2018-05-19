### Problem 1

https://leetcode.com/problems/valid-anagram/description/


```C
#define ABC_SIZE 26

int chars_count[ABC_SIZE];

bool is_anagram(char *s, char *t) {
    // Set default chars_count to zero array
    memset(chars_count, 0, ABC_SIZE * sizeof(int));
    
    while (*s && *t) {
        chars_count[*(s++)-'a']++; // Don't do this, sida đấy
        chars_count[*(t++)-'a']--;
    }
    
    // Avoid next step because of 2 str have difference length
    if (*s || *t) {
        return false;
    }

    // Check diff of chars_count
    for (int i=0; i < ABC_SIZE; i++) {
        if (chars_count[i] != 0) {
            return false;
        }
    }
    return true;
}

// This is stupid naming in C, don't want use this
bool isAnagram(char* s, char* t) {
    return is_anagram(s, t);
}
```
