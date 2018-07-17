#include <vector>

using namespace std;

class Solution {
public:
  void sortColors(vector<int>& nums) {
    int zero=0, one=0, two=0;

    int n = nums.size();
    for (int i=0; i<n; ++i) {
      switch(nums[i]) {
      case 0:
        ++zero;
        break;
      case 1:
        ++one;
        break;
      case 2:
        ++two;
        break;
      default:
        break;
      }
    }

    int i=0;
    while (i < n) {
      if (zero) {
        nums[i] = 0;
        --zero;
      }
      else if (one) {
        nums[i] = 1;
        --one;
      }
      else if (two) {
        nums[i] = 2;
        --two;
      }

      ++i;
    }
  }
};
