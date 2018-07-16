#### Problem 1 (easy): https://www.hackerrank.com/challenges/mini-max-sum/problem 
	
Nothing much to say about this problem, just calculate 5 sums by removing each element, then calculate max and min of those sums. One small notice is to be careful of overflow error for strong-type language

Code:

```Scala
def miniMaxSum(arr: Array[Int]) {
	val longArr = arr.map(_.toLong)
	val total = longArr.sum
	val sums = arr.map(total - _)
	println(s"${sums.min} ${sums.max}")
}
```

#### Problem 2 (easy/medium): https://www.hackerrank.com/challenges/sparse-arrays/problem

This problem is an interesting candiate for an interview question. Depends on the size of the input, different algorithm is required.

With the original input size from hacker rank, it's possible to get accepted using a trivial algorithm, for each query, just loop through all strings and count the matches. Complexity: O(n\*q\*lenStr)

Code:

```Scala
def matchingStrings(strings: Array[String], queries: Array[String]): Array[Int] = {
	queries.map(item => strings.count(_ == item))
}
```

However, the problem gets more interesting with bigger input. If n and q are increased to be 10^5, I suggest few alternatives.

1. Binary search

   Sort the original strings, (optionally squeze identical items into one and keep track of the count) and binary search to find the count. Complexity: O(max(n, q)\*log(n)\*lenStr)

2. Map

   Construct a Map[String, Int] represents number of string apperances. One small optimization of this approach is to hash the strings and construct the Map[Int, Int] to improve insert and query operation on Map. Depends on the underlying Map, this optimization may not be necessary. This optimization can be apply to first approach as well. Complexity: O(max(n, q)\*log(n)\*lenStr) or O(max(n, q)\*log(n) + max(n, q)\*lenStr) with optimization. Code.

```Scala
def matchingStrings(strings: Array[String], queries: Array[String]): Array[Int] = {
	val stringsCountMap = strings
		.groupBy(identity)
		.mapValues(_.size)

	queries.map(item => stringsCountMap.getOrElse(item, 0))
}
```


3. Trie:

   Read more here https://en.wikipedia.org/wiki/Trie. Basicaly, based on the input of strings, we construct a tree where nodes are characters, each tree path from root to a leaf corresponds to an item from strings input. Then when we want to query, we just try to traverse from root, and get the result at the leaf. This is somewhat more complicated to code, but I think the fact that you know about this data structure is a huge plus for the interviewers. 

#### Problem 3 (medium/hard): http://codeforces.com/problemset/problem/1000/E

