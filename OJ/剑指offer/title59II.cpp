class MaxQueue {
public:
    queue<int > qu;
    deque<int > des;// 维护一个单调队列，即入队元素只能比 back() 要小

    MaxQueue() {
        
    }

    int max_value() {
        return des.empty() ? -1 : des.front();
    }

    void push_back(int value) {
        while (!des.empty() && des.back() < value)    des.pop_back();
        qu.push(value);
        des.push_back(value);
    }

    int pop_front() {
        if (qu.empty())    return -1;
        int fr = qu.front();
        if (fr == des.front())    des.pop_front();
        qu.pop();
        return fr;
    }
};