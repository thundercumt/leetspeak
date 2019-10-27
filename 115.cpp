#include <string>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int ssize = s.size(), tsize = t.size();
        if (ssize < tsize) return 0;
        if (s == t) return 1;

        long long int dp[ssize+1][tsize+1];
        memset(dp, 0, sizeof(dp));

        for (int i=0; i<=ssize; ++i) {
            dp[i][0] = 1;
        }

        for (int i=1; i<=tsize; ++i) {
            dp[0][i] = 0;
        }

        for (int i=1; i<=ssize; ++i) {
            for (int j=1; j<=tsize; ++j) {
                if (s[i-1] == t[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[ssize][tsize];
    }
};


int main() {
    string s = "aabdbaabeeadcbbdedacbbeecbabebaeeecaeabaedadcbdbcdaabebdadbbaeabdadeaabbabbecebbebcaddaacccebeaeedababedeacdeaaaeeaecbe";
    string t = "bddabdcae";
    printf("%d\n", Solution().numDistinct(s,t));
}