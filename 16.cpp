#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
      int n = nums.size();
      sort(nums.begin(), nums.end());
      int ret=nums[0]+nums[1]+nums[2];

      int k=0, t, tmp;
      while (k<n && nums[k] <= max(nums[0], target)) {
        int i=k+1, j=n-1;

        while (i < j) {
          tmp = nums[k] + nums[i] + nums[j];
          if (tmp < target) {
            if (target - tmp < abs(ret - target)) ret = tmp;
            ++i;
          }
          else if (tmp > target) {
            if (tmp - target < abs(ret - target)) ret = tmp;
            --j;
          }
          else {
            return target;
          }
        }

        ++k;
      }

      return ret;
    }
};


#ifdef DEBUG

int main() {
  int a[] = {-1, 2, 1, -4};
  vector<int> v(a, a+sizeof(a)/sizeof(int));
  Solution s;
  cout << s.threeSumClosest(v, 1) << '\n';
}

#endif
