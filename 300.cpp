#include <vector>

using namespace std;

class SolutionOn2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 0) return 0;
        
        vector<int> v(sz, 1);
        int maxAll = 1;
        for (int i=sz-2; i>=0; --i) {
            int maxCur = v[i];
            for (int j=i+1; j<sz; ++j) {
                if (nums[i] < nums[j]) {
                    maxCur = v[j] + 1 > maxCur ? v[j] + 1 : maxCur;
                }
            }
            v[i] = maxCur;
            maxAll = maxCur > maxAll ? maxCur : maxAll;
        }
        return maxAll;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) 
            return 0;
        
        vector<int> v;
        int n = nums.size();
        for (int i=0; i<n; ++i) {
            vector<int>::iterator it = lower_bound(v.begin(), v.end(), nums[i]);
            if (it == v.end()) {
                v.push_back(nums[i]);
            } else {
                *it = nums[i];
            }
        }
        return v.size();
    }
};

int main() {
    int a[] = {2,3,7,1,4,8};
    vector<int> v(a, a + sizeof(a)/sizeof(a[0]));
    int l = Solution().lengthOfLIS(v); 
    printf("%d\n", l);
}