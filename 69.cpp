#include <iostream>

using namespace std;


class Solution {
public:
  int mySqrt(int x) {
    int i=0, j=x;
    long mid, sq;
    while (i < j) {
      mid = (i+j) / 2;
      sq = mid * mid;

      if (sq > x) j = mid - 1;
      else if( sq < x) {
        if ((mid+1) * (mid+1) <= x) i = mid + 1;
        else j = j-1;
      }
      else return mid;
    }
    return i;
  }
};


#ifdef DEBUG

int main() {
  Solution s;
  cout << s.mySqrt(4) << '\n';
  cout << s.mySqrt(1) << '\n';
  cout << s.mySqrt(0) << '\n';
  cout << s.mySqrt(8) << '\n';
  cout << s.mySqrt(1024) << '\n';
  cout << s.mySqrt(INT_MAX) << '\n';
}

#endif
