#include <vector>
#include <string>
#include <iostream>

using namespace std;


class Solution {
public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> ret;

    int n = words.size();
    int i=0, j;
    int count = 0;
    while (i<n) {
      count = words[i].size();
      for (j=i+1;
           j<n && count + words[j].size() + (j-i) <=maxWidth;
           count += words[j].size(), ++j);

      string s;
      if (j==n || j-i==1) {
        for (int k=i; k<j; ++k) {
          s.append(words[k]);
          if (k<j-1) s.append(1, ' ');
          else s.append(maxWidth - s.size(), ' ');
        }
      }
      else {
        int left = maxWidth - count;
        int fill = left / (j-i-1);
        int remain = left % (j-i-1);//spaces not evenly distributed
        for (int k=i; k<j; ++k) {
          s.append(words[k]);
          if (k < j-1) s.append(fill, ' ');
          if (remain) {s.append(1, ' '); --remain;}
        }
      }

      ret.push_back(s);
      i = j;
    }

    return ret;
  }
};



#ifdef DEBUG

int main() {
  string a[] = {"what", "must", "be", "achnowledgment", "shall", "be"};
  vector<string> va(a, a+sizeof(a)/sizeof(string));
  Solution s;
  vector<string> r = s.fullJustify(va, 20);
  for (int i=0; i<r.size(); ++i)
    cout << r[i] << '\n';
}

#endif
