#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  string minWindow(string s, string t) {
    vector<int> m(128, 0);
    for (int i=0; i<t.size(); ++i) ++m[t[i]];
    int counter = t.size(), beg = 0, end = 0, d = INT_MAX, start = 0;

    while (end < s.size()) { 
      if (m[s[end++]]-- > 0) --counter;
      while (counter==0) {
        if (end - beg < d) d = end - (start = beg);
		if (m[s[beg++]]++ == 0) ++counter;
      }
    }

    return d == INT_MAX ? "" : s.substr(start, d);
  }
};

#ifdef DEBUG

int main() {
    Solution s;
    cout << s.minWindow("abc", "d") << '\n';
    cout << s.minWindow("", "he") << '\n';
    cout << s.minWindow("abc", "") << '\n';
    cout << s.minWindow("adobecodebanc", "abc") << '\n';
    cout << s.minWindow("abccba", "abc") << '\n';
    cout << s.minWindow("aabbcc", "abc") << '\n';
	cout << s.minWindow("aa", "aa") << '\n';
}

#endif
