#include <iostream>

using namespace std;

class Solution {
public:
  int climbStairs(int n) {
    if (n==1) return 1;
    if (n==2) return 2;
    int x=1, y=2;

    for (int i=3; i<=n; ++i) {
      y = x + y;
      x = y - x;
    }
    return y;
  }
};



#ifdef DEBUG

int main() {
  Solution s;
  for (int i=1; i<=10; ++i)
    cout << s.climbStairs(i) << '\n';
  cout << s.climbStairs(INT_MAX) << '\n';
}

#endif
