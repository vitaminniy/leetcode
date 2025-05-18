#include <algorithm>
#include <cassert>
#include <vector>

class Solution {
 public:
  std::vector<int> nextGreaterElement(std::vector<int>& left,
                                      std::vector<int>& right) {
    assert(left.size() <= right.size());

    std::vector<int> result;
    result.reserve(left.size());

    for (const auto num : left) {
      auto it = std::find(right.begin(), right.end(), num);
      if (it == right.end()) {
        result.push_back(-1);
        continue;
      }

      auto found = false;
      for (; it != right.end(); it++) {
        if (*it > num) {
          result.push_back(*it);
          found = true;
          break;
        }
      }

      if (!found) {
        result.push_back(-1);
      }
    }

    return result;
  }
};
