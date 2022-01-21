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
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode *p = new ListNode(0);
        p->next = head;
        head = p;                           // 加上头结点

        while (p->next) {
            if (p->next->val == val) {
                p->next = p->next->next;
                break;
            }
            p = p->next;
        }

        p = head;
        head = head->next;                  // 删头结点
        delete p;
        return head;
    }
};
