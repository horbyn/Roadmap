class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int cf = 0;
        ListNode* p1 = l1, * p2 = l2;
        ListNode* ret = new ListNode;
        ret->next = nullptr;
        ListNode* tmp = ret;

        while (p1 && p2) {
            // calculate
            int sum = p1->val + p2->val + cf;
            ListNode* p = new ListNode;
            p->next = nullptr;
            p->val = sum % 10;
            cf = sum / 10;

            // insert node
            tmp->next = p;
            tmp = tmp->next;
            p1 = p1->next;
            p2 = p2->next;
        }

        while (p1) {
            int sum = p1->val + cf;
            ListNode* p = new ListNode;
            p->next = nullptr;
            p->val = sum % 10;
            cf = sum / 10;

            tmp->next = p;
            tmp = tmp->next;
            p1 = p1->next;
        }
        while (p2) {
            int sum = p2->val + cf;
            ListNode* p = new ListNode;
            p->next = nullptr;
            p->val = sum % 10;
            cf = sum / 10;

            tmp->next = p;
            tmp = tmp->next;
            p2 = p2->next;
        }
        if (cf == 1) {
            // the highest carry need to insert extra one
            ListNode* p = new ListNode;
            p->next = nullptr;
            p->val = 1;

            tmp->next = p;
            tmp = tmp->next;
        }

        //del head node
        ListNode* del = ret;
        ret = ret->next;
        delete del;
        return ret;
    }
};
