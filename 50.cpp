#include <iostream>

using namespace std;

class Solution {
public:
  double myPow(double x, int n) {
    if (n>=0) return pow1(x, n);
    else return pow2(x, n);
  }

  double pow1(double x, int n) {
    if (n==0) return 1;
    if (n==1) return x;
    if (n==-1) return 1/x;

    double t = x;
    int nn = n-1, nnn=1;

    while (nn>>1) {
      t *= t;
      nn >>= 1;
      nnn <<= 1;
    }

    return t * pow1(x, n-nnn);
  }

  double pow2(double x, int n) {
    //cout << x << ' ' << n << '\n';
    if (n==0) return 1;
    if (n==1) return x;
    if (n==-1) return 1/x;
    
    double t = 1 / x;
    int nn = n+1, nnn=-1;

    while ((nn>>1) < -1) {
      t *= t;
      nn >>= 1;
      nnn <<= 1;
    }
    return t * pow2(x, n-nnn);
  }
};


#ifdef DEBUG

int main() {
  Solution s;
  cout << s.myPow(2.0, 10) << '\n';
  cout << s.myPow(2.10000, 3) << '\n';
  cout << s.myPow(2.0, -2) << '\n';
  cout << s.myPow(1.0, INT_MIN) << '\n';
}

#endif
