#include <cstdlib>
#include <vector>

class Solution {
 public:
  void rotate(std::vector<int>& nums, int k) const {
    const int size = nums.size();

    k = k % size;
    if (k == 0 || size <= 1) {
      return;
    }

    // NOTE(udalovmax): reverse [end - k, end)
    partial_rotate(nums, size - k, size - 1);
    // NOTE(udalovmax): rotate [0; end - k)
    partial_rotate(nums, 0, size - 1 - k);
    // NOTE(udalovmax): rotate array completely
    partial_rotate(nums, 0, size - 1);
  }

 private:
  void partial_rotate(std::vector<int>& nums, int start, int end) const {
    while (start <= end) {
      auto tmp = nums[start];
      nums[start] = nums[end];
      nums[end] = tmp;
      start++;
      end--;
    }
  }
};
