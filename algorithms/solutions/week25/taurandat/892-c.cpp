/*
 *
 * Link: https://leetcode.com/problems/split-array-with-same-average
 *
 * 52 / 52 test cases passed.
 * Status: Accepted
 * Runtime: 31 ms
 *
 */

#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
  while(b) a %= b, swap(a, b);
  return a;
}

int main() {
  int n;
  cin >> n;

  vector <int> arr;
  arr.resize(n);

  int count_1 = 0;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] == 1) {
      count_1 += 1;
    }
  }

  if(count_1 > 0) {
    cout << n - count_1 << endl;
  } else {
    for(int i=1; i<n; i++) {
      for(int j=0; j + i < n; j++) {
        arr[j] = gcd(arr[j], arr[j+1]);
        if(arr[j]==1) {
          cout << i+n-1 << endl;
          return 0;
        }
      }
    }

    cout << -1 << endl;
  }

  return 0;
}
