#include <string>
#include <vector>

class Solution {
 public:
  std::string longestPalindrome(const std::string& src) const {
    const auto n = static_cast<int>(src.size());
    std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));
    std::pair<int, int> result{0, 0};

    for (int i = 0; i < n; i++) {
      dp[i][i] = true;
    }

    for (int i = 0; i < n - 1; i++) {
      if (src[i] == src[i + 1]) {
        dp[i][i + 1] = true;
        result = {i, i + 1};
      }
    }

    for (int diff = 2; diff < n; diff++) {
      for (int i = 0; i < n - diff; i++) {
        int j = i + diff;
        if (src[i] == src[j] && dp[i + 1][j - 1]) {
          dp[i][j] = true;
          result = {i, j};
        }
      }
    }

    int i = result.first;
    int j = result.second;

    return src.substr(i, j - i + 1);
  }
};
