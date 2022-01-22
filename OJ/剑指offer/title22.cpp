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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *slow = head, *fast = head;

        for (int i = 1; i < k; ++i)    fast = fast->next;

        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }
};
