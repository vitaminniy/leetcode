#include <vector>

class Solution {
 public:
  std::vector<int> twoSum(const std::vector<int>& numbers, int target) {
    int left = 0;
    int right = numbers.size() - 1;
    while (left <= right) {
      auto sum = numbers[left] + numbers[right];
      if (sum == target) {
        return {++left, ++right};
      }

      if (sum < target) {
        left++;
      } else {
        right--;
      }
    }

    return numbers;
  }
};
