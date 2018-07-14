#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  string getPermutation(int n, int k) {
    string s(n, 0);
    int fact[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    vector<int> cands(9, 0);
    for (int i=0; i<n; ++i) cands[i] = i+1;

    int nn = n-1, kk = k-1;//zero-based
    while (nn >= 1) {
      int idx = kk / fact[nn];
      s[n-nn-1] = '0' + cands[idx];
      cands.erase(cands.begin() + idx);
      kk = kk % fact[nn];
      --nn;
    }
    s[n-1] = '0' + cands[0];
    return s;
  }
};


#ifdef DEBUG

int main() {
  Solution s;
  cout << s.getPermutation(3, 3) << '\n';
  cout << s.getPermutation(4, 9) << '\n';
}

#endif
