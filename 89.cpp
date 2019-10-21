#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> v;
        int size = 1 << n;
        for (int i=0; i<size; ++i) {
            v.push_back(i ^ (i >> 1));
        }
        return v;
    }
};

int main() {
    Solution s;
    vector<int> v = s.grayCode(3);
    for (int i=0; i<v.size(); ++i) {
        printf("%d\n", v[i]);
    }
}