#include <algorithm>
#include <limits>
#include <vector>

constexpr static int kMax = std::numeric_limits<int>::max();

class Solution {
public:
  int count_swaps(int target, const std::vector<int> &a,
                  const std::vector<int> &b) {
    int nswaps = 0;
    for (auto i = 0; i < a.size(); i++) {
      if (a[i] != target && b[i] != target) {
        return kMax;
      } else if (a[i] != target) {
        nswaps++;
      }
    }
    return nswaps;
  }

  int minDominoRotations(std::vector<int> &a, std::vector<int> &b) {
    int result = count_swaps(a[0], a, b);
    result = std::min(result, count_swaps(a[0], b, a));
    result = std::min(result, count_swaps(b[0], a, b));
    result = std::min(result, count_swaps(b[0], b, a));

    return result == kMax ? -1 : result;
  }
};
