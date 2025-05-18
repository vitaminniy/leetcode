#include <unordered_map>
#include <vector>

// You are given an integer array nums. You need to ensure that the elements in
// the array are distinct. To achieve this, you can perform the following
// operation any number of times:
//
// - Remove 3 elements from the beginning of the array. If the array has fewer
// than 3 elements, remove all remaining elements.
//
// Note that an empty array is
// considered to have distinct elements. Return the minimum number of operations
// needed to make the elements in the array distinct.
class Solution {
 public:
  int minimumOperations(const std::vector<int>& nums) {
    std::unordered_map<int, std::size_t> seen;
    seen.reserve(nums.size());

    for (int i = nums.size() - 1; i >= 0; i--) {
      if (seen.find(nums[i]) != seen.end()) {
        return i / 3 + 1;
      }

      seen[nums[i]]++;
    }

    return 0;
  }
};
