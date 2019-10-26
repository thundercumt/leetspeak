#include <algorithm>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector< vector<int> > subsetsWithDup(vector<int>& nums) {
        vector< vector<int> > v;
        sort(nums.begin(), nums.end());
        subset(v, nums, nums.size());
        return v;
    }
private:
    int subset(vector< vector<int> > &v, vector<int>& nums, int m) {
        if (m == 0) {
            v.push_back(vector<int>());
            return 1;
        }
        else {
            int lastAdded = subset(v, nums, m - 1);
            int count = v.size();
            int startFrom;
            if (m == 1 || nums[m-1] != nums[m-2]) {
                startFrom = 0;
            } else {
                startFrom = count - lastAdded;
            }
            for (int i=startFrom; i<count; ++i) {
                vector<int> copy(v[i]);
                copy.push_back(nums[m-1]);
                v.push_back(copy);
            }
            return count - startFrom;
        }
    }
};



int main() {
    int x[] = {1,2,2,3,3,3};
    vector<int> v(x, x + sizeof(x) / sizeof(x[0]));
    vector< vector<int> > r = Solution().subsetsWithDup(v);

    for (int i=0; i<r.size(); ++i) {
        for (int j=0; j<r[i].size(); ++j) {
            printf("%d ", r[i][j]);
        }
        printf("\n");
    }
}