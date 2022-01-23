/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 投机取巧法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        vector<int > vc;
        ListNode *p = head;

        while (p) {
            vc.push_back(p->val);
            p = p->next;
        }
        p = head;
        for (int i = (int)vc.size() - 1; i >= 0; --i) {
            p->val = vc[i];
            p = p->next;
        }

        return head;
    }
};

// 遍历一个结点，next 域往前指
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head)    return nullptr;

        ListNode *r = new ListNode(0);
        r->next = head;
        ListNode *f = head;

        while (f) {
            ListNode *p = f;
            f = f->next;
            p->next = r;
            r = p;
        }

        f = head->next;
        head->next = nullptr;
        head = r;
        delete f;
        return head;
    }
};
