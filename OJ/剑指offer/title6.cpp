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
    vector<int> reversePrint(ListNode* head) {
        // ============== INITIALIZATION ================
        vector<int > vec;
        ListNode *p = head, *cur = nullptr;
        ListNode *front = new ListNode(0), *next = nullptr;
        
        // =============== MAIN LOGIC ===================
        // 头插法，创建新链表（逆序）
        while (p) {
            cur = new ListNode(p->val);
            cur->next = next;
            front->next = cur;
            next = cur;
            p = p->next;
        }
        
        // 赋值给 vector，同时回收新链表空间
        p = front->next;
        while (p) {
            vec.push_back(p->val);
            cur = p;
            p = p->next;
            delete cur;
        }
        
        return vec;
    }
};
