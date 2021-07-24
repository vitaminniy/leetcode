#include <iostream>
#include <vector>

#include "solution.cpp"

void solution(std::vector<std::vector<int>> &matrix, int target) {
  std::cout << "Searching for " << target << " in matrix:" << std::endl;
  for (const auto &v : matrix) {
    for (const auto i : v) {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }

  const auto result = Solution{}.searchMatrix(matrix, target);
  std::cout << "Result: " << result << std::endl;
  std::cout << std::endl;
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
