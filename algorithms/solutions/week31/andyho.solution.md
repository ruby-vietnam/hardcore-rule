Problem 1 : http://codeforces.com/contest/550/problem/A

```Scala
object Solution extends App {
    
    val input = scala.io.StdIn.readLine()
    
    val enough = input.contains("AB") && input.contains("BA")
    val abFirst = input.indexOf("AB") + 1 < input.lastIndexOf("BA")
    val baFirst = input.indexOf("BA") + 1 < input.lastIndexOf("AB")
    
    if (enough && (abFirst || baFirst)) {
        println("YES")
    } else {
        println("NO")
    }
}
```

Problem 2 : https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

```Scala
object Solution {
    def maxTwo(root: TreeNode): (Int, Int) = {
        if (root == null) {
            (-2000000000, 0)
        } else {
            val (leftTotal, leftPath) = maxTwo(root.left)
            val (rightTotal, rightPath) = maxTwo(root.right)

            val total = List(leftTotal, rightTotal, Math.max(leftPath, 0) + root.value + Math.max(rightPath, 0)).max
            val bestPath = List(leftPath, rightPath, 0).max + root.value
            (total, bestPath)
        }
    }
    
    def maxPathSum(root: TreeNode): Int = {
        maxTwo(root)._1
    }
}
```

Problem 3 : http://codeforces.com/contest/580/problem/D

```C++
#include <iostream>

using namespace std;

#define MAXN 20
int n, m, k;
long long a[MAXN], C[MAXN][MAXN];
long long res[1 << MAXN][MAXN];

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < k; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        x--; y--;
        C[x][y] = c;
    }

    long long result = 0;

    for (int i = 1; i <= (1 << n); i++) {
        int cnt = __builtin_popcount(i);
        if (cnt > m) continue;
        for (int j = 0; j < n; j++) {
            if (!(i & (1 << j))) continue;
            long long maxV = a[j];
            int remain = i & ~(1 << j);
            for (int k = 0; k < n; k++) {
                if (!(remain & (1 << k))) continue;
                maxV = max(maxV, res[remain][k] + a[j] + C[k][j]);
            }
            res[i][j] = maxV;
            result = max(result, maxV);
        }

    }

    cout << result << endl;

    return 0;
}
```

Problem 4 : https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/

```C++
class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
       deque<pair<long long, int>> q;
       int res = A.size() + 1;
       q.push_back(pair<long long, int>(0, -1));
       long long sum = 0;
       for (int i = 0; i < A.size(); i++) {
           sum += A[i];
           while (!q.empty() && q.back().first > sum) q.pop_back();
           while(!q.empty() && sum - q.front().first >= K) {
               res = min(res, i - q.front().second);
               q.pop_front();
           }
           q.push_back(pair<long long, int>(sum, i));
       }
       return (res == A.size() + 1) ? -1 : res; 
    }
};
```
