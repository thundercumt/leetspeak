#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
  vector< vector<int> > generateMatrix(int n) {
    vector< vector<int> > ret(n, vector<int>(n, 0));

    int i=0, j=0;
    int di[] = {0, 1, 0, -1};
    int dj[] = {1, 0, -1, 0};
    int delta = 0;
    int k = 0;
    while (true) {
      ret[i][j] = ++k;
      i += di[delta];
      j += dj[delta];

      if (i<0 || i>=n || j<0 || j>=n || ret[i][j]) {
        i -= di[delta];
        j -= dj[delta];
        
        if (j+1<n && !ret[i][j+1]) delta = 0;
        else if (i+1<n && !ret[i+1][j]) delta = 1;
        else if (j-1>=0 && !ret[i][j-1]) delta = 2;
        else if (i-1>=0 && !ret[i-1][j]) delta = 3;
        else break;

        i += di[delta];
        j += dj[delta];
      }
    }

    return ret;
  }
};


#ifdef DEBUG

int main() {
  Solution s;
  vector< vector<int> > ret = s.generateMatrix(4);
  for (int i=0; i<ret.size(); ++i) {
    for (int j=0; j<ret[0].size(); ++j) {
      cout << ret[i][j] << ' ';
    }
    cout << '\n';
  }

}

#endif
