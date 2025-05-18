#include <algorithm>
#include <array>
#include <cassert>
#include <vector>

namespace {

// prepare_jobs organizes jobs as tuples of <start, end, profit> and sorts them
// the way thay earliest jobs with earlier end time comes first.
std::vector<std::array<int, 3>> prepare_jobs(const std::vector<int>& start_time,
                                             const std::vector<int>& end_time,
                                             const std::vector<int>& profit) {
  std::vector<std::array<int, 3>> result;

  result.reserve(start_time.size() + 1);

  for (std::size_t i = 0; i < start_time.size(); i++) {
    result.push_back({start_time[i], end_time[i], profit[i]});
  }

  std::sort(result.begin(), result.end());

  return result;
}

// calculate_next_jobs calculates job to execute after jobs[i]. In other words
// `result[i] = idx` where idx - index in jobs to execute after jobs[i].
// jobs[idx].start > jobs[i].end.
std::vector<std::size_t> calculate_next_jobs(
    const std::vector<std::array<int, 3>>& jobs) {
  std::vector<std::size_t> result;
  result.resize(jobs.size());

  for (std::size_t i = 0; i < jobs.size(); i++) {
    auto start = jobs.begin() + i;
    auto end = jobs.end();

    auto it =
        std::upper_bound(start, end, std::array<int, 3>{jobs[i][1], 0, 0});

    result[i] = it - jobs.begin();
  }

  return result;
}

int max_profit(const std::vector<std::array<int, 3>>& jobs,
               std::vector<int>& dp, const std::vector<std::size_t>& next_jobs,
               std::size_t i) {
  if (i == jobs.size()) {
    return 0;
  }

  if (dp[i] != -1) {
    return dp[i];
  }

  auto profit_with_job =
      jobs[i][2] + max_profit(jobs, dp, next_jobs, next_jobs[i]);
  auto profit_without_job = max_profit(jobs, dp, next_jobs, i + 1);

  return dp[i] = std::max(profit_with_job, profit_without_job);
}

}  // namespace

class Solution {
 public:
  int jobScheduling(const std::vector<int>& startTime,
                    const std::vector<int>& endTime,
                    const std::vector<int>& profit) {
    assert(!startTime.empty());
    assert(startTime.size() == endTime.size() == profit.size());

    const auto jobs = prepare_jobs(startTime, endTime, profit);
    const auto next_jobs = calculate_next_jobs(jobs);

    std::vector<int> dp;
    dp.assign(jobs.size(), -1);

    return max_profit(jobs, dp, next_jobs, 0);
  }
};
