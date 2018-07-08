#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  vector< vector<int> > permute(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector< vector<int> > ret;

    do {
      ret.push_back(nums);
    }  while (nextPermute(nums));

    return ret;
  }

private:
  bool nextPermute(vector<int> &v) {
    int n = v.size();
    int j=n-1;
    while (j>=1 && v[j-1] >= v[j]) --j;
    if (!j) return false;

    int i=j-1;
    while (j<n-1 && v[i] < v[j+1]) ++j;
    
    int tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
    
    reverse(v, i+1, n-1);

    return true;
  }

  void reverse(vector<int> &v, int i, int j) {
    int t;
    while (i<j) {
      t = v[i];
      v[i] = v[j];
      v[j] = t;
      ++i, --j;
    }
  }
};


#ifdef DEBUG

int main() {
  int a[] = {1,2,3};
  vector<int> va(a, a+sizeof(a)/sizeof(int));
  Solution s;
  vector< vector<int> > r = s.permute(va);

  for (int i=0; i<r.size(); ++i) {
    for (int j=0; j<r[i].size(); ++j)
      cout << r[i][j] << ' ';
    cout << '\n';
  }

}

#endif
