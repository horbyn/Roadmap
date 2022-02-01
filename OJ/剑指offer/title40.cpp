class Solution {
public:
    // 由快速排序算法得到灵感
    int quick_sort(vector<int >& v, int k, int l, int r) {
        if (l > r)    return l; // 递归保证前半部分左小右大，所以到达递归边界时返回左端点
        int i = l, j = r, pivot = l;
        while (i != j) {
            while (i != j && v[j] >= v[pivot])    --j;
            while (i != j && v[i] <= v[pivot])    ++i;
            if (v[i] != v[j])    swap(v[i], v[j]);
        }
        if (v[pivot] != v[i])    swap(v[pivot], v[i]);

        if (k == i + 1)    return i;
        else if (k < i + 1)    return quick_sort(v, k, l, i - 1);
        else    return quick_sort(v, k, i + 1, r);
    }

    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (arr.empty() || k == 0)    return {};

        int pivot = quick_sort(arr, k, 0, (int)arr.size() - 1);
        vector<int > ret;
        for (int i = 0; i <= pivot; ++i)    ret.emplace_back(arr[i]);
        return ret;
    }
};
