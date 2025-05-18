#include <algorithm>
#include <cassert>
#include <cstdint>
#include <vector>

// You have k bags. You are given a 0-indexed integer array weights where
// weights[i] is the weight of the ith marble. You are also given the integer k.
// Divide the marbles into the k bags according to the following rules:
//
// - No bag is empty.
// - If the ith marble and jth marble are in a bag, then all marbles with an
// index between the ith and jth indices should also be in that same bag
// - If a bag consists of all the marbles with an index from i to j inclusively,
// then the cost of the bag is weights[i] + weights[j]
//
// The score after distributing the marbles is the sum of the costs of all the k
// bags.
//
// Return the difference between the maximum and minimum scores among marble
// distributions.
class Solution {
 public:
  std::int64_t putMarbles(const std::vector<int>& weights, int k) const {
    assert(weights.size() >= 1);
    assert(k >= 1);
    assert(static_cast<std::size_t>(k) <= weights.size());

    std::vector<int> pairs(weights.size() - 1, 0);

    for (std::size_t i = 0; i < weights.size() - 1; i++) {
      pairs[i] = weights[i] + weights[i + 1];
    }

    std::sort(pairs.begin(), pairs.end());

    std::int64_t result = 0;

    for (std::size_t i = 0; i < static_cast<std::size_t>(k) - 1; i++) {
      result += pairs[weights.size() - 2 - i] - pairs[i];
    }

    return result;
  }
};
