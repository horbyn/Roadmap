/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // add head node
        ListNode* p = new ListNode;
        p->next = head;
        head = p;

        // calcate list size
        int num = 0;
        while (p->next) {
            num++;
            p = p->next;
        }

        // find former node
        int former = num - n;
        p = head;
        int cr = 0;
        while (cr != former) {
            cr++;
            p = p->next;
        }

        // delete node
        ListNode* del = p->next;
        p->next = p->next->next;
        delete del;

        // delete head node
        del = head;
        head = head->next;
        delete del;
        return head;
    }
};
