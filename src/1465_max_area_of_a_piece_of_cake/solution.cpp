#include <cmath>
#include <vector>

namespace {

const static std::uint64_t kModulo = std::pow(10, 9) + 7;

int GetBiggestSlice(int len, std::vector<int>& cuts) {
  if (cuts.empty()) {
    return static_cast<std::uint64_t>(len);
  }

  std::sort(cuts.begin(), cuts.end());

  int max = 0;
  int start = 0;
  for (const auto cut : cuts) {
    max = std::max(max, cut - start);
    start = cut;
  }

  if (start < len) {
    max = std::max(max, len - start);
  }

  return max;
}

}  // namespace

class Solution {
 public:
  int maxArea(int h, int w, std::vector<int>& horizontalCuts,
              std::vector<int>& verticalCuts) const {
    const auto horizontal = GetBiggestSlice(h, horizontalCuts) % kModulo;
    const auto vertical = GetBiggestSlice(w, verticalCuts) % kModulo;

    return (horizontal * vertical) % kModulo;
  }
};
