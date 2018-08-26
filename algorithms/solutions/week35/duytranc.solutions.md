# Problem 1
#### [K-based Numbers](http://acm.timus.ru/problem.aspx?space=1&num=1009)
```cs
public class Solution
{
	private static void Main()
	{

		long n = long.Parse(Console.ReadLine().Trim());
		long k = long.Parse(Console.ReadLine().Trim());
		var r = Solve(n, k);
		Console.WriteLine(r);
	}
	
	private static long Solve(long n, long k)
	{
		return DFS(n, k , 1, true);
	}
	
	private static long DFS(long n, long k, long res, bool zero)
	{
		if(n == 0)
			return res;
			
		if(zero)
		{
			return DFS(n - 1, k , res * (k - 1), false);
		}
		else
		{
			return DFS(n - 1, k , res * (k - 1), false) + DFS(n - 1, k , res, true);
		}
	}
}
```

# Problem 1 harder version
#### [K-based Numbers. Version 2](http://acm.timus.ru/problem.aspx?space=1&num=1012)
```cs
public class Solution
{
	private static BigInteger[,] caches = new BigInteger[2000, 2];
	private static void Main()
	{

		int n = int.Parse(Console.ReadLine().Trim());
		BigInteger k = BigInteger.Parse(Console.ReadLine().Trim());
		BigInteger r = Solve(n, k);
		Console.WriteLine(r.ToString());
	}
	
	private static BigInteger Solve(int n, BigInteger k)
	{
		return DFS(n, k , BigInteger.One , true);
	}
	
	private static BigInteger DFS(int n, BigInteger k, BigInteger val, bool zero)
	{
		if(n == 0)
			return val;
		
		BigInteger subVal;
		var index = zero ? 0 : 1;
		if(caches[n, index] != 0)
		{
			subVal = caches[n, index];
		}
		else
		{
			if(zero)
			{
				subVal =  DFS(n - 1, k , (k - 1), false);
			}
			else
			{
				subVal = BigInteger.Add(DFS(n - 1, k , (k - 1), false) , DFS(n - 1, k , 1, true));
			}
			caches[n, index] = subVal;
		}
		
		return BigInteger.Multiply(val , subVal);
	}
}
```





