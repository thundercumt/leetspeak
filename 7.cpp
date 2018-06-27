#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
      //const int INT_MAX = 2^31 - 1;
      
      int sign = x > 0 ? 1 : -1;
      int xx = x >= 0 ? x : -x;
      int t=0, l;
      while (xx) {
        l = t;

        //check multiplication overflow
        if (t > INT_MAX / 10) {
          t = 0;
          break;
        }
        t *= 10;        

        //check add overflow
        if (INT_MAX - t < xx % 10) {
          t = 0;
          break;
        }
        t += xx % 10;

        xx /= 10;
      }
      t *= sign;
      return t;
    }
};


#ifdef DEBUG

int main() {
  Solution s;

  cout << s.reverse(5) << '\n';
  cout << s.reverse(-5) << '\n';
  cout << s.reverse(12345) << '\n';
  cout << s.reverse(-12345) << '\n';
  cout << s.reverse(-2147483647) << '\n';
  cout << s.reverse(534236469) << '\n';
  cout << s.reverse(1534236469) << '\n';
}

#endif
