#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 0) return 0;
        
        vector<int> v(sz, 1);
        int maxLen = 1;
        for (int i=sz-2; i>=0; --i) {
            int maxCur = v[i];
            for (int j=i+1; j<sz; ++j) {
                if (nums[i] < nums[j]) {
                    maxCur = v[j] + 1 > maxCur ? v[j] + 1 : maxCur;
                }
            }
            v[i] = maxCur;
            maxLen = maxCur > maxLen ? maxCur : maxLen;
        }
        return maxLen;
    }
};


int main() {
    int a[] = {10,9,2,5,3,7,101,18};
    vector<int> v(a, a + sizeof(a)/sizeof(a[0]));
    int l = Solution().lengthOfLIS(v); 
    printf("%d\n", l);
}