#include <string>

namespace {

constexpr auto kNumSymbols = 26;
constexpr auto kASCIIOffset = 65;

char to_char(int sym) { return static_cast<char>(sym + kASCIIOffset); }

}  // namespace

class Solution {
 public:
  std::string convertToTitle(int columnNumber) const {
    std::string result;

    while (columnNumber > 0) {
      columnNumber--;

      auto symbol = columnNumber % kNumSymbols;

      columnNumber /= kNumSymbols;

      result = to_char(symbol) + result;
    }

    return result;
  }
};
