#include <cassert>
#include <vector>

class Solution {
 public:
  // You are given two integer arrays nums1 and nums2, sorted in non-decreasing
  // order, and two integers m and n, representing the number of elements in
  // nums1 and nums2 respectively.
  //
  // Merge nums1 and nums2 into a single array sorted in non-decreasing order.
  //
  // The final sorted array should not be returned by the function, but instead
  // be stored inside the array nums1. To accommodate this, nums1 has a length
  // of m + n, where the first m elements denote the elements that should be
  // merged, and the last n elements are set to 0 and should be ignored. nums2
  // has a length of n.
  void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2,
             int n) const {
    assert(nums1.size() ==
           static_cast<std::size_t>(m) + static_cast<std::size_t>(n));
    assert(nums2.size() == static_cast<std::size_t>(n));
    assert(m + n >= 1);

    for (int i = m + n - 1; i >= 0; i--) {
      if (m > 0 && n > 0) {
        auto left = nums1[m - 1];
        auto right = nums2[n - 1];

        if (left >= right) {
          nums1[i] = left;
          m--;
        } else {
          nums1[i] = right;
          n--;
        }

        continue;
      }

      if (n == 0 && m > 0) {
        nums1[i] = nums1[m - 1];
        m--;

        continue;
      }

      if (m == 0 && n > 0) {
        nums1[i] = nums2[n - 1];
        n--;

        continue;
      }
    }
  }
};
