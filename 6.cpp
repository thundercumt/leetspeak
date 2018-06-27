#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    string convert(string s, int numRows) {
      if (numRows <= 1) return s;
      
      vector<char> v[numRows];
      vector<int> insert[numRows];
      bool switcher[numRows];
      int n = s.size();
      bool fwd = true;
      int r = 0;
      int ins;

      for (int i=0; i<numRows; ++i) {
        if (i==0 || i==numRows-1) {
          insert[i].push_back(numRows - 2);
        }
        else {
          insert[i].push_back(numRows - 2 - i);
          insert[i].push_back(i - 1);
          switcher[i] = true;
        }
      }

      for (int i=0; i<n; ++i) {
        if (r==-1 && !fwd) {
          r = 1;
          fwd = true;
        }
        else if (r==numRows && fwd) {
          r = numRows - 2;
          fwd = false;
        }

        //first numRows characters are put in a column
        if (i < numRows) {
          v[r].push_back(s[i]);
        }
        else {
          if (r==0 || r==numRows-1) {
            ins = insert[r][0];
          }
          else {
            if (switcher[r]) {
              ins = insert[r][0];
              switcher[r] = false;
            }
            else {
              ins = insert[r][1];
              switcher[r] = true;
            }
          }

          //for (int j=0; j<ins; ++j) v[r].push_back(' ');
          v[r].push_back(s[i]);
        }
        
        if (fwd) ++r;
        else --r;
      }

      string ret;
      for (int i=0; i<numRows; ++i) {
        for (int j=0; j<v[i].size(); ++j) {
          //cout << v[i][j];
          ret.push_back(v[i][j]);
        }
        //cout << '\n';
      }
      return ret;

    }
};


#ifdef DEBUG

int main() {
  Solution s;
  cout << s.convert("PAYPALISHIRING", 4) << "\n";
}

#endif
