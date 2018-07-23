# Problem 1
#### [Two Substrings](http://codeforces.com/contest/550/problem/A)
```cs
public void Solve(int testNumber, InputReader reader, StreamWriter writer)
{
	var s = reader.Next();

	writer.WriteLine(SolveTwoSubstrings(s) ? "YES" : "NO");
}

private bool SolveTwoSubstrings(string s)
{
	var ab = "AB";
	var ba = "BA";

	var firstIndexOfAB = s.IndexOf(ab);
	if (firstIndexOfAB >= 0)
	{
		if (firstIndexOfAB + 2 < s.Length)
		{
			var indexOfBA = s.IndexOf(ba, firstIndexOfAB + 2);
			if (indexOfBA >= 0)
			{
				return true;
			}
		}
	}

	var firstIndexOfBA = s.IndexOf(ba);
	if (firstIndexOfBA >= 0)
	{
		if (firstIndexOfBA + 2 < s.Length)
		{
			var indexOfAB = s.IndexOf(ab, firstIndexOfBA + 2);
			if (indexOfAB >= 0)
			{
				return true;
			}
		}
	}
	return false;
}
```


