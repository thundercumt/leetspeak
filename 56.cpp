#include <vector>
#include <iostream>

using namespace std;


#ifdef DEBUG
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};
#endif

bool interval_less(const Interval &a, const Interval &b) {
  return a.end < b.start || a.start < b.start;
}

class Solution {
public:
  vector<Interval> merge(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), interval_less);
    vector<Interval> ret;
    int n = intervals.size(); 
    if (!n) return ret;
    ret.push_back(intervals[0]);
    int last = 0;
    for (int i=1; i<n; ++i) {
      if (ret[last].end >= intervals[i].start)
        ret[last].end = max(ret[last].end, intervals[i].end);
      else {
        ret.push_back(intervals[i]);
        ++last;
      }
    }

    return ret;
  }
};



#ifdef DEBUG

int main() {
  int a[][2] = {{1,3}, {2,6}, {8,10}, {15,18}};
  vector<Interval> v;
  for (int i=0; i<sizeof(a)/sizeof(a[0]); ++i) {
    v.push_back(Interval(a[i][0], a[i][1]));
  }

  Solution s;
  vector<Interval> r = s.merge(v);
  for (int i=0; i<r.size(); ++i)
    cout << '[' << r[i].start << ',' << r[i].end << "]\n";
}

#endif
