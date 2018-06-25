#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

struct elem {
  elem(int ipos, int iv) : pos(ipos), v(iv) {}
  int pos;
  int v;
};

int compare_elem (const elem& a, const elem& b) {
  return a.v < b.v;
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      vector<elem> v;
      vector<int> ret;
      int n = nums.size();
      for (int i=0; i<n; ++i) {
        v.push_back(elem(i, nums[i]));
      }

      sort(v.begin(), v.end(), compare_elem);

      int l=0, h=v.size()-1;
      long s = 0;
      while (l < h) {
        s = v[l].v;
        s += v[h].v;
        if (s > target) --h;
        else if (s < target) ++l;
        else {
          if (v[l].pos < v[h].pos) {
            ret.push_back(v[l].pos);
            ret.push_back(v[h].pos);
          }
          else {
            ret.push_back(v[h].pos);
            ret.push_back(v[l].pos);
          }
          break;
        }
      }

      return ret;
    }
};

#ifdef DEBUG
int main() {
  vector<int> nums;
  nums.push_back(5);
  nums.push_back(11);
  nums.push_back(7);
  nums.push_back(4);
  nums.push_back(1);
  nums.push_back(3);
  nums.push_back(5);

  vector<int> ret = Solution().twoSum(nums, 10);
  printf("%d %d\n", ret[0], ret[1]);
}
#endif
