# Problem 1

Here we need to check there are non-overlapping occurences of

the string "BA" and "AB"

```cpp
#include <bits/stdc++.h>

using namespace std;

//  ***** MAIN *****
int main(){
    string s; cin >> s;

    int ab_first = -1 , ba_first = -1;
    int ab_last = -1, ba_last = -1;

    for(int i =0; i < s.length() -1; i++){
        if(s[i] == 'A' && s[i+1] == 'B'){
            if(ab_first == -1 ) ab_first = i;
            ab_last = i;
        }
        else if (s[i] == 'B' && s[i+1] == 'A'){
            if (ba_first == -1) ba_first = i;
            ba_last = i;
        }
    }

    if (ba_first ==-1 || ab_first == -1){}
    else if(ba_last - ab_first > 1 || ab_last - ba_first > 1){
      cout << "YES" << endl;
      return 0;
    }
    cout << "NO" << endl;
    return 0;
}
```

# Problem 2

Here we take notice that tree datastructure are recursive. The longest path
can either reside entirely on the left subtree, the right subtree, or it can be
a path that cross over the root node


```cpp
int glob_max_path = INT_MIN;
int maxPathSum(TreeNode *root){
    recurse(root);
    return glob_max_path;
}

int recurse(TreeNode *root){
    if (root == NULL) return 0;
    int l_path = max(0, recurse(root->left));
    int r_path = max(0, recurse(root->right));
    glob_max_path = max(glob_max_path, l_path + root->val + r_path);
    return max(l_path, r_path);
}
```

# Problem 3

Here we conduct a complete search with DP. Which means iterating through
all order of dishes served. But we only need to keep track of dishes he
already ate, and also the last dish he ate, since this will interfere
with the bonus of our next dish

Since the number of dishes is small, an bitmask integer will
be used to keep track of which dishes Kefa ate.

At the start each iteration, we update Kefa satisfaction level accordingly:

dp[mask][Y] = dp[mask][X] + value[Y] + bonus[X][Y]

The output will be the maximum value in the table.

Solution: (recursive dp)

```cpp
#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100

int n, m, k;

int64_t a[20];
int64_t dp[1<<19][20];
int64_t bonus[20][20];

int64_t solve(int bitmask, int prev, int total){

  if (total >= m) return 0;

  if(dp[bitmask][prev] != -1) return dp[bitmask][prev];

  int64_t mx = -1;
  for (int i = 1; i <= n; i++) {
    if( !(bitmask&(1<<i)) ){
      mx = max<int64_t>(mx, bonus[prev][i] + a[i] + solve((bitmask|(1<<i)), i, total+1));
    }
  }

  return dp[bitmask][prev] = mx;

}

//  ***** MAIN *****
int main(){

  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m >> k;

  memset(dp, -1, sizeof(dp[0][0])*(1<<18)*20);
  memset(bonus, 0, sizeof(bonus[0][0])*20*20);

  a[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int x, y;

  for (int i = 0; i < k; i++) {
    cin >> x >> y;
    cin >> bonus[x][y];
  }

  std::cout << solve(0, 0, 0) << std::endl;

  return 0;
}
```

# Problem 4

## Check linxGNU's solution for usage of Fenwick Tree

## Author's solution:
https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/solution/

Calculating an array prefix[n], for each i, prefix[i] = sum(a[0], a[1].. a[i-1])

With this, calculating sum of range from indices x->y became a constant time procedure:
sum(a[x]...a[y])) = prefix[y] - prefix[x] |  (x > 0)


Now the main idea here is to find a maximum index X for every index Y such as
prefix[Y] - prefix[X] >= K, we call this X opt(Y)

The solution is to construct a double-ended queue of indices as a sliding windows
when calculating valid pairs of x, y such that prefix[y] - prefix[x] >= k

The author notes 2 key observations:

* For 2 indices x_1, x_2 if prefix[x_1] <= prefix[x_2] AND x_1 < x_2
Then when choosing opt(y) between x_1, and x_2. It is always better
to choose x_2, since if prefix[y] - prefix[x_1] >= K
if follows prefix[y] - prefix[x_2] >= prefix[y] - prefix[x_1] >= K
but x_2 > x_1 hence the length of our array will be shorter

This means when adding index x_1, x_2... etc to the end of the queue,
we expect their prefix value to also be increasing in value

* If x is already the opt(y_1) value of some index y_1,
then x cannot be the optimum value for some index y_2 larger than y_1

This means that when adding new index to the end of the queue, we only needs
to check the new index' validity (sum of range >= K ) against the index
at the front of the queue. If satisfies, immediately pop front.


```cpp
class Solution {
    public int shortestSubarray(int[] A, int K) {
        int N = A.length;
        long[] P = new long[N+1];
        for (int i = 0; i < N; ++i)
            P[i+1] = P[i] + (long) A[i];

        // Want smallest y-x with P[y] - P[x] >= K
        int ans = N+1; // N+1 is impossible
        Deque<Integer> monoq = new LinkedList(); //opt(y) candidates, as indices of P

        for (int y = 0; y < P.length; ++y) {
            // Want opt(y) = largest x with P[x] <= P[y] - K;
            while (!monoq.isEmpty() && P[y] <= P[monoq.getLast()])
                monoq.removeLast();
            while (!monoq.isEmpty() && P[y] >= P[monoq.getFirst()] + K)
                ans = Math.min(ans, y - monoq.removeFirst());

            monoq.addLast(y);
        }

        return ans < N+1 ? ans : -1;
    }
}
```

