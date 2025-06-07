#include <cstdint>

constexpr auto mask16 = 0b11111111111111110000000000000000;
constexpr auto mask16rev = mask16 >> 16;  // 0b00000000000000001111111111111111
constexpr auto mask8 = 0b11111111000000001111111100000000;
constexpr auto mask8rev = mask8 >> 8;  // 0b00000000111111110000000011111111
constexpr auto mask4 = 0b11110000111100001111000011110000;
constexpr auto mask4rev = mask4 >> 4;
constexpr auto mask2 = 0b11001100110011001100110011001100;
constexpr auto mask2rev = mask2 >> 2;
constexpr auto mask1 = 0b10101010101010101010101010101010;
constexpr auto mask1rev = mask1 >> 1;

class Solution {
 public:
  std::uint32_t reverseBits(std::uint32_t n) const {
    n = ((n & mask16) >> 16 | (n & mask16rev) << 16);
    n = ((n & mask8) >> 8 | (n & mask8rev) << 8);
    n = ((n & mask4) >> 4 | (n & mask4rev) << 4);
    n = ((n & mask2) >> 2 | (n & mask2rev) << 2);
    n = ((n & mask1) >> 1 | (n & mask1rev) << 1);

    return n;
  }
};
