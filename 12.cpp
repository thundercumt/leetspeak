#include <iostream>
#include <string>

using namespace std;

char* one[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
char* ten[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
char* hun[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
char* thou[] = {"", "M", "MM", "MMM" };

class Solution {
public:
    string intToRoman(int num) {
      string s;
      int t;

      s.append(thou[num / 1000]);

      s.append(hun[num / 100 % 10]);

      s.append(ten[num / 10 % 10]);

      s.append(one[num % 10]);
      
      return s;
    }
};


#ifdef DEBUG

int main() {

  Solution s;

  cout << s.intToRoman(3) << '\n';
  cout << s.intToRoman(4) << '\n';
  cout << s.intToRoman(9) << '\n';
  cout << s.intToRoman(58) << '\n';
  cout << s.intToRoman(1994) << '\n';
}

#endif
