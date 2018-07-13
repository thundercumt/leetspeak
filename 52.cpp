#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  int totalNQueens(int n) {
    vector<int> cols(n, 0);
    vector<int> dial(n+n-1, 0);
    vector<int> diar(n+n-1, 0);
    int ret = 0;
    queen(ret, cols, dial, diar, n, 0);
    return ret;
  }

private:
  bool queen(int &count,
             vector<int> &cols,
             vector<int> &dial,
             vector<int> &diar,
             int n, int i) {
    if (i == n) {
      ++count;
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
      ret |= queen(count, cols, dial, diar, n, i+1);
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
  int ret = s.totalNQueens(4);
  cout << ret << '\n';
}

#endif
