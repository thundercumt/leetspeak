#include <cctype>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
      return isMatch(s, s.size()-1, p, p.size()-1);
    }

  bool isMatch(string s, int i1, string p, int i2) {
    //cout << "isMatch(s, " << i1 << " p " << i2 << " ) called\n";
    
    while(i1>=0 && i2>=0 && p[i2]!='*') {
      if (s[i1] != p[i2] && p[i2] != '.') return false;
      --i1;
      --i2;
    }

    if (i1<0 && i2<0) return true;
    if (i1<0 && i2>=0 && p[i2]!='*') return false;
    if (i2<0 && i1>=0) return false;

    char pc = p[i2-1];
    if (i1 < 0) {
      return isMatch(s, i1, p, i2-2);
    }
    else if (pc != '.' && pc != s[i1])
      return isMatch(s, i1, p, i2-2);
    else {
      return isMatch(s, i1, p, i2-2) || isMatch(s, i1-1, p, i2);
    }
  }
};


#ifdef DEBUG

int main() {
  Solution s;
  cout << s.isMatch("", "") << '\n';
  cout << s.isMatch("", "a*") << '\n';
  cout << s.isMatch("ha", "") << '\n';
  cout << s.isMatch("aa", "a") << '\n';
  cout << s.isMatch("aa", "a*") << '\n';
  cout << s.isMatch("ab", ".*") << '\n';
  cout << s.isMatch("aab", "c*a*b") << '\n';
  cout << s.isMatch("mississippi", "mis*is*p*.") << '\n';
}

#endif
