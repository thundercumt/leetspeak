#include <vector>

using namespace std;

class Solution {
public:
    vector< vector<int> > generate(int numRows) {
        vector< vector<int> > r;
        if (numRows<=0) return r;
        
        for (int i=1; i<=numRows; ++i) {
            vector<int> v;
            v.resize(i);
            v[0] = 1;
            v[i-1] = 1;
            for (int j=1; j<i-1; ++j) {
                v[j] = r[i-2][j-1] + r[i-2][j];
            }
            r.push_back(v);
        }
        
        return r;
    }
};

int main() {
    vector< vector<int> > r = Solution().generate(5);
    for (int i=0; i<r.size(); ++i) {
        for (int j=0; j<r[i].size(); ++j)
            printf("%d ", r[i][j]);
        printf("\n");
    }
}