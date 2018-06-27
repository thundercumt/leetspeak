#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
      const int N = 1001;
      char m[N][N] = {0};
      int n = s.size();

      int l1=0, l2=0;
      
      for (int i=0; i<n; ++i) {
        m[i][i] = 1;
      }

      for (int step=1; step < n; ++step) {
        for (int i=0; i+step < n; ++i) {
          if (s[i] == s[i+step]) {
            if (step == 1) {
              m[i][i+step] = 1;
              l1 = i;
              l2 = i+step;
            }
            else if (m[i+1][i+step-1] == 1) {
              m[i][i+step] = 1;
              l1 = i;
              l2 = i + step;
            }
          }
        }
      }

      return s.substr(l1, l2-l1+1);
    }
};


#ifdef DEBUG

int main() {
  Solution s;
  cout << s.longestPalindrome("abc") << "\n";
  cout << s.longestPalindrome("aba") << "\n";
  cout << s.longestPalindrome("babad") << "\n";
  cout << s.longestPalindrome("cbbd") << "\n";
}

#endif
