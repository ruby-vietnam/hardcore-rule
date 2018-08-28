# Problem 1:
https://leetcode.com/problems/climbing-stairs/description/

We can use dynamic programming:
To clim to n, we have 2 way:
    - clim to n-1 and take 1 step: have result(n-1) ways
    - clim to n -2 and take 2 steps: have result(n-2) ways

-> result(n) = result(n-1) + result(n-2)

```java
class Solution {
    public int climbStairs(int n) {
        if (n <= 2) {
	    	return n;
    	}

        int r1 = 1, r2 = 2;
        for (int i = 2; i < n; i++) {
            int temp = r2;
            r2 = r1 + r2;
            r1 = temp;
        }

        return r2;
    }
}
```


# Problem 2: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
Dynamic programing again
```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s.length() == 0) {
            return 0;
        }
        char[] chars = s.toCharArray();
        int result = 1;
        int[] dp = new int[chars.length];
        
        dp[0] = 1;
        for (int i = 1; i < chars.length; i++) {
            int d = 1;

            for (int j = 0; j < dp[i-1]; j ++) {
                if (chars[i] != chars[i - j - 1]) {
                    d++;
                } else {
                    break;
                }
            }

            dp[i] = d;
            if (result < d) {
                result = d;
            }
        }

        return result;
    }
}
```

# Problem 3:

Using DFS with a recStack to keep track current path.

```java
class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        List<Integer>[] graph = new List[numCourses];
        for (int i=0; i < numCourses; i++) {
            graph[i] = new ArrayList<Integer>();
        }

        for (int i = 0; i < prerequisites.length; i++) {
            graph[prerequisites[i][0]].add(prerequisites[i][1]);
        }

        boolean[] visited = new boolean[numCourses];
        boolean[] recStack = new boolean[numCourses];

        for (int i=0; i<numCourses; i++) {
            if (!visit(i, graph, visited, recStack)) {
                return false;
            }
        }

        return true;
    }

    public boolean visit(int courseNum, List<Integer>[] graph, boolean[] visited, boolean[] recStack) {
        if (recStack[courseNum]) {
            return false;
        }

        if (visited[courseNum]) {
            return true;
        }

        visited[courseNum] = true;
        recStack[courseNum] = true;
        for (int p : graph[courseNum]) {
            if (!visit(p, graph, visited, recStack)) {
                return false;
            }
        }
        recStack[courseNum] = false;

        return true;
    }
}
```
