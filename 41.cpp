#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int firstMissingPositive(vector<int>& nums) {
    if (nums.empty()) return 1;
    const int n = nums.size();
    int nn = n;
    int i=0;
    int tmp;
    while (i<nn) {
      if (nums[i] <= 0 || nums[i] > n) {
        tmp = nums[nn-1];
        nums[nn-1] = nums[i];
        nums[i] = tmp;
        --nn;
      }
      else {
        ++i;
      }
    }
    
    //put correct nums into its pos when possible so that nums[0]=1, nums[1]=2, etc
    for (i=0; i<nn; ++i) {
      if (nums[i] != i+1 && nums[i] <= nn &&     nums[nums[i]-1] != nums[i]) {
        tmp = nums[nums[i]-1];
        nums[nums[i]-1] = nums[i];
        nums[i] = tmp;
        --i;
      }
    }

    for (i=0; i<nn; ++i)
      if (nums[i] != i+1) return i+1;
    return nn+1;
  }
};


#ifdef DEBUG

int main() {
  Solution s;
  int a[] = {1,2,0};
  vector<int> va(a, a+sizeof(a)/sizeof(int));
  int b[] = {3,4,-1,1};
  vector<int> vb(b, b+sizeof(b)/sizeof(int));
  int c[] = {7,8,9,11,12};
  vector<int> vc(c, c+sizeof(c)/sizeof(int));
  cout << s.firstMissingPositive(va) << '\n';
  cout << s.firstMissingPositive(vb) << '\n';
  cout << s.firstMissingPositive(vc) << '\n';
}

#endif
