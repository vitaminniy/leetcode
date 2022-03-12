#include <iostream>
#include <iterator>
#include <ostream>
#include <vector>

/*
 * You are given an n x n 2D matrix representing an image, rotate the image by
 * 90 degrees (clockwise).
 *
 * You have to rotate the image in-place, which means you have to modify the
 * input 2D matrix directly. DO NOT allocate another 2D matrix and do the
 * rotation.
 *
 * Example 1:
 * Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [[7,4,1],[8,5,2],[9,6,3]]
 * | 1 2 3 |    | 7 4 1 |
 * | 4 5 6 | -> | 8 5 2 |
 * | 7 8 9 |    | 9 6 3 |
 *
 * Example 2:
 * Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
 * Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 *
 * Example 3:
 * Input: matrix = [[1]]
 * Output: [[1]]
 *
 * Example 4:
 * Input: matrix = [[1,2],[3,4]]
 * Output: [[3,1],[4,2]]
 *
 * Constraints:
 * * matrix.length == n
 * * matrix[i].length == n
 * * 1 <= n <= 20
 * * -1000 <= matrix[i][j] <= 1000
 *
 */
class Solution {
 public:
  void rotate(std::vector<std::vector<int>>& matrix) {
    const auto n = matrix.size();

    // | 1 2 3 |
    // | 4 5 6 |
    // | 7 8 9 |
    // {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}

    // transpose
    for (size_t i = 0; i < n; ++i) {
      for (size_t j = i; j < n; ++j) {
        std::swap(matrix[i][j], matrix[j][i]);
      }
    }

    // | 1 4 7 |
    // | 2 5 8 |
    // | 3 6 9 |
    //             {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}}
    // and we need {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}}
    // so swap? but how

    // rotate
    for (size_t i = 0; i < n; ++i) {
      for (size_t j = 0; j < n / 2; j++) {
        std::swap(matrix[i][j], matrix[i][n - j - 1]);
      }
    }
  }
};

void print(std::ostream& dst, const std::vector<std::vector<int>>& matrix) {
  for (const auto& row : matrix) {
    int i = 0;
    for (const auto& n : row) {
      if (i++ > 0) {
        dst << ' ';
      }
      dst << n;
    }
    dst << std::endl;
  }
}

int main() {
  std::vector<std::vector<int>> m{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  print(std::cout, m);
  Solution{}.rotate(m);
  print(std::cout, m);
  return 0;
}
