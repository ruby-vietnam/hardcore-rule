class Solution {
  public:
    bool isPowerOfThree(int n) {
      if (n < 0) { return false; }
      if (n == 0) { return false; }
      if (n == 1) { return true; }

      while (n > 0) {
        if (n % 3 == 0) {
          if (n == 3) {
            return true;
          } else {
            n /= 3;
          }
        } else {
          return false;
        }
      }
      return true;
    }
};
