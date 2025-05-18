struct ListNode {
  ListNode(int x) : val(x), next(nullptr) {}

  int val{0};
  ListNode* next{nullptr};
};

class Solution {
 public:
  bool hasCycle(const ListNode* head) const {
    if (head == nullptr || head->next == nullptr) {
      return false;
    }

    auto* fast = head;
    auto* slow = head;

    while (fast != nullptr && slow != nullptr && fast->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;

      if (fast == slow) {
        return true;
      }
    }

    return false;
  }
};
