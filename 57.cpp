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


class Solution {
public:
  vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    vector<Interval> ret;
    int n = intervals.size();
    bool merged = false;
    for (int i=0; i<n; ++i) {
      if (merged) {
        ret.push_back(intervals[i]);
        continue;
      }
      
      if (intervals[i].end < newInterval.start)
        ret.push_back(intervals[i]);
      else if (intervals[i].start > newInterval.end){
        ret.push_back(newInterval);
        merged = true;
        ret.push_back(intervals[i]);
      }
      else {
        newInterval.start = min(newInterval.start, intervals[i].start);
        newInterval.end = max(newInterval.end, intervals[i].end);
      }
    }

    if (!merged) ret.push_back(newInterval);
    return ret;
  }
};


#ifdef DEBUG

int main() {
  int a[][2] = {{1,2}, {3,5}, {6,7}, {8,10}, {12,16}};
  vector<Interval> v;
  for (int i=0; i<sizeof(a)/sizeof(a[0]); ++i)
    v.push_back(Interval(a[i][0], a[i][1]));
  Solution s;
  vector<Interval> ret = s.insert(v, Interval(4,8));
  for (int i=0; i<ret.size(); ++i)
    cout << ret[i].start << ' '<< ret[i].end << '\n';
}

#endif
