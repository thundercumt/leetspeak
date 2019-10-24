#include <algorithm>
#include <vector>
#include <set>

using namespace std;

class SolutionOK {
public:
    vector< vector<int> > subsetsWithDup(vector<int>& nums) {
        set< vector<int> > s;
        vector< vector<int> > v;
        if (nums.size() == 0) return v;
        sort(nums.begin(), nums.end());
        subset(s, v, nums, nums.size());
        return v;
    }
private:
    void subset(set< vector<int> > &s, vector< vector<int> > &v, vector<int>& nums, int m) {
        if (m == 0) {
            vector<int> empty;
            s.insert(empty);
            v.push_back(empty);
        }
        else {
            subset(s, v, nums, m-1);
            int count = v.size();
            for (int i=0; i<count; ++i) {
                vector<int> copy(v[i]);
                copy.push_back(nums[m-1]);
                if (s.find(copy) == s.end()) {
                    s.insert(copy);
                    v.push_back(copy);
                }
            }
        }
    }
};


class Solution {
public:
    vector< vector<int> > subsetsWithoutDup(vector<int>& nums) {
        vector< vector<int> > v;
        v.push_back(vector<int>());
        int size = nums.size();
        if (size == 0) return v;

        sort(nums.begin(), nums.end());
        
        for (int i=0; i<size; ++i) {
            for (int j=0; j<v.size(); ++j) {
                vector<int> copy(v[j]);
                copy.push_back(nums[i]);
                v.push_back(copy);
            }
        }
        
        return v;
    }

    vector< vector<int> > subsetsWithDup(vector<int>& nums) {
        vector< vector<int> > v;
        if (nums.size() == 0) return v;
        sort(nums.begin(), nums.end());
        subset(v, nums, nums.size());
        return v;
    }
private:
    void subset(vector< vector<int> > &v, vector<int>& nums, int m) {
        if (m == 0) {
            v.push_back(vector<int>());
        }
        else {
            subset(v, nums, m-1);
            int count = v.size();
            for (int i=0; i<count; ++i) {
                vector<int> copy(v[i]);
                copy.push_back(nums[m-1]);
                v.push_back(copy);
            }
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