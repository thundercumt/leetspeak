#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;


class Solution {
public:
  vector< vector<string> > groupAnagrams(vector<string>& strs) {
    vector< vector<string> > ret;
    if (strs.empty()) return ret;

    int n = strs.size();
    map<string, vector<string> > m;
    
    for (int i=0; i<n; ++i) {
      string repr = strs[i];
      sort(repr.begin(), repr.end());
      m[repr].push_back(strs[i]);
    }
    
    for (map<string, vector<string> >::iterator it = m.begin(), end = m.end();
         it != end; ++it) {
      ret.push_back(it->second);
    }

    return ret;
  }

  string encode(const string &s) {
    int chars[26] = {0};
    int n = s.size();
    for (int i=0; i<n; ++i) {
      ++chars[s[i]-'a'];
    }

    string r;
    for (int i=0; i<26; ++i) {
      if (chars[i]) {
        r.push_back(i + 'a');
        r.append(itoa(chars[i]));
      }
    }
    return r;
  }

  string itoa(int i) {
    string s;
    while (i) {
      s.push_back('0' + (i % 10));
      i /= 10;
    }
    return string(s.rbegin(), s.rend());
  }
};


#ifdef DEBUG

int main() {
  string a[] = {"eat", "tea", "tan", "ate", "nat" ,"bat"};
  vector<string> va(a, a+sizeof(a)/sizeof(string));
  Solution s;
  vector< vector<string> > ret = s.groupAnagrams(va);

  for (int i=0; i<ret.size(); ++i) {
    for (int j=0; j<ret[i].size(); ++j)
      cout << ret[i][j] << ' ';
    cout << '\n';
  }
}

#endif
