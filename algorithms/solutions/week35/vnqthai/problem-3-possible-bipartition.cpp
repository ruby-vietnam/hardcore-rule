#define forl(i, from, to) for (int i = (from); i <  (to); i++)
#define fore(i, from, to) for (int i = (from); i <= (to); i++)

class Solution {
  public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
      vector<vector<bool>> g(N+1, vector<bool>(N+1, false)); // Graph
      forl(i, 0, dislikes.size()) {
        short int u = dislikes[i][0];
        short int v = dislikes[i][1];
        g[u][v] = true;
        g[v][u] = true;
      }

      vector<unsigned char> color(N+1, 0);
      queue<short int> q;
      q.push(1);
      color[1] = 1;

      while (!q.empty()) {
        short int i = q.front();
        q.pop();
        fore(j, 1, N) {
          if (g[i][j]) {
            if (color[j] == 0) {
              color[j] = 3 - color[i];
              q.push(j);
            } else if (color[i] == color[j]) {
              cout << (int) i << "," << (int) j << "; " << (int) color[i] << "," << (int) color[j] << "\n";
              return false;
            }
          }
        }
      }

      return true;
    }
};
