#include <vector>

class Solution {
 public:
  std::vector<int> lexicalOrder(int n) const {
    if (n <= 0) {
      return {};
    }

    std::vector<int> result;
    result.reserve(n);

    for (auto i = 1; i <= 9; i++) {
      dfs(result, i, n);
    }

    return result;
  }

 private:
  void dfs(std::vector<int>& carry, int current, int n) const {
    if (current > n) {
      return;
    }

    carry.push_back(current);
    for (auto i = 0; i <= 9; i++) {
      dfs(carry, (current * 10) + i, n);
    }
  }
};
