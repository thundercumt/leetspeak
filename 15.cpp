#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector< vector<int> > threeSum(vector<int>& nums) {
      vector< vector<int> > v;
      sort(nums.begin(), nums.end());

      int k=0, n=nums.size();
      int t;

      while (k<n && nums[k]<=0) {
        t = -nums[k];

        int i=k+1, j=n-1;
        while (i<j) {
          if (nums[i] + nums[j] < t) {
            while(i<j && nums[i+1]==nums[i])++i;
            ++i;
          }
          else if (nums[i] + nums[j] > t) {
            while(i<j && nums[j-1]==nums[j])--j;
            --j;
          }
          else {
            vector<int> tv;
            tv.push_back(nums[k]);
            tv.push_back(nums[i]);
            tv.push_back(nums[j]);
            v.push_back(tv);
            while(i<j && nums[j-1]==nums[j])--j;
            --j;
          }
        }

        while(k<n && nums[k+1]==nums[k])++k;
        ++k;
      }

      return v;
    }
};


#ifdef DEBUG

int main() {
  Solution s;
  
  int nums[] = {-1, 0, 1, 1, 2, 2, -1, -1, 0, 0, -4, -3, -3,  3, 4, 5};
  vector<int> v(nums, nums+sizeof(nums)/sizeof(int));
  vector< vector<int> > r = s.threeSum(v);
  for (int i=0; i<r.size(); ++i) {
    cout << '[';
    cout << r[i][0] << ' ' << r[i][1] << ' ' << r[i][2];
    cout << "]\n";
  }
}

#endif
