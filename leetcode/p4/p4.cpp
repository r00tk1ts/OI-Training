#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
      nums1.swap(nums2);
    }
    int m = nums1.size(), n = nums2.size();
    if (n == 0) return 0.0;

    int iMin = 0, iMax = m;
    int half_length = (m + n + 1) / 2;
    while (iMin <= iMax) {
      int i = (iMin + iMax) / 2;
      int j = half_length - i;
      if (i < m && nums1[i] < nums2[j - 1]) {
        iMin = i + 1;
      } else if (i > 0 && nums1[i - 1] > nums2[j]) {
        iMax = i - 1;
      } else {
        int max_left, min_right;
        if (i == 0)
          max_left = nums2[j - 1];
        else if (j == 0)
          max_left = nums1[i - 1];
        else
          max_left = max(nums1[i - 1], nums2[j - 1]);

        if ((m + n) % 2 == 1) return max_left * 1.0;

        if (i == m)
          min_right = nums2[j];
        else if (j == n)
          min_right = nums1[i];
        else
          min_right = min(nums1[i], nums2[j]);

        return (min_right + max_left) / 2.0;
      }
    }
    return 0.0;
  }
};

int main() {
  vector<int> nums1{1, 2, 3};
  vector<int> nums2{2, 4, 5};
  cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;
  return 0;
}