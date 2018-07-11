#include <deque>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int jump(vector<int>& nums) {
    return greedy(nums);
  }
private:

  struct item {
    int idx;
    int step;
    int cnt;
    item(int a, int b, int c) : idx(a), step(b), cnt(c) {}
  };

  
  int bfs(const vector<int> &v) {
    int n = v.size();

    if (!n) return 0;
    if (n==1) return 0;

    deque<item> q;
    vector<bool> visited(v.size(), false);

    q.push_back(item(0, v[0], 0));
    visited[0] = true;
    
    while (!q.empty()) {
      item it = q.front();
      q.pop_front();
      int i = it.idx;
      int rng = it.step;
      int count = it.cnt;

      for (int j=1; j<=rng && i+j < n; ++j) {
        //cout << i+j << '\n';
        if (!visited[i+j]) {
          if (i+j == n-1) return count+1;
          visited[i+j] = true;
          q.push_back(item(i+j, v[i+j], count+1));
        }
      }
    }
    
    return -1;
  }


  int dp(const vector<int> &v) {
    int n = v.size();
    vector< vector<int> > dist(n, vector<int>(n, 999999));
    for (int i=n-2; i>=0; --i) {
      for (int j=n-1; j>=i; --j) {
        if (v[i] + i >= n-1) dist[i][j] = 1;
        else if (j > i) dist[i][j] = dist[i+1][j];
        else if (v[i]>0) dist[i][j] = dist[i+1][i+v[i]] + 1;
      }
    }
    return dist[0][0];
  }

  int greedy(const vector<int> &v) {
    const int n = v.size();

    if (n<=1) return 0;
    
    vector<int> dist(n, INT_MAX);

    int i = 0;
    int reach = 0;
    while (i<n) {
      if (i + v[i] > reach) {
        for (int j=reach-i; i+j<n && j<=v[i]; ++j) {
          dist[i+j] = min(dist[i+j], i);
        }
        reach = i + v[i];
      }
      ++i;
    }
    
    int steps = 0;
    int idx = n-1;
    while (idx) {
      idx = dist[idx];
      ++steps;
    }

    return steps;
  }
};


#ifdef DEBUG

int main() {
  int a[] = {1,2,3,4,5};
  vector<int> va(a, a+sizeof(a)/sizeof(int));
  Solution s;
  cout << s.jump(va) << '\n';
  
  vector<int> vb(36002, 0);
  for (int i=0;i<36000; ++i) vb[i] = 36000-i;
  vb[36000] = 1;
  cout << s.jump(vb) << '\n';
}

#endif
