#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int longestValidParentheses(string s) {
    if (s.empty()) return 0;
    const int n = s.size();
    vector<int> dp(n, 0);//dp[i] is the max length of valid parenthesis ending at i

    int maxlen = 0;
    for (int i=0; i<n; ++i) {
      if (s[i] == '(') continue;//dp[i] = 0;
      else /*if (s[i] == ')')*/ {
        if (i==1 && s[i-1] == '(') dp[i] = 2;
        else if (i>1 && s[i-1] == '(') dp[i] = dp[i-2] + 2;
        else if (i-dp[i-1]-1>=0 && s[i-dp[i-1]-1] == '(')
          dp[i] = dp[i-1] + 2 + dp[i-dp[i-1]-2];//the matching part + the one before the matching part
      }

      if (dp[i] > maxlen) maxlen = dp[i];
    }
    return maxlen;
  }
};


#ifdef DEBUG

int main() {
  Solution s;
  cout << s.longestValidParentheses("))((()()((") << '\n';
  cout << s.longestValidParentheses("(((()(((())(()()(())()") << '\n';
}

#endif
