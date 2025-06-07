#include <queue>
#include <string>
#include <vector>

namespace {

std::string to_rank(int place) {
  if (place <= 1) {
    return "Gold Medal";
  }
  if (place == 2) {
    return "Silver Medal";
  }
  if (place == 3) {
    return "Bronze Medal";
  }

  return std::to_string(place);
}

}  // namespace

class Solution {
 public:
  // You are given an integer array score of size n, where score[i] is the score
  // of the ith athlete in a competition. All the scores are guaranteed to be
  // unique.
  //
  // The athletes are placed based on their scores, where the 1st place athlete
  // has the highest score, the 2nd place athlete has the 2nd highest score, and
  // so on. The placement of each athlete determines their rank:
  //
  // - The 1st place athlete's rank is "Gold Medal".
  // - The 2nd place athlete's rank is "Silver Medal".
  // - The 3rd place athlete's rank is "Bronze Medal".
  // - For the 4th place to the nth place athlete, their rank is their placement
  //   number (i.e., the xth place athlete's rank is "x").
  //
  // Return an array answer
  // of size n where answer[i] is the rank of the ith athlete.
  std::vector<std::string> findRelativeRanks(
      const std::vector<int>& scores) const {
    std::priority_queue<std::pair<int, std::size_t>> pq;
    for (std::size_t i = 0; i < scores.size(); i++) {
      pq.push(std::make_pair(scores[i], i));
    }

    std::vector<std::string> result(scores.size(), "");

    int score = 1;
    for (; !pq.empty(); pq.pop()) {
      auto [_, idx] = pq.top();

      result[idx] = to_rank(score++);
    }

    return result;
  }
};
