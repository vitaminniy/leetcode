#include <string>
#include <unordered_map>

class Solution {
public:
  bool isIsomorphic(const std::string &source, const std::string &target) {
    std::unordered_map<char, char> seen;
    std::unordered_map<char, char> reverse;

    seen.reserve(source.size());
    seen.reserve(target.size());

    for (auto source_it = source.begin(), target_it = target.begin();
         source_it != source.end() && target_it != target.end();
         source_it++, target_it++) {
      const auto s = *source_it;
      const auto t = *target_it;

      const auto seen_it = seen.find(s);
      const auto reverse_it = reverse.find(t);

      if (seen_it == seen.end() && reverse_it == reverse.end()) {
        // new mapping for both source and target
        seen[s] = t;
        reverse[t] = s;
        continue;
      }

      if ((seen_it != seen.end() && reverse_it == reverse.end()) ||
          (seen_it == seen.end() && reverse_it != reverse.end())) {
        // no two characters may map to the same character
        return false;
      }

      if (seen_it->second != reverse_it->first ||
          seen_it->first != reverse_it->second) {
        return false;
      }
    }

    return true;
  }
};
