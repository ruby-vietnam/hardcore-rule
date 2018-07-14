# Problem 2
#### [Sparse Arrays](https://www.hackerrank.com/challenges/sparse-arrays/problem)
```cs
static int[] matchingStrings(string[] strings, string[] queries) 
{
	var map = new Dictionary<string, int>();
	foreach(var str in strings)
	{
		if(map.ContainsKey(str))
		{
			map[str]++;
		}
		else
		{
			map.Add(str, 1);
		}
	}
	return queries.Select(query => map.ContainsKey(query) ? map[query] : 0).ToArray();
}
```


