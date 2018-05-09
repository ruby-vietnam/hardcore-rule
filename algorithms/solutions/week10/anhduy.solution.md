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

# 114. Flatten Binary Tree to Linked List

```c
void flatten(struct TreeNode* root) {
    if (root) {
      struct TreeNode* left = root->left;
      struct TreeNode* right = root->right;

      root->left = NULL;

      flatten(left);
      flatten(right);

      root->right = left;
      struct TreeNode* node = root;
      while (node->right) {
        node = node->right;
      }
      node->right = right;
    }
}
```
