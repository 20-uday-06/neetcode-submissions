class Solution {
public:

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nxt = curr->next;

            curr->next = prev;

            prev = curr;
            curr = nxt;
        }

        return prev;
    }

    void reorderList(ListNode* head) {

        if (head == nullptr || head->next == nullptr)
            return;

        // 1. Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != nullptr &&
               fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Split into two lists
        ListNode* second = slow->next;
        slow->next = nullptr;

        // 3. Reverse second half
        second = reverseList(second);

        // 4. Merge
        ListNode* first = head;

        while (second != nullptr) {

            ListNode* nextFirst = first->next;
            ListNode* nextSecond = second->next;

            first->next = second;
            second->next = nextFirst;

            first = nextFirst;
            second = nextSecond;
        }
    }
};