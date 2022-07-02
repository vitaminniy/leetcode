#include <cmath>
#include <utility>
#include <vector>

namespace {

const static std::uint64_t kModulo = std::pow(10, 9) + 7;

using Slice = std::pair<int, int>;

int GetDiff(const Slice& slice) { return slice.second - slice.first; }

bool More(const Slice& lhs, const Slice& rhs) {
  return GetDiff(lhs) > GetDiff(rhs);
}

Slice GetBiggestSlice(int len, std::vector<int>& cuts) {
  if (cuts.empty()) {
    return std::make_pair(0, len);
  }

  std::sort(cuts.begin(), cuts.end());

  std::vector<Slice> slices;
  slices.reserve(cuts.size() + 1);

  int start = 0;
  for (const auto cut : cuts) {
    slices.emplace_back(start, cut);
    start = cut;
  }

  if (start < len) {
    slices.emplace_back(start, len);
  }

  std::sort(slices.begin(), slices.end(), More);

  return slices.front();
}

}  // namespace

class Solution {
 public:
  int maxArea(int h, int w, std::vector<int>& horizontalCuts,
              std::vector<int>& verticalCuts) const {
    const auto horizontal_slice = GetBiggestSlice(h, horizontalCuts);
    const auto vertical_slice = GetBiggestSlice(w, verticalCuts);

    std::uint64_t result = 1;
    result *= static_cast<std::uint64_t>(GetDiff(horizontal_slice)) % kModulo;
    result *= static_cast<std::uint64_t>(GetDiff(vertical_slice)) % kModulo;

    return static_cast<int>(result % kModulo);
  }
};
