class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode dummy(0);
        ListNode* currAns = &dummy;

        ListNode* currL1 = l1;
        ListNode* currL2 = l2;

        int carry = 0;

        while (currL1 != nullptr || currL2 != nullptr || carry) {

            int sum = carry;

            if (currL1 != nullptr) {
                sum += currL1->val;
                currL1 = currL1->next;
            }

            if (currL2 != nullptr) {
                sum += currL2->val;
                currL2 = currL2->next;
            }

            currAns->next = new ListNode(sum % 10);
            currAns = currAns->next;

            carry = sum / 10;
        }

        return dummy.next;
    }
};