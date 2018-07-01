#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector< vector<int> > fourSum(vector<int>& nums, int target) {
      vector< vector<int> > ret;
      int n = nums.size();

      if (n<4) return ret;
      int t, l, r;
      vector<int> tv(4,0);
      sort(nums.begin(), nums.end());

      for (int i=0; i<n; ++i) {
        for(int j=i+1; j<n; ++j) {
          t = target - nums[i] - nums[j];

          l = j+1, r = n-1;

          while (l < r) {
            if(nums[l] + nums[r] < t) {
              ++l;
            }
            else if (nums[l] + nums[r] > t) {
              --r;
            }
            else {
              tv[0] = nums[i];
              tv[1] = nums[j];
              tv[2] = nums[l];
              tv[3] = nums[r];
              ret.push_back(tv);

              while (nums[r-1]==nums[r]) --r;
              --r;
            }
          }

          while(nums[j+1]==nums[j])++j;
        }

        while(nums[i+1]==nums[i]) ++i;
      }

      return ret;
    }
};


#ifdef DEBUG

int main() {
  int a[] = {1, 0, -1, 0, -2, 2};
  vector<int> v(a, a+sizeof(a)/sizeof(int));
  Solution s;
  vector< vector<int> > r = s.fourSum(v, 0);

  for (int i=0; i<r.size(); ++i) {
    cout << r[i][0] << ' ' << r[i][1] << ' ' << r[i][2] << ' ' << r[i][3] << '\n';
  }

}

#endif
