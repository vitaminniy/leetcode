#include <cassert>
#include <limits>
#include <vector>

namespace {

bool non_decreasing(const std::vector<int>& nums) {
  auto min = std::numeric_limits<int>::min();

  for (const auto num : nums) {
    if (num >= min) {
      min = num;
    } else {
      return false;
    }
  }

  return true;
}

}  // namespace

class Solution {
 public:
  // Given an array nums, you can perform the following operation any number of
  // times:
  //
  // - Select the adjacent pair with the minimum sum in nums. If multiple such
  // pairs exist, choose the leftmost one.
  // - Replace the pair with their sum.
  //
  // Return the minimum number of operations needed to make the array
  // non-decreasing.
  // An array is said to be non-decreasing if each element is greater than or
  // equal to its previous element (if it exists).
  int minimumPairRemoval(std::vector<int>& nums) {
    assert(nums.size() >= 1);
    assert(nums.size() <= 50);

    int operations = 0;

    while (!non_decreasing(nums)) {
      const auto n = static_cast<int>(nums.size());

      auto minsum = std::numeric_limits<int>::max();
      auto minidx = -1;

      for (auto i = 0; i < n - 1; i++) {
        auto pairsum = nums[i] + nums[i + 1];
        if (pairsum < minsum) {
          minsum = pairsum;
          minidx = i;
        }
      }

      nums[minidx] = nums[minidx] + nums[minidx + 1];
      nums.erase(nums.begin() + minidx + 1);
      operations++;
    }

    return operations;
  }
};
