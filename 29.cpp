#include <iostream>
#include <cstdlib>

using namespace std;

class Solution {
public:
  int divide(int dividend, int divisor) {
    if (divisor == 0) return INT_MAX;
    if (dividend == 0) return 0;
    if (dividend == divisor) return 1;

    int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
    
    long dvd = labs(dividend);
    long dvs = labs(divisor);
    long r = 0;
    while(dvd >= dvs) {
      int tmp = 1;
      while (dvd >= (dvs << tmp)) {
        ++tmp;
      }
      
      r += (1L << (tmp-1));
      dvd -= (dvs << (tmp-1));
    }

    if (sign == -1) r = -r;
    if (r > INT_MAX || r < INT_MIN) r = INT_MAX;
    return r;
  }
};

#ifdef DEBUG

int main() {
  Solution s;
  cout << s.divide(8, 2) << '\n';
  cout << s.divide(9, 4) << '\n';
  cout << s.divide(7, -3) << '\n';
  cout << s.divide(-5, -2) << '\n';
  cout << s.divide(-2147483648, -1) << '\n';
  cout << s.divide(-2147483648, 1) << '\n';
}

#endif
