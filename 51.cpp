#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  vector< vector<string> > solveNQueens(int n) {
    vector<int> colPos(n, -1);
    vector<int> cols(n, 0);
    vector<int> dial(n+n-1, 0);
    vector<int> diar(n+n-1, 0);
    vector< vector<string> > ret;
    queen(ret, colPos, cols, dial, diar, n, 0);
    return ret;
  }

private:
  bool queen(vector< vector<string> > &v,
             vector<int> &colPos,
             vector<int> &cols,
             vector<int> &dial,
             vector<int> &diar,
             int n, int i) {
    if (i == n) {
      for (int j=0; j<n; ++j)
        cout << colPos[j] << ' ';
      cout << '\n';
      
      vector<string> r;
      for (int j=0; j<n; ++j) {
        string s(n, '.');
        s[colPos[j]] = 'Q';
        r.push_back(s);
      }
      v.push_back(r);
      return true;
    }

    vector<int> cands;
    int l, r;
    for (int j=0; j<n; ++j) {
      diagonal(n, i, j, l, r);
      if (!cols[j] && !dial[l] && !diar[r]) cands.push_back(j);
    }

    bool ret = false;
    for (int j=0; j<cands.size(); ++j) {
      diagonal(n, i, cands[j], l, r);
      cols[cands[j]] = 1;
      dial[l] = 1;
      diar[r] = 1;
      colPos[i] = cands[j];
      ret |= queen(v, colPos, cols, dial, diar, n, i+1);
      colPos[i] = -1;
      cols[cands[j]] = 0;
      dial[l] = 0;
      diar[r] = 0;
    }

    return ret;
  }

  void diagonal(int n, int i, int j, int &l, int &r) {
    int m = min(i, j);
    int x1 = i - m;
    int y1 = j - m;
    l = n - x1 - 1 + y1;

    m = min(j, n-1-i);
    x1 = i + m;
    y1 = j - m;
    r = n-1-x1 + n-1-y1;
  }
};



#ifdef DEBUG

int main() {
  Solution s;
  vector< vector<string> > ret = s.solveNQueens(5);
  for (int i=0; i<ret.size(); ++i) {
    for (int j=0; j<ret[i].size(); ++j)
      cout << ret[i][j] << '\n';
    cout << '\n';
  }
}

#endif
