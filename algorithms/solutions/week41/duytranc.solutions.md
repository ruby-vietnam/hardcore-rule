# Problem 2
#### [Palindromic Substrings](https://leetcode.com/problems/palindromic-substrings/description/)
```cs
public class Solution {
    public int CountSubstrings(string s) {
        int result = 0;
        var nMid = s.Length * 2 - 1;
        for (var mid = 0; mid < nMid; ++mid)
        {
            var left = mid / 2;
            var right = left + mid % 2;

            while (left >= 0 && right < s.Length && s[left] == s[right])
            {
                result++;
                left--;
                right++;
            }
        }

        return result;
    }
}
```