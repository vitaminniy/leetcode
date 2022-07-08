#include <string>
#include <vector>

class Solution {
 public:
  bool isValid(const std::string& s) const {
    std::vector<char> stack;
    for (const auto c : s) {
      switch (c) {
        case '(':
        case '[':
        case '{':
          stack.push_back(c);
          break;
        case ')':
        case ']':
        case '}': {
          if (stack.empty()) {
            return false;
          }

          auto opener = GetMatching(c);
          if (opener != stack.back()) {
            return false;
          }
          stack.pop_back();
          break;
        }
      }
    }
    return stack.empty();
  }

 private:
  static char GetMatching(char c) {
    switch (c) {
      case ')':
        return '(';
      case ']':
        return '[';
      case '}':
        return '{';
    }
    throw std::runtime_error("invalid char");
  }
};
