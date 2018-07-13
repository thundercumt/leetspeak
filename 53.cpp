#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    return maxSubArrayDP(nums);
  }

private:

  int maxSubArrayON(vector<int> &v) {
    if (v.empty()) return INT_MIN;
    int maxsum = v[0], sum = v[0];
    int n = v.size();
    for (int i=1; i<n; ++i) {
      if (sum < 0) sum = max(v[i], sum);
      else sum += v[i];
      maxsum = max(maxsum, sum);
    }
    return maxsum;
  }

  int maxSubArrayDP(vector<int> &v) {
    int n = v.size();
    vector<int> dp(v.size(), 0);
    dp[0] = v[0];
    int m = v[0];
    for (int i=1; i<n; ++i) {
      dp[i] = max(dp[i-1]+v[i], v[i]);
      m = max(dp[i], m);
    }
    return m;
  }
};



#ifdef DEBUG

int main() {
  int a[] = {-2,-1,1, 3, -1, 5, -6, 7};
  vector<int> va(a, a+sizeof(a)/sizeof(int));
  Solution s;
  cout << s.maxSubArray(va) << '\n';
}

#endif
