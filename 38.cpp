#include <string>
#include <iostream>
#include <map>

using namespace std;


class Solution {
public:
  string countAndSay(int n) {
    if (n==1) return "1";
    if (m.count(n)) return m[n];

    string s = countAndSay(n-1);
    int nn = s.size();
    int i=0;
    string ret;

    while (i < nn) {
      int j=i+1;
      for (; j<nn && s[i]==s[j]; ++j);
      ret.push_back('0'+j-i);
      ret.push_back(s[i]);
      i=j;
    }
    m[n] = ret;
    return ret;
  }

private:
  map<int, string> m;
};


#ifdef DEBUG

int main() {

  Solution s;
  for (int i=1; i<50; ++i)
    cout << s.countAndSay(i) << '\n';

}

#endif
