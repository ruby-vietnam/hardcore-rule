#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

template <class T> int getbit(T s, int i) { return (s >> i) & 1; }
template <class T> T onbit(T s, int i) { return s | (T(1) << i); }
template <class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template <class T> ll countbit(T s) { return __builtin_popcountll(s); }

#define all(a) (a).begin(), (a).end()
#define ms(a, x) memset(a, x, sizeof(a))
#define forv(v, it) for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); it++)
#define clear(x) v.clear(); vector<T>(v).swap(v)

#define ANSI_COLOR_RESET "\x1B[0m"
#define ANSI_COLOR_RED   "\x1B[31m"
#define ANSI_COLOR_BOLD  "\x1B[1m"
#define log_debug(x) printf("L%d: " ANSI_COLOR_BOLD ANSI_COLOR_RED "%s\n" ANSI_COLOR_RESET, __LINE__, x)

#define PI (2 * acos((ld)0))
#define linf (1ll << 60)
#define eps  1e-12

#define div   ___div
#define next  ___next
#define prev  ___prev
#define left  ___left
#define right ___right
#define y0    ___y0
#define y1    ___y1

ll b[20][20], a[20], dp[1<<18][20];

int main(void) {
  int n, m, k;
  cin >> n >> m >> k;

  ll ans = 0;
  for (int i = 0; i < n; ++ i) {
    cin >> a[i];
    dp[1<<i][i] = a[i];
    if (m == 1) {
      ans = max(ans, dp[1<<i][i]);
    }
  }

  for (int i = 0; i < k; ++ i) {
    int x, y, c;
    cin >> x >> y >> c;
    b[x-1][y-1] = c;
  }

  for (int i = 1; i < (1<<n); ++ i) {
    if (countbit(i) > m) continue;
    for (int j = 0; j < n; ++ j) {
      if (((i>>j) & 1) == 0) {
        for (int t = 0; t < n; ++ t) if (((i>>t) & 1)) {
            dp[i | (1<<j)][j] = max(dp[i | (1<<j)][j], dp[i][t] + a[j] + b[t][j]);
        }
        if (countbit(i) == m - 1) {
          ans = max(ans, dp[i | (1<<j)][j]);
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}
