#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    if(matrix.size()==0) return 0;

    int ans = 0, m = matrix.size(), n = matrix[0].size();
    vector<int> height(n,0); // height

    for(int i=0;i<m;i++){  
      for(int j=0;j<n;j++){
	if(matrix[i][j]=='0') { 
	  height[j] = 0;
	  continue;
	}
	height[j]++;

	for(int cur = j-1, pre = height[j]; cur>=0; cur--){
	  //cout << "pre=" << pre << " cur=" << cur << " height[cur]=" << height[cur] << " ans=" << ans << '\n';
	  if ( height[cur] == 0 ) break;
	  pre = min(pre,height[cur]);
	  ans = max(ans, (j-cur+1)*pre);
	}
	ans = max(ans, height[j]);
      }
    }
    return ans;
  }
};

#ifdef DEBUG
int main() {
  char a[][5] = {
    {'1','0','1','0','0'},
    {'1','0','1','1','1'},
    {'1','1','1','1','1'},
    {'1','0','0','1','0'}
  };

  const int r = sizeof(a) / sizeof(a[0]);
  const int c = sizeof(a[0]) / sizeof(a[0][0]);

  vector< vector<char> > v;

  for (int i=0; i<r; ++i) {
    v.push_back(vector<char>(c, 0));
    for (int j=0; j<c; ++j){
      v[i][j] = a[i][j];
    }
  }
  
  Solution s;
  cout << s.maximalRectangle(v) << '\n';
}
#endif
