#include <string>
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
  int strStr(string haystack, string needle) {
    if (needle.size() == 0) return 0;
    if (haystack.size() < needle.size()) return -1;
    return naive(haystack, needle);
  }

  int naive(const string& t, const string& p) {
    int n = t.size();
    int m = p.size();
    for (int i=0; i<=n-m; ++i) {
      int j;
      for (j=0; j<m; ++j) {
        if (t[i+j] != p[j]) break;
      }
      if (j==m) return i;
    }
    return -1;
  }

  int kmp(const string& t, const string& p) {
    int n = t.size();
    int m = p.size();
    vector<int> d(m,0);
    init(d, p);

    int k = 0;
    for (int i=0; i<n; ++i) {
      while (k && p[k] != t[i]) k = d[k];

      if (p[k] == t[i]) k = k+1;
      if (k == m) {
        return i-m+1;
      }
    }
    return -1;
  }

private:
  //vector<int> d means if p[0..k-1] matches but fails at p[k] what is the next length k1 that matches p[0..k1-1] == p[k-k1, k-1]
  void init(vector<int> &d, const string& p) {
    int m = p.size();
    d[0] = 0;
    d[1] = 0;
    int k = 0;
    for (int i=2; i<m; ++i) {
      while(k && p[k] != p[i-1]) k = d[k];
      if (p[k] == p[i-1]) k = k+1;
      d[i] = k;
    }
  }
};


#ifdef DEBUG

int main() {
  Solution s;
  cout << s.strStr("hello", "ll") << '\n';
  cout << s.strStr("aaaaa", "bba") << '\n';
  cout << s.strStr("abacbacd", "bacd") << '\n';
  cout << s.strStr("mississippi", "issip") << '\n';
}

#endif
