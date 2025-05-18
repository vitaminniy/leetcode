#include <string>
#include <vector>

class Solution {
 public:
  bool isValid(const std::string& s) const {
    std::vector<char> stack;
    for (const auto c : s) {
      if (c == '(' || c == '[' || c == '{') {
        stack.push_back(c);
        continue;
      }

      if (stack.empty()) {
        return false;
      }

      const auto opener = GetMatching(c);
      if (opener != stack.back()) {
        return false;
      }
      stack.pop_back();
    }
    return stack.empty();
  }

 private:
  static char GetMatching(char c) {
    if (c == ')') {
      return '(';
    }
    if (c == ']') {
      return '[';
    }
    return '{';
  }
};
