#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
  string simplifyPath(string path) {
    vector<string> v;
    v.push_back("/");

    int n = path.size();
    int j, k, count=1;
    for (int i=0; i<n; ++i) {
      for (j=i; j<n && path[j]=='/'; ++j);
      for (k=j+1; k<n && path[k]!='/'; ++k);
      string s = path.substr(j, k-j);

      if (s == "..") {
        if (count > 1) {
          v.pop_back();
          --count;
        }
      }
      else if(!s.empty() && s != ".") {
        v.push_back(s);
        ++count;
      }

      i=k;
    }

    string ret;
    for (int i=0; i<count; ++i) {
      ret += v[i];
      if (i>0 && i<count-1) ret += '/';
    }

    return ret;
  }
};



#ifdef DEBUG

int main() {
  Solution s;
  cout << s.simplifyPath("") << '\n';
  cout << s.simplifyPath("/") << '\n';
  cout << s.simplifyPath("/./") << '\n';
  cout << s.simplifyPath("/////") << '\n';
  cout << s.simplifyPath("/../") << '\n';
  cout << s.simplifyPath("/a/./b/../../c") << '\n';
  cout << s.simplifyPath("/home/a/b/c") << '\n';
}

#endif
