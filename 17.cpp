#include <string>
#include <iostream>
#include <vector>

using namespace std;

string m[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};


class Solution {
public:
    vector<string> letterCombinations(string digits) {
      vector<string> v;
      if (digits=="") return v;
      string s(digits.size(), 0);
      combinate(v, digits, s, 0);
      return v;
    }

  void combinate(vector<string> &v, const string &digits, string &s, int idx) {
    if (idx==digits.size()) {
      v.push_back(s);
      return;
    }

    int d = digits[idx] - '0';
    string &ref = m[d];
    for (int i=0; i<ref.size(); ++i) {
      s[idx] = ref[i];
      combinate(v, digits, s, idx+1);
    } 
  }
};


#ifdef DEBUG

int main() {

  Solution s;

  vector<string> v = s.letterCombinations("2345");

  for (int i=0; i<v.size(); ++i)
    cout << v[i] << '\n';

}

#endif
