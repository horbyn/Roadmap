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
    ListNode* reverseList(ListNode* head) {
        if (!head)    return nullptr;

        ListNode* p = head;
        ListNode* pre, *nxt;

        // 第一个结点单独处理
        pre = nxt = new ListNode(p->val);

        // 处理其他结点
        while (p->next) {
            p = p->next;
            pre = new ListNode(p->val);
            pre->next = nxt;
            nxt = pre;
        }

        return pre;
    }
};
