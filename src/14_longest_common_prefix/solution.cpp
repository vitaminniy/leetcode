#include <string>
#include <vector>

class Solution {
 public:
  std::string longestCommonPrefix(const std::vector<std::string>& strs) const {
    if (strs.empty()) {
      return "";
    }

    if (strs.size() == 1) {
      return strs[0];
    }

    for (std::size_t i = 0; i < strs[0].size(); i++) {
      const auto c = strs[0][i];
      for (std::size_t j = 1; j < strs.size(); j++) {
        if (strs[j].size() <= i || strs[j][i] != c) {
          return strs[0].substr(0, i);
        }
      }
    }

    return strs[0];
  }
};
