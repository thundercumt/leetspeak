#include <vector>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> lessL(n, -1), lessR(n, n);
    int m = 0;
    
    for (int i=1; i<n; ++i) {
      int p;
      for(p=i-1; p>=0 && heights[p] >= heights[i]; p=lessL[p]);
      lessL[i] = p;
    }

    for (int i=n-2; i>=0; --i) {
      int p;
      for (p=i+1; p<n && heights[p] >= heights[i]; p=lessR[p]);
      lessR[i] = p;
    }

    for (int i=0; i<n; ++i) {
      m = max(m, heights[i] * (lessR[i] - lessL[i] - 1));
    }

    return m;
  }
};


#ifdef DEBUG

int main() {
  int a[] = {2,1,5,6,2,3};
  vector<int> va(a, a+sizeof(a)/sizeof(int));
  Solution s;
  cout << s.largestRectangleArea(va) << '\n';
}

#endif
