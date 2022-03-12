#pragma once

#include <vector>

namespace my {

#define REQUIRES(...) class = std::enable_if_t<(__VA_ARGS__)>
#define REQUIRES_CV_OF(A, B) REQUIRES(std::is_same_v<std::remove_cv_t<A>, B>)

template <typename Key, typename Less = std::less<Key>>
class Bucket {
 public:
  void add(const Key& key) {
    const auto it = binary_search(key);
    if (it == keys_.end() || *it != key) {
      keys_.insert(it, key);
    }
  }

  bool contains(const Key& key) const {
    const auto it = binary_search(key);
    if (it == keys_.end()) {
      return false;
    }

    return *it == key;
  }

  void remove(const Key& key) {
    const auto it = binary_search(key);
    if (it != keys_.end() && *it == key) {
      keys_.erase(it);
    }
  }

 private:
  template <class U, REQUIRES_CV_OF(U, Bucket)>
  static decltype(auto) binary_search(U& self, const Key& key) {
    return std::lower_bound(self.keys_.begin(), self.keys_.end(), key,
                            self.less_);
  }

  decltype(auto) binary_search(const Key& key) const {
    return binary_search(*this, key);
  }

  decltype(auto) binary_search(const Key& key) {
    return binary_search(*this, key);
  }

  std::vector<Key> keys_;
  Less less_;
};

template <typename Key, typename HashFunc>
class HashSet {
 public:
  /// @brief Adds key to the set.
  void add(const Key& key) {
    const auto idx = hash_func_(key);
    if (idx >= buckets_.size()) {
      buckets_.resize(idx + 1);
    }

    auto& bucket = buckets_[idx];
    bucket.add(key);
  }

  /// @brief Returns whether the key exists in the set or not.
  bool contains(const Key& key) const {
    if (buckets_.empty()) {
      return false;
    }

    const auto idx = hash_func_(key);
    if (idx >= buckets_.size()) {
      return false;
    }

    return buckets_[idx].contains(key);
  }

  /// @brief Removes key from set. If the key does not exist in the set, do
  /// nothing.
  void remove(const Key& key) {
    if (buckets_.empty()) {
      return;
    }

    const auto idx = hash_func_(key);
    if (idx >= buckets_.size()) {
      return;
    }

    auto& bucket = buckets_[idx];
    bucket.remove(key);
  }

 private:
  std::vector<Bucket<Key>> buckets_;
  HashFunc hash_func_;
};

}  // namespace my
