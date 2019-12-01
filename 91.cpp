#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0) return 0;
        vector<int> dp(n,0);
        dp[0] = valid(s[0]) ? 1 : 0;
        if (n==1) return dp[0];

        if (!dp[0]) return 0;
        if (valid(s[1])) {
            dp[1] += dp[0];
        }
        if (valid(s[0], s[1])) {
            dp[1] += 1;
        }

        for (int i=2; i<n; ++i) {
            if (!dp[i-1]) return 0;

            if (valid(s[i])) {
                dp[i] += dp[i-1];
            }

            if (valid(s[i-1], s[i])) {
                dp[i] += dp[i-2];
            }
        }

        return dp[n-1];
    }
private:
    inline bool valid(char c1, char c2) {
        return c1 == '1' ||
            (c1 == '2' && c2 >= '0' && c2 <= '6');
    }

    inline bool valid(char c) {
        return c >= '1' && c <= '9';
    }
};

int main() {
    string s = "101011";
    printf("%d\n", Solution().numDecodings(s));
}