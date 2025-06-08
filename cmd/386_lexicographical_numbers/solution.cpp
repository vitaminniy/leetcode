#include <vector>

class Solution {
 public:
  std::vector<int> lexicalOrder(int n) const {
    if (n <= 0) {
      return {};
    }

    const auto digits = countDigits(n);

    std::vector<int> result;
    result.reserve(n);

    dfs(result, 1, n, digits);

    return result;
  }

 private:
  void dfs(std::vector<int>& carry, int current, int n, int ndigits) const {
    if (current > n) {
      return;
    }

    carry.push_back(current);

    if (ndigits > 1) {
      dfs(carry, current * 10, n, ndigits - 1);
    }

    if (current % 10 == 9) {
      return;
    }

    dfs(carry, current + 1, n, ndigits);
  }

  int countDigits(int n) const {
    if (n == 0) {
      return 1;
    }

    int result = 0;
    while (n > 0) {
      n = n / 10;
      result++;
    }

    return result;
  }
};
