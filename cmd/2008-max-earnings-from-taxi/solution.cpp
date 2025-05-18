#include <algorithm>
#include <vector>

namespace {

long long calc_profit(const std::vector<int>& ride) {
  return ride[1] - ride[0] + ride[2];
}

long long dfs(const std::vector<std::vector<int>>& rides,
              std::vector<long long>& profit, std::size_t i) {
  if (i == rides.size()) {
    return 0;
  }

  if (profit[i] != -1) {
    return profit[i];
  }

  const auto next =
      std::upper_bound(rides.begin() + i, rides.end(), rides[i],
                       [](const auto& value, const auto& element) -> bool {
                         return element[0] >= value[1];
                       }) -
      rides.begin();

  const auto with_ride = calc_profit(rides[i]) + dfs(rides, profit, next);
  const auto without_ride = dfs(rides, profit, i + 1);

  return profit[i] = std::max(with_ride, without_ride);
}

}  // namespace

class Solution {
 public:
  long long maxTaxiEarnings(int, std::vector<std::vector<int>>& rides) {
    std::sort(rides.begin(), rides.end());

    std::vector<long long> profit;
    profit.assign(rides.size(), -1);

    return dfs(rides, profit, 0);
  }
};
