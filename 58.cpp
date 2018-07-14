#include <string>
#include <iostream>

using namespace std;


class Solution {
public:
  int lengthOfLastWord(string s) {
    int len = 0;
    bool word = false;
    int n = s.size();
    for (int i=0; i<n; ++i) {
      if (s[i] != ' ') {
        if (!word) {
          len = 1;
          word = true;
        }
        else ++len;
      }
      else word = false;
    }

    return len;
  }
};


#ifdef DEBUG
int main() {
  Solution s;
  cout << s.lengthOfLastWord("") << '\n';
  cout << s.lengthOfLastWord("abc") << '\n';
  cout << s.lengthOfLastWord("aa abca") << '\n';
  cout << s.lengthOfLastWord("a aa a  ") << '\n';
}
#endif
