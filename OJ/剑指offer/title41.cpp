class MedianFinder {
public:
    priority_queue<int > small;
    priority_queue<int, vector<int >, greater<int > > big;
    int diff;

    /** initialize your data structure here. */
    MedianFinder() {
        diff = 0;
    }

    void addNum(int num) {
        if (small.empty())    big.push(num);
        else {
            if (big.top() <= num)    big.push(num);
            else    small.push(num);
        }

        int m = (int)big.size(), n = (int)small.size();
        if (m - n == 2) {
            small.push(big.top());
            big.pop();
        }else if (m - n == -1) {
            big.push(small.top());
            small.pop();
        }

        diff = abs((int)big.size() - (int)small.size());
    }

    double findMedian() {
        if (diff == 0 && small.empty() && big.empty())    return 0.0;

        if (diff == 1)    return (double)big.top();
        else    return ((double)small.top() + big.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
