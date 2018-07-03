#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
  int removeElement(vector<int>& nums, int val) {
    int n = nums.size();
    if (n==0) return 0;

    int r=-1;
    for (int i=0; i<n; ++i) {
      if (val != nums[i]) {
        nums[++r] = nums[i];
      }
    }
    return r+1;
  }
};


#ifdef DEBUG

int main() {
  int a[] = {0, 1, 2, 2, 3, 0, 4, 2};
  vector<int> v(a, a+sizeof(a)/sizeof(int));
  Solution s;
  int n = s.removeElement(v, 2);

  for (int i=0; i<n; ++i) cout << v[i] << ' ';
  cout << '\n';
}

#endif
