#include <algorithm>
#include <vector>

namespace {
bool search(const std::vector<std::vector<int>> &matrix, int l, int r,
            int target);

bool search(const std::vector<std::vector<int>> &matrix, int l, int r,
            int target) {
  if (l > r)
    return false;

  const auto mid = l + (r - l) / 2;
  const auto &vec = matrix[mid];

  if (vec[0] == target)
    return true;

  if (vec[0] > target)
    return search(matrix, l, mid - 1, target);

  if (vec[vec.size() - 1] >= target)
    return std::binary_search(vec.begin(), vec.end(), target);

  return search(matrix, mid + 1, r, target);
}
}; // namespace

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
  bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
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

    return search(matrix, 0, matrix.size() - 1, target);
  }
};
