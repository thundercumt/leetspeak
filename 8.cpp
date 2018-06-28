#include <iostream>
#include <cctype>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
      long t=0;
      long l;
      int i=0;
      int n = str.size();
      int sign = 1;
      int c;

      while (str[i] == ' ') ++i;

      if (str[i] == '+') {
        ++i;
      }
      else if (str[i] == '-') {
        sign = -1;
        ++i;
      }
      
      for (; i<n && isdigit(str[i]); ++i) {
        c = sign==1 ? str[i]-'0' : '0'-str[i];
        l = t;
        t = t * 10 + c;

        if (sign==1 && t > INT_MAX) {
          t = INT_MAX;
          break;
        }
        else if (sign==-1 && t < INT_MIN) {
          t = INT_MIN;
          break;
        }
      }

      return t;
    }
};


#ifdef DEBUG

int main() {
  Solution s;
  cout << s.myAtoi("42") << '\n';
  cout << s.myAtoi("-42") << '\n';
  cout << s.myAtoi("+42") << '\n';
  cout << s.myAtoi("4193 hello world") << '\n';
  cout << s.myAtoi("hello world42") << '\n';
  cout << s.myAtoi("-91283472332") << '\n';
  cout << s.myAtoi("91283472332") << '\n';
}

#endif
