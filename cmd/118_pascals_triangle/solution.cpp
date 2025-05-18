#include <vector>

class Solution {
 public:
  // Given an integer numRows, return the first numRows of Pascal's triangle.
  std::vector<std::vector<int>> generate(int numRows) const {
    if (numRows <= 0) {
      return {};
    }

    std::vector<std::vector<int>> result(numRows, std::vector<int>());
    result[0] = {1};

    for (auto i = 1; i < numRows; i++) {
      result[i] = std::vector<int>(i + 1, 1);

      for (auto j = 1; j < i; j++) {
        result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
      }
    }

    return result;
  }
};
