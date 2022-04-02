#include <vector>

class Solution {
 public:
  std::vector<int> twoSum(const std::vector<int>& numbers, int target) {
    const int size = numbers.size();
    for (int i = 0; i < size; i++) {
      auto diff = target - numbers[i];
      if (diff < numbers[i]) {
        // array is sorted in non-decreasing order and there are no elements
        // that are less than current.
        return {};
      }

      int left = i + 1;
      int right = size - 1;
      while (left <= right) {
        const auto mid = left + ((right - left) / 2);
        if (numbers[mid] == diff) {
          return {i + 1, mid + 1};
        }

        if (numbers[mid] > diff) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      }
    }

    return {};
  }
};
