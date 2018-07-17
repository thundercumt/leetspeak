#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
  bool searchMatrix(vector< vector<int> > &matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;

    int m = matrix.size(), n = matrix[0].size();

    int l=0, r = m-1;
    int mid;

    while (l<r) {
      mid = (l+r) / 2;
      if (matrix[mid][0] > target) r = mid - 1;
      else if (matrix[mid][0] < target) {
        if (matrix[mid+1][0] <= target) l = mid+1;
        else { l = mid; break;}
      }
      else return true;
    }

    vector<int> &row = matrix[l];
    l = 0, r = n-1;
    while (l<r) {
      mid = (l+r) / 2;
      if (row[mid] > target) r = mid-1;
      else if (row[mid] < target) l = mid+1;
      else return true;
    }

    return row[l] == target;
  }
};
