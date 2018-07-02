#include <vector>
#include <string>
#include <iostream>

using namespace std;


class Solution {
public:
    vector<string> generateParenthesis(int n) {
      vector<string> v;

      if (n<=0) return v;
      
      string s(n*2, 0);
      dfs(v, s, 0, 0, n, n*2);

      return v;
    }

  void dfs(vector<string> &v, string &s, int i, int depth, int r, int n) {
    if (i==n) {
      v.push_back(s);
      return;
    }

    if (r>0) {
      s[i] = '(';
      dfs(v, s, i+1, depth+1, r-1, n);
    }

    if (depth > 0) {
      s[i] = ')';
      dfs(v, s, i+1, depth-1, r, n);
    }
  }
};

#ifdef DEBUG

int main() {
  Solution s;
  s.generateParenthesis(3);
}

#endif
