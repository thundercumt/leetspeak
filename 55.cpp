#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  bool canJump(vector<int>& nums) {
    if (nums.empty()) return false;
    int n = nums.size();
    if (n==1) return true;
    int i, reach;
    vector<int> v(n, INT_MAX);
    for (i=0; i<=v[0]; ++i) v[i] = 0;
    reach = nums[0];
    i = 1;
    //loop invariant reach >= i
    while (i<n) {
      if (i>reach) return false;
      for (int j=reach-i+1; i+j<n && j<=nums[i]; ++j) 
        v[i+j] = min(v[i+j], i);
      reach = max(reach, i + nums[i]);
      ++i;
    }

    return i==n;
  }
};


#ifdef DEBUG

int main() {
  int a[] = {2,3,1,1,4};
  vector<int> va(a, a+sizeof(a)/sizeof(int));
  Solution s;
  cout << s.canJump(va) << '\n';
  int b[] = {3,2,1,0,4};
  vector<int> vb(b, b+sizeof(b)/sizeof(int));
  cout << s.canJump(vb) << '\n';
}

#endif
