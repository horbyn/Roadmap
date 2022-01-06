class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1)    return head;

        // by means of vector to reverse
        vector<int > vc;
        ListNode* p = head;
        while (p) {
            vc.push_back(p->val);
            p = p->next;
        }
        int size = vc.size();
        p = head;
        for (int i = 0; i <= size - k; i += k) {
            for (int j = i + k - 1; j >= i; --j) {
                p->val = vc[j];
                p = p->next;
            }
        }
        return head;
    }
};
