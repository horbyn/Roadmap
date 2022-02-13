// 一般思路应该是哈希表的，但题目要求时间 O(n) 空间 O(1)，那哈希表就不可能了
// 然后没做出来要看题解，题解这种方法应该一般人想不出来，有点偏规律，所以凑合 commit 吧

// v1：哈希表
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (!headA || !headB)    return nullptr;

        unordered_map<ListNode*, bool > mp;
        ListNode* pa = headA, * pb = headB;
        while (pa) {
            mp[pa] = true;
            pa = pa->next;
        }
        while (pb) {
            if (mp[pb] == true)    break;
            else    pb = pb->next;
        }
        return pb;
    }
};

// v2：规律
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* pa = headA, * pb = headB;

        while (pa != pb) {
            if (pa == nullptr)    pa = headB;
            else    pa = pa->next;
            if (pb == nullptr)    pb = headA;
            else    pb = pb->next;
        }

        return pa;
    }
};