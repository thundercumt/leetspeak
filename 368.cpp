#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> r;
        if (nums.size() == 0) return r;
        sort(nums.begin(), nums.end());

        int nsize = nums.size();
        vector<int> dp(nsize);
        vector<int> pre(nsize);

        int maxDp = 0, maxPre = -1;
        for (int i=0; i<nsize; ++i) {
            dp[i] = 1;//max num of divisibles of nums[i] is 1 (only nums[i] itself)
            pre[i] = -1;//assume its prefix does not exist

            for (int j=0; j<i; ++j) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        pre[i] = j;
                    }
                }
            }

            if (dp[i] > maxDp) {
                maxDp = dp[i];
                maxPre = i;
            }
        }

        while(maxPre != -1) {
            r. push_back(nums[maxPre]);
            maxPre = pre[maxPre];
        }
        reverse(r.begin(), r.end());
        return r;
    }
};