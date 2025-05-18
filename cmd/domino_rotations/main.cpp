#include <iostream>

#include "rotate.cpp"

void runCase(std::vector<int> a, std::vector<int> b, int expected) {
  std::cout << "a:";
  for (auto it = a.begin(); it != a.end(); it++) {
    std::cout << " " << *it;
  }
  std::cout << std::endl;
  std::cout << "b:";
  for (auto it = b.begin(); it != b.end(); it++) {
    std::cout << " " << *it;
  }
  std::cout << std::endl;
  const auto result = Solution{}.minDominoRotations(a, b);
  std::cout << "expected: " << expected << "; actual: " << result << std::endl;
}

int main() {
  runCase({2, 1, 2, 4, 2, 2}, {5, 2, 6, 2, 3, 2}, 2);
  runCase({3, 5, 1, 2, 3}, {3, 6, 3, 3, 4}, -1);
}
