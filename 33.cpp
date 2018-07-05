#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int search(vector<int>& nums, int target) {
    if (nums.empty()) return -1;
    const int n = nums.size();
    int p = pivot(nums, 0, n-1);
    int a = qsearch(nums, 0, p-1, target);
    if (a!=-1) return a;
    a = qsearch(nums, p, n-1, target);
    return a;
    
  }

  int pivot(vector<int>& v, int ll, int rr) {
    int m;
    int l=ll, r=rr;
    while(v[l] > v[r]) {
      m = (l + r) / 2;
      if (l<m && m<r && v[m-1] > v[m] && v[m+1] > v[m]) return m;
      else if (v[m] > v[r]) l=m+1;
      else if (v[m] < v[r]) r = m-1;
      //no duplicates in v else {}
    }
    //pivot not stable, should check if it is the beginning of 2nd part
    if (l>=ll && l+1 <= rr && v[l+1] < v[l]) return l+1;
    return l;
  }

  int qsearch(vector<int> &v, int ll, int rr, int target) {
    int m;
    int l=ll, r=rr;
    while (l<=r) {
      m = (l+r) / 2;
      if (v[m] > target) r = m - 1;
      else if (v[m] < target) l = m + 1;
      else return m;
    }
    if (l > rr) return -1;
    else if (v[l] == target) return l;
    return -1;
  }
};


#ifdef DEBUG

int main() {
  int a[] = {6,7,8,1,2,3,4,5};
  vector<int> v(a, a+sizeof(a)/sizeof(int));
  Solution s;
  cout << s.search(v, 6) << '\n';
  cout << s.search(v, 3) << '\n';

}

#endif
