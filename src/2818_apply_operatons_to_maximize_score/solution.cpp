#include <queue>
#include <set>
#include <stack>
#include <vector>

constexpr int kMOD = 1e9 + 7;

namespace {
std::vector<int> primeFactors(int n) {
  std::vector<int> result;

  while (n % 2 == 0) {
    result.push_back(2);
    n = n / 2;
  }

  for (int i = 3; i * i <= n; i = i + 2) {
    while (n % i == 0) {
      result.push_back(i);
      n = n / i;
    }
  }

  if (n > 2) {
    result.push_back(n);
  }

  return result;
}

int primeScore(int n) {
  const auto factors = primeFactors(n);
  const auto distinctFactors = std::set<int>(factors.begin(), factors.end());

  return static_cast<int>(distinctFactors.size());
}

int64_t power(int64_t base, int64_t exp) {
  int64_t result = 1;

  while (exp > 0) {
    if (exp % 2 == 1) {
      result = ((result * base) % kMOD);
    }

    base = (base * base) % kMOD;
    exp /= 2;
  }

  return result;
}
}  // namespace

class Solution {
 public:
  int maximumScore(std::vector<int>& nums, int k) {
    std::vector<int> prime_scores;
    prime_scores.resize(nums.size(), 0);

    for (std::size_t i = 0; i < nums.size(); i++) {
      prime_scores[i] = primeScore(nums[i]);
    }

    std::vector<int> next_dominant(nums.size(), nums.size());
    std::vector<int> prev_dominants(nums.size(), -1);

    std::stack<int> decreasing_prime_scores;

    for (std::size_t idx = 0; idx < nums.size(); idx++) {
      while (!decreasing_prime_scores.empty() &&
             prime_scores[decreasing_prime_scores.top()] < prime_scores[idx]) {
        auto top = decreasing_prime_scores.top();
        decreasing_prime_scores.pop();

        next_dominant[top] = static_cast<int>(idx);
      }

      if (!decreasing_prime_scores.empty()) {
        prev_dominants[idx] = decreasing_prime_scores.top();
      }

      decreasing_prime_scores.push(static_cast<int>(idx));
    }

    std::vector<int64_t> num_subarrays(nums.size());
    for (int idx = 0; static_cast<std::size_t>(idx) < nums.size(); idx++) {
      num_subarrays[idx] = static_cast<int64_t>((next_dominant[idx] - idx)) *
                           (idx - prev_dominants[idx]);
    }

    std::priority_queue<std::pair<int, int>> queue;
    for (std::size_t idx = 0; idx < nums.size(); idx++) {
      queue.push(std::make_pair(nums[idx], static_cast<int>(idx)));
    }

    int64_t result = 1;

    while (k > 0) {
      auto [num, idx] = queue.top();
      queue.pop();

      auto ops = std::min(static_cast<int64_t>(k), num_subarrays[idx]);

      result = (result * power(num, ops)) % kMOD;

      k -= ops;
    }

    return result;
  }
};
