#include <map>
#include <vector>

class Solution {
 public:
  int numberOfArithmeticSlices(std::vector<int>& nums) {
    const int size = nums.size();
    int result = 0;
    std::vector<std::map<int, int>> counter(size);

    for (int i = 1; i < size; i++) {
      for (int j = 0; j < i; j++) {
        auto delta = nums[i] - nums[j];
        auto sum = 0;

        if (auto it = counter[j].find(delta); it != counter[j].end()) {
          sum = it->second;
        }

        counter[i][delta] += (sum + 1);
        result += sum;
      }
    }

    return result;
  }
};