This problem requires some knowledge about graph theory. First, we observe that the bosses need to be placed in a [bridge](https://en.wikipedia.org/wiki/Bridge_(graph_theory)). A bridge is a edge that if we remove it, the number of connected regions of graph increases. For example, in a tree, every edges is a bridge. If the bosses are placed in a non-brige edge, there is always a path from s to t that doesn't involve that bridge (because s and t are still connected after removing that edge). So firstly, we find all the bridges in the graph. Now if we remove all the briges, the graph becomes a set of connected regions, they are call strongly connected components. We can imagnine those component as a node, and the briges are edges to connect those nodes. We can view the original graph as a tree with node as strongly connected components and edges as bridges. It's easy to see that now the final resul is the longest path from one node to another node in the tree (which equates the number of brigeds in that path).

They are two famous problems in graph theory and there are plenty of implementations that you can refer to online.
1. Find the brige/strongly connected components

   Tarjan algorithm and it's variants: https://en.wikipedia.org/wiki/Tarjan%27s_strongly_connected_components_algorithm

2. Find the longest path in a tree, or tree diameter problem

   You can implement this using dp or greedy algorithm

  - DP

    Start at a node v, result at v is either result form a child of v, or sum of two longest path from a leaf to v via two children of v

  - Greedy

    Start at 1, find the farthest node in tree from 1, called v, then find the farthest node in tree from v, called u. The path from v to u is the longest path of tree. Proof lefts as exercise.

Code: This code use dp for the second problem, and some tricks to avoid constructing the tree for the second prolem.

```C++
#include <cstring>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;
#define MAXN 300005

vector<int> edges[MAXN];
int cnt[MAXN], low[MAXN], vis[MAXN];
int n, m;
int count;

void readInput() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
}

void firstTraverse(int v, int parent) {
	cnt[v] = low[v] = ++count; // update count and low as the number of visted index
	for (int i = 0; i < edges[v].size(); i++) {
		int u = edges[v][i]; // u is a vertex connected to v
		if (u == parent) continue; // ignore edge to parent
		if (cnt[u]) {
			// u is visited, update low[v]
			low[v] = min(low[v], cnt[u]);
		} else {
			// else traverse through u, and update low[v]
			firstTraverse(u, v);
			low[v] = min(low[v], low[u]);
		}
	}
}

void updateMax(int longest, int &max1, int &max2) {
	if (longest > max1) {
		max2 = max1;
		max1 = longest;
	} else if (longest > max2) {
		max2 = longest;
	}
}

pair<int, int> calculate(int v) { // return max diameter + longest path
	vis[v] = 1;
	int max1 = 0, max2 = 0, vDiameter = 0; // two longest paths from children
	for (int i = 0; i < edges[v].size(); i++) {
		int u = edges[v][i];
		if (vis[u]) continue; // only visit unvisted nodes

		pair<int, int> uResult = calculate(u); // calculate for u
		int uDiameter = uResult.first;
		vDiameter = max(vDiameter, uDiameter);
		int longest = uResult.second;
		if (low[u] > cnt[v]) longest++; // longest path from a node to v through u
		updateMax(longest, max1, max2); // update two maxes that we care
	}

	// vdiameter = max(all children diameter, sum of two longest paths)
	vDiameter = max(vDiameter, max1 + max2); 

	return pair<int, int> (vDiameter, max1);
}

int main() {
	readInput();
	firstTraverse(1, 0);
	cout << calculate(1).first << endl;
	return 0;
}
```

#### Bonus(medium/hard): https://leetcode.com/problems/median-of-two-sorted-arrays/description/

This problem explicitly states the required complexity, which make it quite hard to implement. But I think we can learn from analyzing it incrementally. Below are some algorithm with worse complexity but easier to implement.

1. O(m\*n)

   Loop through array A, find the neighbors of it in B, calculate median if appropriate.
2. O(m\*log(n))

   Loop through array A, binary search the neighbors in B, calculate median if appropriate.
3. O(m + n)

   Loop through array A, note that the neighbor of A[i] in B increases as i increase, we keep a pointer j in B that increases when i increases in A.
4. O(log(m)\*log(n))

   Binary search in A, binary search neighbors in B, calculate median if appropriate. The basic idea is, for each element in A, if the number of smallers elements in both A and B are greater than (m + n)/2, then we should search in the left of that element, otherwise we search in the right

Now how do we contiue to optimize from here? It bases on an observation that the index of the final median is fixed, which is middle = (m + n)/2. So for an element of A at index Ai, for it to be around the median position, we know that its neighbors in B should be of index Bi = middle - Ai. Depends on the value of B[Bi] and A[Ai], we should know to continue searching in the left or the right of Ai.

This problem is also hard to implement because it has lots of special cases and very error-prone. This editoral just provides the algorithm idea, the code will cover those special cases.

```C++
    double findMedianSortedArrays(int A[], int m, int B[], int n) {

        int left = 0, right = m - 1;
        bool odd = (m + n) % 2;
        int middle = (m + n + 1)/2;
        int pos = -1;
		
        while (left <= right) {
            int mid = (left + right)/2;

            if (mid + 1 + n < middle) {
                left = mid + 1;
                continue;
            }

            if (mid + 1 >= middle) {
                pos = mid;
                right = mid - 1;
                continue;
            }

            if (A[mid] < B[middle - mid - 2]) {
                left = mid + 1;
            } else {
                pos = mid;
                right = mid - 1;
            }
        }

        if (pos == -1) {
            if (odd) {

                if (m >= middle) return A[middle - 1];
                else return B[middle - m - 1];
				
            } else {

                int sum = 0;

                if (m >= middle) sum += A[middle - 1];
                else sum += B[middle - m - 1];

                middle ++;
                if (m >= middle) sum += A[middle - 1];
                else sum += B[middle - m - 1];

                return sum/2.0;
            }
        }

        bool takeA = true;
        if (pos + 1 + n > middle) {

            if (A[pos] > B[middle - pos - 1]) {
                takeA = false;
                pos = middle - pos - 1;
            }
        }

        if (takeA) {

            if (odd) return A[pos];
            else {
                int sum = A[pos];

                if (pos + 1 > m - 1) {
                    sum += B[middle - pos - 1];
                } else if (middle - pos - 1 > n - 1) {
                    sum += A[pos + 1];
                } else sum += min(A[pos + 1], B[middle - pos - 1]);

                return sum/2.0;
            }

        } else {

            if (odd) return B[pos];
            else {

                int sum = B[pos];

                if (pos + 1 > n - 1) {
                    sum += A[middle - pos - 1];
                } else if (middle - pos - 1 > m - 1) {
                    sum += B[pos + 1];
                } else sum += min(B[pos + 1], A[middle - pos - 1]);

                return sum/2.0;
            }
        }
    }

```

