#include <iostream>
#include <cmath>
using namespace std;

class Solution {
  public:
    int reverse(int x) {
      if (x == 0 || x == INT_MAX || x == INT_MIN) { return 0; }
      int s = x > 0 ? 1 : -1;
      if (x < 0) { x = -x; }
      int n = number_of_digits(x);
      long long result = 0L;

      for (int i = 1; i <= n; i++) {
        result += (x%10)*pow(10, n-i);
        x /= 10;
      }

      if (result > INT_MAX) { return 0; }
      return result*s;
    }

  private:
    int number_of_digits(int x) {
      return log10(abs((double) x)) + 1;
    }
};

int main() {
  Solution o;
  int x =-2147483648; 
  cout<<o.reverse(x);
  return 0;
}
