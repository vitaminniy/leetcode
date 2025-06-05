#include <cassert>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace {

std::unordered_map<char, std::vector<char>> build_equivalency(
    const std::string& s1, const std::string& s2) {
  std::unordered_map<char, std::vector<char>> result;

  result.reserve(s1.size() + s2.size());

  for (std::size_t i = 0; i < s1.size(); i++) {
    auto key = s1[i];
    auto value = s2[i];

    result[key].push_back(value);
    result[value].push_back(key);
  }

  return result;
}

char find_smallest(const std::unordered_map<char, std::vector<char>>& equiv,
                   char c, std::unordered_set<char>& visited) {
  visited.insert(c);

  auto result = c;

  const auto it = equiv.find(c);
  if (it == equiv.end()) {
    return result;
  }

  for (const auto n : it->second) {
    auto vit = visited.find(n);
    if (vit != visited.end()) {
      continue;
    }

    result = std::min(result, find_smallest(equiv, n, visited));
  }

  return result;
}

}  // namespace

class Solution {
 public:
  std::string smallestEquivalentString(const std::string& s1,
                                       const std::string& s2,
                                       const std::string& baseStr) const {
    assert(s1.size() == s2.size());

    const auto equivalency = build_equivalency(s1, s2);

    std::string result;
    result.reserve(baseStr.size());

    for (const auto c : baseStr) {
      std::unordered_set<char> visited;

      const auto smallest = find_smallest(equivalency, c, visited);
      result.push_back(smallest);
    }

    return result;
  }
};
