#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = m==0 ? 0 : matrix[0].size();
    vector<int> row(m, 0);
    vector<int> col(n, 0);

    for (int i=0; i<m; ++i) {
      for (int j=0; j<n; ++j){
        if (!matrix[i][j]) {
          row[i] = 1;
          col[j] = 1;
        }
      }
    }

    for (int i=0; i<m; ++i)
      if (row[i])
        for (int j=0; j<n; ++j) matrix[i][j] = 0;

    for (int j=0; j<n; ++j)
      if (col[j])
        for (int i=0; i<m; ++i) matrix[i][j] = 0;
  }
};
