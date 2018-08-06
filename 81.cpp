#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  bool search(vector<int> &A, int target) {
    int lo =0, hi = A.size()-1;
    int mid = 0;
    while(lo<hi){
          mid=(lo+hi)/2;
          if(A[mid]==target) return true;
          if(A[mid]>A[hi]){
              if(A[mid]>target && A[lo] <= target) hi = mid-1;
              else lo = mid + 1;
          }else if(A[mid] < A[hi]){
              if(A[mid]<target && A[hi] >= target) lo = mid + 1;
              else hi = mid - 1;
          }else{
              hi--;
          }
          
    }
    return lo == hi && A[lo] == target;
  }
};

#ifdef DEBUG

int main() {
  int a[] = {2,5,6,0,0,1,2};
  int b[] = {1,2,1,1,1,1,1,1,1};
  vector<int> va(a, a+sizeof(a)/sizeof(a[0]));
  vector<int> vb(b, b+sizeof(b)/sizeof(b[0]));
  Solution s;
  cout << s.search(va, 0) << '\n';
  cout << s.search(va, 3) << '\n';
  cout << s.search(vb, 2) << '\n';
}

#endif
