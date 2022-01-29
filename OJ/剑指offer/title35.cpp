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
        map<Node *, Node * > mp;
        mp[nullptr] = nullptr;

        Node *ans = new Node(0);
        Node *p = head, *q = ans;
        while (p) {
            q->next = new Node(p->val);
            mp[p] = q->next;
            p = p->next;
            q = q->next;
        }

        p = head; q = ans->next;
        while (p) {
            q->random = mp[p->random];
            p = p->next;
            q = q->next;
        }

        q = ans;
        ans = ans->next;
        delete q;
        return ans;
    }
};
