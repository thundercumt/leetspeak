#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    int r=1;
    int last = nums[0];
    for (int i=1; i<n; ++i) {
      if (nums[i] > last) {
        nums[r++] = nums[i];
        last = nums[i];
      }
    }
    return r;
  }
};


#ifdef DEBUG

int main() {
  int a[] = {1,1,2,2,3,4,5,5,6,7};
  vector<int> v(a, a+sizeof(a)/sizeof(int));

  Solution s;
  int n = s.removeDuplicates(v);
  for(int i=0; i<n; ++i) cout << v[i] << ' ';
  cout << '\n';

}

#endif
