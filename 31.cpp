#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
  void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    if (n==1) return;
    int i = n-1;
    int j = i;
    while(i>0 && nums[i-1] >= nums[i]) --i;

    if (i > 0) {
      reverse(nums, i, j);
      int t = i-1;
      while(nums[t] >= nums[i]) ++i;
      j = nums[t];
      nums[t] = nums[i];
      nums[i] = j;
      return;
    }
    else {
      reverse(nums, 0, n-1);
    }
  }
private:
  void reverse(vector<int> &v, int i, int j) {
    int t;
    while(i < j) {
      t = v[i];
      v[i] = v[j];
      v[j] = t;
      ++i;
      --j;
    }
  }
};


#ifdef DEBUG

void output(const vector<int> &v) {
  for (int i=0; i<v.size(); ++i) cout << v[i] << ' ';
  cout << '\n';
}

int main() {
  int a[] = {1,1,3,3};
  vector<int> v(a, a+sizeof(a)/sizeof(int));
  Solution s;

  for (int i=0; i<24; ++i) {
    output(v);
    s.nextPermutation(v);
  }

}


#endif
