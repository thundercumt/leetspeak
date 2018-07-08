#include <iostream>
#include <string>
#include <vector>

using namespace std;

/** OK but low in efficiency
class Solution {
public:
  string multiply(string num1, string num2) {
    string sum;
    if (num1.size() < num2.size()) return multiply(num2, num1);

    int n = num2.size();
    int m = num1.size();
    char c, t;
    for (int i=n-1; i>=0; --i) {
      string pass;
      c = num2[i] - '0';
      char carry = 0;

      if (c == 0) {
        add(sum, "0");
      }
      else if (c == 1) {
        for (int j=n-1; j>i; --j) pass.push_back('0');//trailing zeros
        pass.append(string(num1.rbegin(), num1.rend()));
        add(sum, pass);
      }
      else {
        for (int j=n-1; j>i; --j) pass.push_back('0');//trailing zeros

        for (int j=m-1; j>=0; --j) {
          t = c * (num1[j]-'0') + carry;
          carry = t / 10;
          t = t % 10;
          pass.push_back(t + '0');
        }
        if (carry) pass.push_back(carry + '0');
        add(sum, pass);
      }
    }

    return string(sum.rbegin(), sum.rend());
  }

  //[0..n) in the order of lsb -> msb
  void add(string &to, const string &from) {
    cout << "to=" << string(to.rbegin(), to.rend()) << " from=" << string(from.rbegin(), from.rend()) << '\n';
    if (to.empty()) {
      to.append(from);
      return;
    }
    const int n = from.size();
    const int m = to.size();
    int carry = 0;
    char c;
    bool reachm=false, reachn=false;
    for (int i=0; i<n || carry; ++i) {
      if (i==m) reachm = true;
      if (i==n) reachn = true;
      c = (reachn ? 0 : from[i]-'0') + (reachm ? 0 : to[i]-'0') + carry;
      carry = c / 10;
      c = c % 10;
      if (reachm) to.push_back(c + '0');
      else to[i] = c + '0';
    }
  }
};
**/


#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
  string multiply(string num1, string num2) {
    int n1 = num1.size(), n2 = num2.size();
    int n = n1 + n2;
    vector<int> v(n, 0);
    for (int i=0; i<n1; ++i) {
      for (int j=0; j<n2; ++j) {
        v[n-1-i-j] += (num1[n1-1-i]-'0') * (num2[n2-1-j]-'0');
      }
    }

    int carry = 0;
    int t;
    for (int i=n-1; i>=0; --i) {
      t = v[i] + carry;
      carry = t / 10;
      v[i] = t % 10;
      //cout << "v[" << i << "]=" << v[i] << '\n';
    }

    int i=0;
    while(i<n && !v[i])++i; //drop leading zero
    if (i==n) return "0";

    string s(n-i, 0);
    int j=-1;
    while (i<n) {
      s[++j] = '0' + v[i];
      ++i;
    }

    return s;
  }
};



#ifdef DEBUG

int main() {
  Solution s;
  cout << s.multiply("2", "3") << '\n';
}




#endif
