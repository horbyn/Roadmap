class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        data.clear();
        mini.clear();
        p1 = p2 = -1;
    }
    
    void push(int x) {
        data.push_back(x);
        ++p1;

        if (mini.empty() || data[p1] <= mini[p2]) {
            mini.push_back(x);
            ++p2;
        }
    }
    
    void pop() {
        if (data[p1] == mini[p2]) {
            mini.pop_back();
            --p2;
        }

        data.pop_back();
        --p1;
    }
    
    int top() {
        return data[p1];
    }
    
    int min() {
        return mini[p2];
    }
private:
    vector<int > data, mini;
    int p1, p2;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
