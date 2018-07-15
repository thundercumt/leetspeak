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
  int minPathSum(vector< vector<int> >& grid) {
    if (!grid.size() || !grid[0].size()) return 0;

    int m = grid.size(), n = grid[0].size();

    vector< vector<int> > df(m+1, vector<int>(n+1, INT_MAX));
    df[1][0] = 0;
    
    for (int i=1; i<=m; ++i) {
      for (int j=1; j<=n; ++j) {
        df[i][j] = min(df[i-1][j], df[i][j-1]) + grid[i-1][j-1];
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
  int a[][3] = {{1,3,1}, {1,5,1}, {4,2,1}};
  vector< vector<int> > va(sizeof(a)/sizeof(a[0]),
                           vector<int> (sizeof(a[0])/sizeof(int), 0));
  for (int i=0; i<sizeof(a)/sizeof(a[0]); ++i)
    for (int j=0; j<sizeof(a[0])/sizeof(int); ++j)
      va[i][j] = a[i][j];

  Solution s;
  cout << s.minPathSum(va) << '\n';
}

#endif
