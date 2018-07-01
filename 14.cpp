#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      if (strs.size() == 0) return "";
      if (strs.size() == 1) return strs[0];

      int m = strs.size();
      char c;
      string& s = strs[0];

      int n = s.size();
      for (int j=1; j<m; ++j)
        if (strs[j].size() < n) n = strs[j].size();

      for(int i=0; i<n; ++i) {
        c = s[i];
        for (int j=1; j<m; ++j) {
          if (strs[j][i] != c) return s.substr(0, i);
        }
      }

      return s.substr(0, n);
    }
};


#ifdef DEBUG

int main() {
  Solution s;

  string a[] = {"flower", "flow", "flight"};
  vector<string> v(a, a+sizeof(a)/sizeof(string));

  cout << s.longestCommonPrefix(v) << '\n';
}

#endif
