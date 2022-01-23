/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *p = head, *i = l1, *j = l2;

        while (i && j) {
            if (i->val <= j->val) {
                p->next = i;
                i = i->next;
            } else {
                p->next = j;
                j = j->next;
            }
            p = p->next;
        }
        if (i)    p->next = i;
        if (j)    p->next = j;

        p = head;
        head = head->next;
        delete p;

        return head;
    }
};
