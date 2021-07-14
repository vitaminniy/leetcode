#include <vector>

class Solution final {
public:
  double findMedianSortedArrays(const std::vector<int> &nums1,
                                const std::vector<int> &nums2) const {
    if (nums1.empty() && nums2.empty()) {
      return 0;
    }

    if (nums1.empty() && !nums2.empty()) {
      return findMedian(nums2);
    }

    if (!nums1.empty() && nums2.empty()) {
      return findMedian(nums1);
    }

    const auto size = nums1.size() + nums2.size();

    std::vector<int> nums;
    nums.reserve(size);

    size_t i = 0;
    size_t j = 0;

    while (i < nums1.size() && j < nums2.size()) {
      if (nums1[i] <= nums2[j]) {
        nums.push_back(nums1[i]);
        i++;
      } else {
        nums.push_back(nums2[j]);
        j++;
      }
    }

    for (; i < nums1.size(); ++i) {
      nums.push_back(nums1[i]);
    }

    for (; j < nums2.size(); ++j) {
      nums.push_back(nums2[j]);
    }

    return findMedian(nums);
  }

private:
  double findMedian(const std::vector<int> &nums) const {
    const auto size = nums.size();
    if (size % 2 == 1) {
      return nums[size / 2];
    }

    const auto mid = size / 2;
    const auto sum = nums[mid - 1] + nums[mid];
    return static_cast<double>(sum) / 2;
  }
};
