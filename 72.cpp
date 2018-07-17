#include <string>
#include <iostream>
#include <vector>

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
  int minDistance(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();

    cout << "m=" << m << " n=" << n << '\n';

    vector< vector<int> > dp(m+1, vector<int>(n+1, 0));
    for (int i=1; i<=n; ++i) dp[0][i] = i;
    for (int i=1; i<=m; ++i) dp[i][0] = i;

    int t;
    for (int i=1; i<=m; ++i) {
      for (int j=1; j<=n; ++j) {
        t = min(dp[i][j-1]+1, dp[i-1][j]+1);
        t = min(t, dp[i-1][j-1] + !(word1[i-1]==word2[j-1]));
        dp[i][j] = t;
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
  cout << s.minDistance("horse", "ros") << '\n';
  cout << s.minDistance("intention", "execution") << '\n';
}

#endif
