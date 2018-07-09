#include <bits/stdc++.h>

using namespace std;

int solve(int f, int s, int g, int u, int d) {
  queue<int> q;
  q.push(s);
  q.push(-1);

  vector<bool> visited(f+1, false);
  visited[s] = true;

  vector<int> distance(f+1, 0);

  while(!q.empty()) {
    int top = q.front();
    q.pop();

    if(top == g) {
      return distance[top];
    }

    if(top != -1 && (top + u) <= f && !visited[top + u]) {
      visited[top + u] = true;
      q.push(top + u);
      distance[top + u] = distance[top] + 1;
    }
    if(top != -1 && (top - d) >= 1 && !visited[top - d]) {
      visited[top - d] = true;
      q.push(top - d);
      distance[top - d] = distance[top] + 1;
    }
  }

  return -1;
}

int main() {
  int f, s, g, u, d;
  cin >> f >> s >> g >> u >> d;

  int steps = solve(f, s, g, u, d);
  if(steps == -1) {
    cout << "use the stairs" << endl;
  } else {
    cout << steps << endl;
  }

  return 0;
}
