#include <iostream>
#include <vector>

#include "solution.cpp"

void solution(std::vector<std::vector<int>> &matrix, int target) {
  int m = matrix.size();
  int n = 0;
  if (m > 0 && matrix[0].size() > 0) {
    n = matrix[0].size();
  }

  std::cout << "Searching for " << target << " in " << m << "x" << n
            << " matrix" << std::endl;

  const auto result = Solution{}.searchMatrix(matrix, target);
  std::cout << "Result: " << result << std::endl;
}

int main() {
  {
    std::vector<std::vector<int>> matrix = {
        {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
    solution(matrix, 3);
  }
  {
    std::vector<std::vector<int>> matrix = {
        {1, 3, 5, 7}, {0, 11, 16, 20}, {23, 30, 34, 50}};
    solution(matrix, 13);
  }
  {
    std::vector<std::vector<int>> matrix = {};
    solution(matrix, 0);
  }
  {
    std::vector<std::vector<int>> matrix = {{1}};
    solution(matrix, 1);
  }
  {
    std::vector<std::vector<int>> matrix = {{1, 1}};
    solution(matrix, 2);
  }
  {
    std::vector<std::vector<int>> matrix = {{1}, {3}};
    solution(matrix, 0);
  }
  {
    std::vector<std::vector<int>> matrix = {{1}, {3}};
    solution(matrix, 2);
  }
  {
    std::vector<std::vector<int>> matrix = {{1}, {3}};
    solution(matrix, 4);
  }
}
