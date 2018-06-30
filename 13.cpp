#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
      int t = 0;
      int m[256] = {0};

      m['M'] = 1000;
      m['C'] = 100;
      m['D'] = 500;
      m['X'] = 10;
      m['L'] = 50;
      m['I'] = 1;
      m['V'] = 5;

      int n = s.size();
      for (int i=0; i<n; ++i) {
        if (i+1 < n && m[s[i]] < m[s[i+1]]) {
          t -= m[s[i]];
        }
        else {
          t += m[s[i]];
        }
      }
      
      return t;
    }
};


#ifdef DEBUG

int main() {

  Solution s;

  cout << s.romanToInt("III") << '\n';
  cout << s.romanToInt("IV") << '\n';
  cout << s.romanToInt("IX") << '\n';
  cout << s.romanToInt("LVIII") << '\n';
  cout << s.romanToInt("MCMXCIV") << '\n';

}

#endif
