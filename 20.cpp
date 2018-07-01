#include <string>
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool isValid(string s) {
      vector<char> v;
      int n = s.size();
      char c;
      for (int i=0; i<n; ++i) {
        c = s[i];
        if (v.size()==0 || !match(v.back(), c)) {
          if (c=='(' || c=='[' || c=='{') v.push_back(c);
          else return false;
        }
        else v.pop_back();
      }
      return v.size() == 0; 
    }

private:
      bool match(char c1, char c2) {
        if (c1 > c2) return match(c2, c1);
        return c2-c1==1 || c2-c1==2;
      }
};


#ifdef DEBUG

int main() {
  Solution s;
  cout << s.isValid("{[]}") << '\n';
  cout << s.isValid("([)]") << '\n';
  cout << s.isValid("{}[]()") << '\n';
}

#endif
