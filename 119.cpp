#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v;
        if (rowIndex < 0) return v;
        
        v.resize(rowIndex+1, 0);
        
        int f,s;
        v[0] = 1;
        
        for (int i=1; i<=rowIndex; ++i) {
            f = 0;
            for (int j=0; j<=i; ++j) {
                s = v[j];
                v[j] = f + s;
                f = s;
            }
        }
        
        return v;
    }
};