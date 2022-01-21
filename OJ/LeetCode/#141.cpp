// 官方用的快慢指针，以后补上
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode *, bool > mp;
        ListNode *p = head;

        while (p) {
            if (mp[p])    return true;
            else {
                mp[p] = true;
                p = p->next;
            }
        }

        return false;
    }
};
