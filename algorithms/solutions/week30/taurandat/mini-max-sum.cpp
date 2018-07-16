#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n, _sum, _min, _max;

  cin >> n;
  _sum = _min = _max = n;
  for(int i = 0; i < 4; i++) {
    cin >> n;
    _sum += n;
    _min = min(_min, n);
    _max = max(_max, n);
  }

  cout << _sum - _max << " " << _sum - _min << endl;

  return 0;
}
