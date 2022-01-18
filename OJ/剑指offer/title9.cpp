class CQueue {
public:
    stack<int > s1, s2;

    CQueue() {
        
    }

    void appendTail(int value) {
        if (this->s1.empty()) {
            while (!this->s2.empty()) {
                int tmp = s2.top();
                s2.pop();
                s1.push(tmp);
            }
        }
        s1.push(value);
    }

    int deleteHead() {
        if (this->s2.empty()) {
            while (!this->s1.empty()) {
                int tmp = s1.top();
                s1.pop();
                s2.push(tmp);
            }
        }
        int tmp = -1;
        if (!this->s2.empty()) {
            tmp = s2.top();
            s2.pop();
        }
        return tmp;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
