#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
public:
  vector< vector<int> > combinationSum2(vector<int>& candidates, int target) {
    vector< vector<int> > ret;
    if (candidates.empty() || target<=0) return ret;

    sort(candidates.begin(), candidates.end());
    vector<int> ans;
    dfs(candidates, 0, ret, ans, target);
    return ret;
  }

  void dfs(const vector<int> &cands, int fromCand, vector< vector<int> > &ret, vector<int> &ans, int target) {
    if (!target) {
      ret.push_back(ans);
      return;
    }

    int n = cands.size();
    for (int i=fromCand; i<n; ++i) {
      if (cands[i] > target) break;
      ans.push_back(cands[i]);
      dfs(cands, i+1, ret, ans, target-cands[i]);
      ans.pop_back();
      //!!!!because of duplicates, we won't try the same cand twice after it is used!!!!
      while (i+1<n && cands[i+1]==cands[i]) ++i;
    }
  }
};


#ifdef DEBUG

int main() {
  int a[] = {2,5,2,1,2,1};
  vector<int> va(a, a+sizeof(a)/sizeof(int));
  Solution s;
  vector< vector<int> > r = s.combinationSum2(va, 5);
  for (int i=0; i<r.size(); ++i) {
    for (int j=0; j<r[i].size(); ++j) {
      cout << r[i][j] << ' ';
    }
    cout << '\n';
  }

}

#endif
