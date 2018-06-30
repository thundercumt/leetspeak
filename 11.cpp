#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
      int l=0, r=height.size()-1;
      int m = 0;

      while (l < r) {
        m = max(m, (r-l)*min(height[l], height[r]));

        if (height[l] < height[r]) ++l;
        else --r;
      }

      return m;
    }
};


#ifdef DEBUG

int main() {
  int a[] = {1,3,1,5,7,2,4,6,3};
  vector<int> h(a, a + sizeof(a)/sizeof(int));

  Solution s;
  cout << s.maxArea(h) << '\n';
}

#endif
