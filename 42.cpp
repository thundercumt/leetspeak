#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
      if (height.size() <= 2) return 0;
      int l=0, r=height.size()-1;
      int hl = 0, hr = 0, h;
      //vector<int> sink(height.size(), 0);
      int sum = 0;
      
      while (l<=r) {
        hl = max(hl, height[l]);
        hr = max(hr, height[r]);
        h = min(hl, hr);

        if (height[l] <= h) {
          sum += h - height[l];
          //sink[l] = h-height[l];
          ++l;
        }
        else if (height[r] <= h) {
          sum += h - height[r];
          //sink[r] = h-height[r];
          --r;
        }
      }
      return sum;
    }
};


#ifdef DEBUG

int main() {
  Solution s;
  int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};
  vector<int> h(a, a+sizeof(a)/sizeof(int));

  cout << s.trap(h) << '\n';
}

#endif
