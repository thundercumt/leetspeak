#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<int> plusOne(vector<int>& digits) {
    vector<int> ret;
    int n = digits.size();

    int carry = 1, t=0;
    for (int i=0; i<n; ++i) {
      t = digits[n-1-i] + carry;
      ret.push_back(t % 10);
      carry = t / 10;
    }
    if (carry) ret.push_back(1);

    reverse(ret.begin(), ret.end());
    return ret;
  }
};


#ifdef DEBUG

int main() {
  int a[] = {9,9,9};
  vector<int> va(a, a+sizeof(a)/sizeof(int));
  Solution s;
  vector<int> ret = s.plusOne(va);
  for (int i=0; i<ret.size(); ++i)
    cout << ret[i] << ' ';
  cout << '\n';
}

#endif
