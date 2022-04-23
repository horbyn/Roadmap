// 方法一：哈希表记录是否存在
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode *, bool > mp;
        ListNode *p = head;

        while (p) {
            if (mp[p])    return true;
            mp[p] = true;
            p = p->next;
        }

        return false;
    }
};

// 方法二：双指针判环思想
//     设一个指针每次移动一格
//     另一个指针每次移动两格
//     若有环，两指针必相遇
class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* i = head, *j = head;

        while (i && j) {
            i = i->next;
            for (int k = 0; k < 2 && j; ++k)    j = j->next;
            // 如果 ij 都为空，那么相等也不能说明有环
            if (i && j && i == j)    return true;
        }

        return false;
    }
};