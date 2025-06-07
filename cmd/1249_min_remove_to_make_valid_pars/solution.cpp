#include <string>

class Solution {
 public:
  std::string minRemoveToMakeValid(std::string& s) const {
    int counter = 0;

    for (std::size_t i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        counter++;
      }
      if (s[i] == ')') {
        if (counter == 0) {
          s[i] = '*';
        } else {
          counter--;
        }
      }
    }

    for (int i = static_cast<int>(s.size()) - 1; i >= 0; i--) {
      if (counter > 0 && s[i] == '(') {
        s[i] = '*';
        counter--;
      }
    }

    std::size_t i = 0;
    for (std::size_t j = 0; j < s.size(); j++) {
      if (s[j] != '*') {
        s[i++] = s[j];
      }
    }

    s.resize(i);

    return s;
  }
};
