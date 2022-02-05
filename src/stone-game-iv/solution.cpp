#include <vector>

class Solution {
public:
  bool winnerSquareGame(int n) const {
    if (n == 1) {
      return true;
    }
    if (n == 2) {
      return false;
    }

    std::vector<bool> memo(n + 1);
    for (int i = 0; i < n + 1; i++) {
      for (int k = 1; k * k <= i; k++) {
        if (memo[i - k * k] == false) {
          memo[i] = true;
          break;
        }
      }
    }

    return memo[n];
  }
};
