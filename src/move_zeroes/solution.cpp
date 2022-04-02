#include <cstdlib>
#include <vector>

class Solution {
 public:
  void moveZeroes(std::vector<int>& nums) const {
    if (nums.size() <= 1) {
      return;
    }

    auto last_non_zero_idx = 0;
    for (size_t i = 0; i < nums.size(); i++) {
      if (nums[i] != 0) {
        std::swap(nums[i], nums[last_non_zero_idx++]);
      }
    }
  }
};
