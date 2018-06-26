#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int n = s.size();

      int i = 0, j=0;
      int len;
      int max_len = 0;
      int m[256];

      while (i < n && j < n) {
        j = i;
        len = 0;
        fill(m, m+256, -1);

        while (j<n && m[s[j]] == -1) {
          m[s[j]] = j;
          ++len;
          ++j;
        }

        if (len > max_len) max_len = len;

        if (j < n) {
          i = m[s[j]] + 1;
        }
      }

      return max_len;
      
    }
};


#ifdef DEBUG
int main() {
  Solution s;

  printf("%d\n", s.lengthOfLongestSubstring("abcabcbb"));
  printf("%d\n", s.lengthOfLongestSubstring("xxx"));
  printf("%d\n", s.lengthOfLongestSubstring("abcdedcba"));

}
#endif
