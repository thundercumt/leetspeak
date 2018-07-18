#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  vector< vector<int> > combine(int n, int k) {
    vector< vector<int> > r;
    if (k>n) return r;

    this->n = n;
    this->k = k;
    vector<int> v(k, 0);
    dfs(r, v, 0, 1);

    return r;
  }

private:
  void dfs(vector< vector<int> >&r, vector<int> &v, int c, int i) {
    if (c==this->k) {
      r.push_back(v);
      return;
    }

    if (i > this->n) return;

    for (int ii=i; ii<=this->n; ++ii) {
      v[c] = ii;
      dfs(r, v, c+1, ii+1);
    }
  }

  int n, k;
};


#ifdef DEBUG

int main() {
  Solution s;
  vector< vector<int > > r = s.combine(4,3);
  for (int i=0; i<r.size(); ++i) {
    for (int j=0; j<r[0].size(); ++j)
      cout << r[i][j] << ' ';
    cout << '\n';
  }
}

#endif
