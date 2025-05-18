#include <algorithm>
#include <vector>

class Solution {
 public:
  // Indicates that matrix contains number.
  //
  // It's known that integers in each row are sorted in ascending order and
  // the first integer or each row is greater than the last integer of the
  // previos row.
  //
  // Thus we can use bisect algorithm on each first element of each row to
  // find vector that possibly has the number we're trying to guess also with
  // bisect.
  bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    const auto size = matrix.size();
    if (size == 0) {
      return false;
    }

    if (size == 1) {
      return std::binary_search(matrix[0].begin(), matrix[0].end(), target);
    }

    if (matrix[0].size() == 0) {
      return false;
    }

    int left = 0;
    int right = matrix.size() - 1;
    while (right >= left) {
      int mid = left + ((right - left) / 2);
      if (matrix[mid][0] == target) return true;

      if (matrix[mid][0] < target) {
        if (matrix[mid][matrix[mid].size() - 1] >= target) {
          return std::binary_search(matrix[mid].begin(), matrix[mid].end(),
                                    target);
        }
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    return false;
  }
};
