#include "solution.cpp"

#include <gtest/gtest.h>

TEST(Merge, Example1) {
  const std::vector<int> want = {1, 2, 2, 3, 5, 6};

  std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  int m = 3;
  std::vector<int> nums2 = {2, 5, 6};
  int n = 3;

  Solution{}.merge(nums1, m, nums2, n);

  ASSERT_EQ(want, nums1);
}

TEST(Merge, Example2) {
  const std::vector<int> want = {1};

  std::vector<int> nums1 = {1};
  int m = 1;
  std::vector<int> nums2 = {};
  int n = 0;

  Solution{}.merge(nums1, m, nums2, n);

  ASSERT_EQ(want, nums1);
}

TEST(Merge, Example3) {
  const std::vector<int> want = {1};

  std::vector<int> nums1 = {0};
  int m = 0;
  std::vector<int> nums2 = {1};
  int n = 1;

  Solution{}.merge(nums1, m, nums2, n);

  ASSERT_EQ(want, nums1);
}
