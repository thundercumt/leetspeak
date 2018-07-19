#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    int i, ic=1;
    int j=1;

    int n = nums.size();
    for (i=1; i<n; ++i) {
      if (nums[i] == nums[i-1]) {
        if (ic < 2) {
          nums[j++] = nums[i];
          ++ic;
        }
      }
      else {
        nums[j++] = nums[i];
        ic = 1;
      }
    }

    return j;
  }
};


#ifdef DEBUG

int main() {

  int a[] = {1,1,1,2,2,3};
  vector<int> va(a, a+sizeof(a)/sizeof(int));
  Solution s;
  printf("%d\n", s.removeDuplicates(va));
}

#endif
