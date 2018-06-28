#include <iostream>

using namespace std;


class Solution {
public:
    bool isPalindrome(int x) {
      int xx = x;
      int t=0;

      if (x < 0) return false;
      else if (x < 10) return true;

      while(xx) {
        t *= 10;
        t += xx % 10;
        xx /= 10;
      }

      return x == t;
    }
};


#ifdef DEBUG

int main() {
  Solution s;
  cout << s.isPalindrome(121) << '\n';
  cout << s.isPalindrome(0) << '\n';
  cout << s.isPalindrome(10) << '\n';
  cout << s.isPalindrome(-121) << '\n';
}

#endif
