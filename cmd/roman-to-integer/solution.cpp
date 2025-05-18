#include <string>
#include <unordered_map>

class Solution {
 public:
  int romanToInt(std::string s) {
    static std::unordered_map<char, int> chars{
        {'I', 1},   {'V', 5},   {'X', 10},   {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000},
    };

    int result = 0;
    for (size_t i = 0; i < s.size() - 1; i++) {
      if (chars[s[i]] < chars[s[i + 1]]) {
        result -= chars[s[i]];
      } else {
        result += chars[s[i]];
      }
    }
    result += chars[s.back()];
    return result;
  }
};
