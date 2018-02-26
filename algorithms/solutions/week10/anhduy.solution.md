# 680. Valid Palindrome II

```c
bool isPalindrome(char* s, int l, int r) {
	while (l < r) {
		if (s[l] != s[r])
			return false;
		l++;
		r--;
	}
	return true;
}

bool validPalindrome(char* s) {
	int l = 0;
    	int r = strlen(s) - 1;	
	while (l < r) {
		if (s[l] != s[r]) {
			return (isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1));
		}
		l++;
		r--;
	}
	return true;
}
```
