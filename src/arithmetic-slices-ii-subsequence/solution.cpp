#include <map>
#include <vector>

class Solution {
 public:
  int numberOfArithmeticSlices(std::vector<int>& nums) {
    const int size = nums.size();
    std::int64_t result = 0;
    std::vector<std::map<std::int64_t, int>> counter(size);

    for (int i = 1; i < size; i++) {
      for (int j = 0; j < i; j++) {
        auto delta = static_cast<std::int64_t>(nums[i]) -
                     static_cast<std::int64_t>(nums[j]);
        auto sum = 0;

        if (auto it = counter[j].find(delta); it != counter[j].end()) {
          sum = it->second;
        }

        counter[i][delta] += (sum + 1);
        result += sum;
      }
    }

    return static_cast<int>(result);
  }
};
