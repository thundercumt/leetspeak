#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> v;
        int size = 1 << n;
        vector<int> s(size, 0);
        dfs(s, v, size, n, 0);
        return v;
    }

private:

    bool dfs(vector<int> &s, vector<int> &v, const int maxSize, const int m, int n) {
        if (v.size() == maxSize) {
            return true;
        }
        
        s[n] = 1;
        v.push_back(n);
        bool ok = false;
        for (int i=0; i<m; ++i) {
            int candidate = n ^ (1 << i);
            if (s[candidate] == 0) {
                ok |= dfs(s, v, maxSize, m, candidate);
            }
        }
        if (!ok) {
            s[n] = 0;
            s.pop_back();
        }
        return ok;
    }
};

int main() {
    Solution s;
    vector<int> v = s.grayCode(3);
    for (int i=0; i<v.size(); ++i) {
        printf("%d\n", v[i]);
    }
}