#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
  vector<int> spiralOrder(vector< vector<int> >& matrix) {
    vector<int> r;
    if (matrix.empty() || matrix[0].empty()) return r;
    int m = matrix.size(), n = matrix[0].size();
    vector< vector<bool> > visited(m, vector<bool>(n, false));

    int deltaI[] = {0, 1, 0, -1};
    int deltaJ[] = {1, 0, -1, 0};
    int delta = 0;
    int i=0, j=0;
    while (true) {cout << i << ' '<< j << '\n';
      r.push_back(matrix[i][j]);
      visited[i][j] = true;

      i += deltaI[delta];
      j += deltaJ[delta];

      if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j]) {
        i -= deltaI[delta];
        j -= deltaJ[delta];

        if (j+1 < n && !visited[i][j+1]) delta = 0;
        else if (i+1 < m && !visited[i+1][j]) delta = 1;
        else if (j-1 >= 0 && !visited[i][j-1]) delta = 2;
        else if (i-1 >= 0 && !visited[i-1][j]) delta = 3;
        else break;//no where to go

        
        i += deltaI[delta];
        j += deltaJ[delta];
      }

    }
    return r;
  }
};


#ifdef DEBUG

int main() {
  int a[][4] = {
    {1,2,3,4},
    {5,6,7,8},
    {9, 10, 11, 12},
    {13,14,15,16}
  };
  int m = sizeof(a) / sizeof(a[0]);
  int n = sizeof(a[0]) / sizeof(int);
  vector< vector<int> > v(m, vector<int>(n, 0));
  for (int i=0; i<m; ++i) {
    for (int j=0; j<n; ++j)
      v[i][j] = a[i][j];
  }
  Solution s;
  vector<int> r = s.spiralOrder(v);
  for (int i=0; i<r.size(); ++i)
    cout << r[i] << ' ';
  cout << '\n';
}

#endif
