#include <string>
#include <vector>

class Solution {
 public:
  std::string multiply(std::string num1, std::string num2) {
    if (num1 == "0" || num2 == "0") {
      return "0";
    }

    reverse(num1);
    reverse(num2);

    std::vector<int> result(num1.size() + num2.size(), 0);

    for (size_t i = 0; i < num1.size(); i++) {
      for (size_t j = 0; j < num2.size(); j++) {
        const int num_i = num1[i] - '0';
        const int num_j = num2[j] - '0';
        const int num = num_i * num_j;

        result[i + j] += num;
        result[i + j + 1] += (result[i + j] / 10);
        result[i + j] = (result[i + j] % 10);
      }
    }

    reverse(result);
    size_t lead = 0;
    while (lead < result.size() && result[lead] == 0) {
      lead++;
    }

    std::string s;
    for (; lead < result.size(); lead++) {
      s += '0' + result[lead];
    }

    return s;
  }

 private:
  template <typename Container>
  void reverse(Container& c) {
    for (size_t i = 0; i < c.size() / 2; i++) {
      std::swap(c[i], c[c.size() - 1 - i]);
    }
  }
};
