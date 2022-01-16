/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)    return nullptr;

        map<Node *, Node * > mp;//新 -> 旧
        mp[nullptr] = nullptr;
        Node* p, * pret, * pre, * cur;
        p = head;
        pret = new Node(p->val);

        // ============= 第一次遍历拷贝 next ===============
        //第一个结点单独拷贝
        pre = cur = pret;
        mp[p] = pre;
        
        //拷贝其余结点
        while (p->next) {
            p = p->next;
            cur = new Node(p->val);
            mp[p] = cur;
            pre->next = cur;
            pre = cur;
        }
        cur->next = nullptr;

        // ============= 第二次遍历拷贝 random ===============
        p = head;
        cur = pret;
        while (p) {
            cur->random = mp[p->random];
            p = p->next;
            cur = cur->next;
        }

        return pret;
    }
};
