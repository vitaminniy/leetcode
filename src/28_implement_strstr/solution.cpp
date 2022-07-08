#include <string>

class Solution {
 public:
  int strStr(const std::string& haystack, const std::string& needle) const {
    if (needle.empty()) {
      return 0;
    }
    if (needle.size() > haystack.size()) {
      return -1;
    }

    std::size_t last_hay = 0;
    std::size_t needle_idx = 0;
    for (std::size_t i = 0; i < haystack.size(); i++) {
      if (haystack[i] == needle[needle_idx]) {
        needle_idx++;
      } else {
        i = last_hay++;
        needle_idx = 0;
      }

      if (needle_idx >= needle.size()) {
        return i - needle_idx + 1;
      }
    }

    return -1;
  }
};
