#include <string>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
public:
  string addBinary(string a, string b) {
    int i = a.size()-1, j = b.size()-1;

    int carry = 0;
    int t;
    string ret;
    while (carry || i>=0 || j>=0) {
      t = carry;
      if (i>=0) t += a[i--] - '0';
      if (j>=0) t += b[j--] - '0';

      ret.push_back(t % 2 + '0');
      carry = t / 2;
    }

    reverse(ret.begin(), ret.end());
    return ret;
  }
};


#ifdef DEBUG

int main() {
  Solution s;
  cout << s.addBinary("11", "1") << '\n';
  cout << s.addBinary("1010", "1011") << '\n';
}

#endif
