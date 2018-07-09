#include <bits/stdc++.h>

using namespace std;

int abs(int x) {
  if (x < 0) {
    return -x;
  } return x;
}

long long solve(vector<int>& A, vector<int>& B, int k1, int k2) {
  int k = k1 + k2;

  int n = A.size();
  priority_queue<long long> pq;

  for(int i = 0; i < n; i++) {
    pq.push(abs(A[i]-B[i]));
  }

  while(k--) {
    long long top = pq.top();
    pq.pop();
    pq.push(abs(top-1));
  }

  long long answer = 0;
  while(!pq.empty()) {
    long long top = pq.top();
    pq.pop();
    answer += top * top;
  }

  return answer;
}

int main() {
  int n, k1, k2;
  cin >> n >> k1 >> k2;

  vector<int> A(n);
  for(int i = 0; i < n; i++) {
    cin >> A[i];
  }

  vector<int> B(n);
  for(int i = 0; i < n; i++) {
    cin >> B[i];
  }

  long long answer = solve(A, B, k1, k2);

  cout << answer << endl;

  return 0;
}
