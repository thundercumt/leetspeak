#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector< vector<int> > combinationSum(vector<int>& candidates, int target) {
    vector< vector<int> > ret;
    if (candidates.empty() || target <= 0) return ret;
    sort(candidates.begin(), candidates.end());

    vector<int> ans;
    dfs(candidates, 0, ret, ans, target);
    return ret;
  }

  void dfs(const vector<int> &cands, int fromCand, vector< vector<int> > &ret, vector<int> &ans, int target) {
    if (target == 0) {
      ret.push_back(ans);
      return;
    }

    int n = cands.size();
    for (int i=fromCand; i<n; ++i) {
      if (cands[i] <= target) {
        ans.push_back(cands[i]);
        dfs(cands, i, ret, ans, target-cands[i]);
        ans.pop_back();
      }
      else break;
    }
  }
};


#ifdef DEBUG

int main() {
  int a[] = {2,3,5};
  vector<int> va(a, a+sizeof(a)/sizeof(int));
  Solution s;
  vector< vector<int> > r = s.combinationSum(va, 8);
  for (int i=0; i<r.size(); ++i) {
    for (int j=0; j<r[i].size(); ++j) {
      cout << r[i][j] << ' ';
    }
    cout << '\n';
  }

}

#endif
