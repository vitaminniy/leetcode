#include <my/hash_set.hpp>

#include <string>

#include <gtest/gtest.h>

namespace my {

namespace {

struct HashFunc {
  size_t operator()(const int i) const { return i % 8; }
};

}  // namespace

TEST(IntBucket, ContainsZero) {
  const Bucket<int> bucket;
  ASSERT_FALSE(bucket.contains(0));
}

TEST(IntBucket, ContainsOne) {
  Bucket<int> bucket;
  bucket.add(1);
  ASSERT_TRUE(bucket.contains(1));
}

TEST(IntBucket, ContainsNoDuplicates) {
  Bucket<int> bucket;
  bucket.add(1);
  bucket.add(1);
  ASSERT_TRUE(bucket.contains(1));
}

TEST(IntBucket, AddRemoveSuite) {
  Bucket<int> bucket;

  {
    bucket.add(0);
    bucket.add(1);

    ASSERT_TRUE(bucket.contains(0));
    ASSERT_TRUE(bucket.contains(1));
  }

  {
    bucket.remove(0);

    ASSERT_FALSE(bucket.contains(0));
    ASSERT_TRUE(bucket.contains(1));
  }

  {
    bucket.remove(1);

    ASSERT_FALSE(bucket.contains(0));
    ASSERT_FALSE(bucket.contains(1));
  }
}

TEST(IntHashSet, ContainsNothing) {
  const HashSet<int, HashFunc> hash_set;
  ASSERT_FALSE(hash_set.contains(0));
}

TEST(IntHashSet, AddRemoveSuite) {
  HashSet<int, HashFunc> hash_set;

  {
    hash_set.add(0);
    ASSERT_TRUE(hash_set.contains(0));
  }

  {
    hash_set.add(1);
    ASSERT_TRUE(hash_set.contains(0));
    ASSERT_TRUE(hash_set.contains(1));
  }

  {
    hash_set.remove(1);
    ASSERT_TRUE(hash_set.contains(0));
    ASSERT_FALSE(hash_set.contains(1));
  }

  {
    hash_set.remove(0);
    ASSERT_FALSE(hash_set.contains(0));
    ASSERT_FALSE(hash_set.contains(1));
  }
}

}  // namespace my
