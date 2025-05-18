#include "solution.cpp"

#include <gtest/gtest.h>

TEST(HasCycle, Example1) {
  auto* head = new ListNode(3);
  {
    auto* tmp = head;

    auto* loopstart = new ListNode(2);
    tmp->next = loopstart;
    tmp = tmp->next;

    tmp->next = new ListNode(0);
    tmp = tmp->next;

    tmp->next = new ListNode(-4);
    tmp = tmp->next;
    tmp->next = loopstart;
  }

  const auto want = true;
  const auto got = Solution{}.hasCycle(head);

  ASSERT_EQ(want, got);
}

TEST(HasCycle, Example2) {
  auto* head = new ListNode(1);
  {
    auto* tmp = head;

    tmp->next = new ListNode(2);
    tmp = tmp->next;
    tmp->next = head;
  }

  const auto want = true;
  const auto got = Solution{}.hasCycle(head);

  ASSERT_EQ(want, got);
}

TEST(HasCycle, Example3) {
  auto* head = new ListNode(1);

  const auto want = false;
  const auto got = Solution{}.hasCycle(head);

  ASSERT_EQ(want, got);
}
