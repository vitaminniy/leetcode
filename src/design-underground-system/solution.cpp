#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

class UndergroundSystem {
 public:
  UndergroundSystem() = default;

  void checkIn(int id, std::string stationName, int t) {
    customers_[id] = CheckIn{std::move(stationName), t};
  }

  void checkOut(int id, std::string stationName, int t) {
    const auto& check_in = customers_[id];
    const auto path = GetPath(check_in.station, stationName);
    path_checkouts_[path].push_back(t - check_in.t);
  }

  double getAverageTime(std::string startStation, std::string endStation) {
    const auto path = GetPath(startStation, endStation);
    const auto& checkouts = path_checkouts_[path];

    const double sum = std::accumulate(checkouts.begin(), checkouts.end(), 0.0);
    return sum / checkouts.size();
  }

 private:
  struct CheckIn {
    std::string station;
    int t;
  };

  std::unordered_map<int, CheckIn> customers_;
  std::unordered_map<std::string, std::vector<int>> path_checkouts_;

  static std::string GetPath(const std::string& start, const std::string& end) {
    return start + "_" + end;
  }
};
