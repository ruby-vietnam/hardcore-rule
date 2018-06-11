/*
 * Problem: https://leetcode.com/problems/find-the-difference/description/
 */
#include <stdlib.h>

#define ALPHABET_SIZE 26

char findTheDifference(char* s, char* t) {
    int *char_count = (int*)calloc(ALPHABET_SIZE+'a', sizeof(int));
    while (*s) {
        char_count[*s++]--;
        char_count[*t++]++;
    }
    char_count[*t]++;
    for (char i='a'; i < ALPHABET_SIZE+'a'; i++) {
        if (char_count[i]) return i;
    }
    return 0;
}
