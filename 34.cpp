#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ret(2,-1);
    if (nums.empty()) return ret;
    const int n = nums.size();

    int l=0, r=n-1, m;
    while(l<r) {cout << "1 " <<  l << ' ' << r << '\n';
      m = (l+r) / 2;
      if (nums[m] < target) l=m+1;
      else if (nums[m] > target) r = m-1;
      else r = m;
    }
    if (l >=n ) l=-1;
    else if (nums[l] != target) l = -1;
    ret[0] = l;
    cout << l << '\n';

    l = 0; r=n-1;
    while (l<r) {cout << "2 " << l << ' ' << r << '\n';
      m = (l+r) / 2;
      if (nums[m] < target) l = m+1;
      else if (nums[m] > target) r = m-1;
      else {
        if (r - l > 1) l = m;
        else if (nums[m] == nums[r]) l = m+1;
        else r = m;
      }
    }
    if (l >= n) l=-1;
    else if (nums[l]!=target) l=-1;
    ret[1] = l;
    cout << l << '\n';

    return ret;
  }

};


#ifdef DEBUG

int main() {
  Solution s;
  int a[] = {5,7,7,8,8,10};
  vector<int> v(a, a+sizeof(a)/sizeof(int));
  vector<int> r = s.searchRange(v, 8);
  for (int i=r[0]; i>=0 && i<=r[1]; ++i) cout << v[i] << ' ';
  cout << '\n';
  r = s.searchRange(v, 3);
  for (int i=r[0]; i>=0 && i<=r[1]; ++i) cout << v[i] << ' ';
  cout << '\n';
}

#endif
