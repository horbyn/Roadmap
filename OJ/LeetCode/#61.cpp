class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        vector<int > vc;
        ListNode* p = head;
        while (p) {
            vc.push_back(p->val);
            p = p->next;
        }

        // create another vector to restore the result of rotation
        int size = vc.size();
        vector<int > ret(size);
        for (int i = 0; i < size; ++i)
            ret[(i + k) % size] = vc[i];

        p = head;
        for (int i = 0; i < size; ++i, p = p->next)
            p->val = ret[i];
        return head;
    }
};
