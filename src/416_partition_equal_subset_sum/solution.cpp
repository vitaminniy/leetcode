#include <cassert>
#include <numeric>
#include <vector>

// Given an integer array nums, return true if you can partition the array into
// two subsets such that the sum of the elements in both subsets is equal or
// false otherwise
class Solution {
  public:
    bool canPartition(std::vector<int>& nums) {
      assert(nums.size() >= 1);
      assert(nums.size() <= 200);

      const auto sum = std::accumulate(nums.begin(), nums.end(), 0);
      if (sum % 2 != 0) {
        return false;
      }


      auto target = sum/2;

      std::vector<bool> dp(static_cast<std::size_t>(target+1), false);
      dp[0] = true;

      for (const auto num : nums) {
        for (auto current = target; current >= num; current--) {
          auto idx = static_cast<std::size_t>(current);
          auto numidx = static_cast<std::size_t>(num);

          dp[idx] = dp[idx] || dp[idx - numidx];
          if (dp[static_cast<std::size_t>(target)]) {
            return true;
          }
        }
      }

      return dp[static_cast<std::size_t>(target)];
    }
};
