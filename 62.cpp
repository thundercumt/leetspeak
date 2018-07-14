#include <vector>
#include <iostream>

using namespace std;

#ifdef DEBUG


void output(vector< vector<int> > &v) {
  for (int i=0; i<v.size(); ++i) {
    for (int j=0; j<v[0].size(); ++j)
      cout << v[i][j] << ' ';
    cout << '\n';
  }
}

#endif

class Solution {
public:
  int uniquePaths(int m, int n) {
    if (!m && !n) return 0;
    if (!m || !n) return 1;

    vector< vector<int> > dp(m+1, vector<int>(n+1, 0));
    dp[1][0] = 1;//fake start point on the left of start

    for (int i=1; i<=m; ++i) {
      for (int j=1; j<=n; ++j) {
        dp[i][j] = dp[i][j-1] + dp[i-1][j];
      }
    }

    #ifdef DEBUG
    output(dp);
    #endif

    return dp[m][n];    
  }
};


#ifdef DEBUG

int main() {

  Solution s;
  cout << s.uniquePaths(7, 3) << '\n';
}

#endif
