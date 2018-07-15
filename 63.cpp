#include <vector>
#include <iostream>

using namespace std;

#ifdef DEBUG

void output(vector< vector<int> > v) {
  for (int i=0; i<v.size(); ++i) {
    for (int j=0; j<v[i].size(); ++j)
      cout << v[i][j] << ' ';
    cout << '\n';
  }

}

#endif

class Solution {
public:
  int uniquePathsWithObstacles(vector< vector<int> >& g) {
    if (!g.size() || !g[0].size()) return 0;

    int m=g.size(), n=g[0].size();
    vector< vector<int> > df(m+1, vector<int>(n+1, 0));
    df [1][0] = 1;

    for (int i=1; i<=m; ++i) {
      for (int j=1; j<=n; ++j) {
        if (g[i-1][j-1]) df[i][j] = 0;
        else df[i][j] = df[i-1][j] + df[i][j-1];
      }
    }

    #ifdef DEBUG
    output(df);
    #endif

    return df[m][n];
  }
};


#ifdef DEBUG

int main() {
  int a[][3] = {{0,0,0},{0,1,0},{0,0,0}};
  vector< vector<int> >va(sizeof(a)/sizeof(a[0]),
                          vector<int>(sizeof(a[0])/sizeof(int), 0));
  for (int i=0; i<sizeof(a)/sizeof(a[0]); ++i)
    for (int j=0; j<sizeof(a[0])/sizeof(int); ++j)
      va[i][j] = a[i][j];
  Solution s;
  cout << s.uniquePathsWithObstacles(va) << '\n';
}

#endif
