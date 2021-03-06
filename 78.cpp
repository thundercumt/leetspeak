#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class SolutionOK {
public:
  vector< vector<int> > subsets(vector<int>& nums) {
    vector< vector<int> > r;
    sort(nums.begin(), nums.end());
    vector<int> v;
    dfs(r, v, nums, 0, nums.size());
    return r;
  }

  void dfs(vector< vector<int> > &r, vector<int> &v,
           vector<int> &nums, int i, int n) {
    if (i > n) return;

    r.push_back(v);

    for (int ii=i; ii<n; ++ii) {
      v.push_back(nums[ii]);
      dfs(r, v, nums, ii+1, n);
      v.pop_back();
    }
    
  }
};

class Solution {
public:
    vector< vector<int> > subsets(vector<int>& nums) {
        vector< vector<int> > v;
        v.push_back(vector<int>());
        int size = nums.size();
        if (size == 0) return v;

        sort(nums.begin(), nums.end());

        for (int i=0; i<size; ++i) {
            int vsize = v.size();
            for (int j=0; j<vsize; ++j) {
                vector<int> copy(v[j]);
                copy.push_back(nums[i]);
                v.push_back(copy);
            }
        }
        return v;
    }
};


#ifdef DEBUG

int main() {
  int a[] = {1,2,3,4};
  vector<int> va(a, a+sizeof(a)/sizeof(int));
  Solution s;
  vector< vector<int> > r = s.subsets(va);

  for (int i=0; i<r.size(); ++i) {
    for (int j=0; j<r[i].size(); ++j)
      cout << r[i][j] << ' ';
    cout << '\n';
  }

}

#endif
