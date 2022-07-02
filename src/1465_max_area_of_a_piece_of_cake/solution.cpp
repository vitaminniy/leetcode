#include <vector>

namespace {

constexpr std::size_t kModulo = 1000000007;  // std::pow(10, 9) + 7;

std::size_t GetBiggestSlice(int len, std::vector<int>& cuts) {
  std::sort(cuts.begin(), cuts.end());
  cuts.push_back(len);

  int max = 0;
  int start = 0;
  for (const auto cut : cuts) {
    max = std::max(max, cut - start);
    start = cut;
  }

  return static_cast<std::size_t>(max);
}

}  // namespace

class Solution {
 public:
  int maxArea(int h, int w, std::vector<int>& horizontalCuts,
              std::vector<int>& verticalCuts) const {
    const auto horizontal = GetBiggestSlice(h, horizontalCuts) % kModulo;
    const auto vertical = GetBiggestSlice(w, verticalCuts) % kModulo;

    return static_cast<int>((horizontal * vertical) % kModulo);
  }
};
