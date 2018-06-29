#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      int k = nums1.size() + nums2.size();
      if (k & 1) {
        return findIth(nums1, 0, nums1.size(),
                       nums2, 0, nums2.size(), k/2);
      }
      else {
        return (findIth(nums1, 0, nums1.size(),
                        nums2, 0, nums2.size(), k/2-1)
                + findIth(nums1, 0, nums1.size(),
                          nums2, 0, nums2.size(), k/2))
          / 2.0;
      }
    }

  /* valid range [s, e) */
  double findIth(vector<int>& nums1, int s1, int e1,
                 vector<int>& nums2, int s2, int e2,
                 int i) {
    if (e1 - s1 > e2 - s2)
      return findIth(nums2, s2, e2, nums1, s1, e1, i);
    if (s1 >= e1) return nums2[s2 + i];
    if (i == 0) return min(nums1[s1], nums2[s2]);

    int i1 = min(i/2, e1 - s1 - 1);
    int i2 = i - i1 - 1;

    int ai1 = s1 + i1;
    int ai2 = s2 + i2;

    int v1 = nums1[ai1];
    int v2 = nums2[ai2];

    if (v1 < v2) {
      return findIth(nums1, ai1+1, e1, nums2, s2, s2+i2+1, i-i1-1);
    }
    else if (v1 > v2) {
      return findIth(nums1, s1, s1+i1+1, nums2, ai2+1, e2, i-i2-1);
    }
    else {
      return v1;
    }
  }
};


#ifdef DEBUG

int main() {
  int nums1[] = {1,3,5,7,9};
  int nums2[] = {2,4,6,8,10};
  vector<int> v1(nums1, nums1+5);
  vector<int> v2(nums2, nums2+5);
  Solution s;
  for (int i=0; i<10; ++i) {
    cout << s.findIth(v1, 0, 5, v2, 0, 5, i) << "\n\n";
  }
}

#endif
