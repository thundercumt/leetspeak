#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
      int n =nums.size();
      return insertIdx(nums, n, 0, n-1, target);
    }

private:
  int insertIdx(vector<int>& v, int n, int l, int r, int target) {
    if (l>r) {
      if (r<0) return 0;
      if (l>=n) return n;
      if (v[r] > target) return r;
      else return l;
    }
    
    int i = (l+r) / 2;
    if (v[i] < target)
      return insertIdx(v, n, i+1, r, target);
    else if (v[i] > target)
      return insertIdx(v, n, l, i-1, target);
    else return i;
  }
};


#ifdef DEBUG

int main() {
  int a[] = {1,3,5,6};
  vector<int> v(a, a+sizeof(a)/sizeof(int));
  Solution s;
  cout << s.searchInsert(v, 5) << '\n';
  cout << s.searchInsert(v, 2) << '\n';
  cout << s.searchInsert(v, 7) << '\n';
  cout << s.searchInsert(v, 0) << '\n';
}

#endif
