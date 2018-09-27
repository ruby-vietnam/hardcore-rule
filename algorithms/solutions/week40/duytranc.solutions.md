# Problem 3
#### [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/description/)
```cs
public string LongestPalindrome(string s) {
	string result = string.Empty;
	var max = 0;

	for (var i = 0; i < s.Length; ++i)
	{
		var left = i;
		var right = i;

		while (left > 0  && s[left - 1] == s[i])
		{
			left--;
		}
		while (right < s.Length - 1 && s[i] == s[right + 1])
		{
			right++;
		}
		while (left > 0 && right < s.Length - 1 && s[left - 1] == s[right + 1])
		{
			left--;
			right++;
		}

		if (right - left + 1 > max)
		{
			max = right - left + 1;
			result = s.Substring(left, right - left + 1);
		}
	}

	return result;
}
```