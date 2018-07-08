#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
  void rotate(vector< vector<int> >& m) {
    int n = m.size();
    int ltx = 0, lty = 0, len = n;

    while (len > 1) {
      for (int i=ltx, j=lty; j<lty+len-1; ++j) {
        swap(m[i][j], m[j][n-1-i]);
        swap(m[i][j], m[n-1-i][n-1-j]);
        swap(m[i][j], m[n-1-j][i]);
      }

      len -= 2;
      ltx += 1;
      lty += 1;
    }
  }
private:
  inline void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
  }
};

#ifdef DEBUG

int main() {
  int a[][6] = {{1,1,1,1,1,1},
                {2,2,2,2,2,2},
                {3,3,3,3,3,3},
                {4,4,4,4,4,4},
                {5,5,5,5,5,5},
                {6,6,6,6,6,6}};

  vector< vector<int> > va;
  for (int i=0; i<6; ++i) {
    vector<int> t(6,0);
    for (int j=0; j<6; ++j)
      t[j] = a[i][j];
    va.push_back(t);
  }
  
  Solution s;
  s.rotate(va);

  for (int i=0; i<6; ++i) {
    for (int j=0; j<6; ++j)
      cout << va[i][j] << ' ';
    cout << '\n';
  }

}

#endif
