#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
    int ns = s.size(), np = p.size();
    vector< vector<int> > v(ns+1, vector<int>(np+1, 0));

    v[0][0] = 1;
    for (int i=1; i<=ns; ++i) v[i][0] = 0;

    for (int j=1; j<=np; ++j) v[0][j] = v[0][j-1] && p[j-1]=='*';
    
    for (int i=1; i<=ns; ++i) {
      for (int j=1; j<=np; ++j) {
        if (s[i-1] == p[j-1] || p[j-1] == '?') v[i][j] = v[i-1][j-1];
        else if (p[j-1] != '*') v[i][j] = 0;
        else v[i][j] = v[i][j-1] || v[i-1][j]; //p[j-1] == '*'
      }
    }

    /**
    for (int i=0; i<=ns; ++i) {
      for (int j=0; j<=np; ++j)
        cout << v[i][j] << ' ';
      cout << '\n';
    }
    **/
    
    return v[ns][np];
  }
};


#ifdef DEBUG

int main() {
  Solution s;
  cout << s.isMatch("aa", "a") << '\n';
  cout << s.isMatch("aa", "*") << '\n';
  cout << s.isMatch("cb", "?a") << '\n';
  cout << s.isMatch("adceb", "*a*b") << '\n';
  cout << s.isMatch("acdcb", "a*c?b") << '\n';
  cout << s.isMatch("mississippi", "m??*ss*?i*pi") << '\n';
  return 0;
}

#endif
