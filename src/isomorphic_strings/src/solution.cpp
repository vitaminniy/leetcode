#include <string>
#include <vector>

class Solution {
 public:
  bool isIsomorphic(const std::string& source, const std::string& target) {
    if (source.size() != target.size()) {
      return false;
    }

    std::vector<char> source_chars(256, 0);
    std::vector<char> target_chars(256, 0);

    for (size_t i = 0; i < source.size(); ++i) {
      // wrong mapping
      if (source_chars[source[i]] != target_chars[target[i]]) {
        return false;
      }

      source_chars[source[i]] = target[i];
      target_chars[target[i]] = target[i];
    }

    return true;
  }
};
