#include <iostream>
#include <vector>
using namespace std;

// 交换
void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// 打印数组
void print(vector<int >& v) {
    cout << v[0];
    for (int i = 1; i < (int)v.size(); ++i)
        cout << " " << v[i];
    cout << endl;
}

// 选择
void selection_sort(vector<int >& v) {
    for (int i = 0; i < (int)v.size() - 1; ++i) {
        int mini = i;
        for (int j = i + 1; j < (int)v.size(); ++j)
            if (v[mini] > v[j])    mini = j;
        swap(v[mini], v[i]);
    }
}

// 插入
void insertion_sort(vector<int >& v) {
    for (int i = 1; i < (int)v.size(); ++i) {
        int tmp = v[i], j = i;
        for (; j > 0 && v[j - 1] > tmp; --j)
            v[j] = v[j - 1];
        v[j] = tmp;
    }
}

// 冒泡(即交换)
void bubble_sort(vector<int >& v) {
    for (int i = 0; i < (int)v.size() - 1; ++i)
        for (int j = (int)v.size() - 1; j > i; --j)
            if (v[j - 1] > v[j])    swap(v[j - 1], v[j]);
}

// 堆排(即选择)
void adjust_down(vector<int >& v, int l, int h) {
    int i = l, j = 2 * i;
    while (j <= h) {
        if (j + 1 <= h && v[j + 1] > v[j])    ++j;

        if (v[i] < v[j]) {
            swap(v[i], v[j]);
            i = j;
        }
        else    i = 2 * i;
        j = 2 * i;
    }
}

void heap_sort(vector<int >& v) {
    v.insert(v.begin(), 0);// 堆排从下标 1 开始

    // 建堆
    int size = (int)v.size() - 1;
    for (int i = size / 2; i >= 1; --i)
        adjust_down(v, i, size);

    // 堆排
    for (int i = size; i > 1; --i) {
        swap(v[1], v[i]);
        adjust_down(v, 1, i - 1);
    }

    v.erase(v.begin());// 删掉增加的下标 1 对应元素
}

// 快排
void quick_sort(vector<int >& v, int l, int r) {
    if (l > r)    return;

    int pivot = l, i = l, j = r;
    while (i != j) {
        while (i != j && v[j] >= v[pivot])    --j;
        while (i != j && v[i] <= v[pivot])    ++i;
        if (i != j)    swap(v[i], v[j]);
    }
    if (v[pivot] != v[i])    swap(v[pivot], v[i]);

    quick_sort(v, l, i - 1);
    quick_sort(v, i + 1, r);
}

//归并
void merge(vector<int > &v, vector<int > &t, int l, int r, int rE) {
    int lE = r - 1, num = rE - l + 1;
    int p = l;

    while (l <= lE && r <= rE) {
        if (v[l] < v[r])    t[p++] = v[l++];
        else    t[p++] = v[r++];
    }
    while (l <= lE)    t[p++] = v[l++];
    while (r <= rE)    t[p++] = v[r++];

    for (int i = 0; i < num; ++i, --rE)    v[rE] = t[rE];
}

void submerge(vector<int >& v, vector<int >& t, int s) {
    int i = 0, n = (int)v.size();
    for (; i <= n - 2 * s; i += 2 * s)    merge(v, t, i, i + s, i + 2 * s - 1);
    if (i + s < n)    merge(v, t, i, i + s, n - 1);//最后两个子列
}

void merge_sort(vector<int >& v, vector<int >& t) {
    int step = 1, n = (int)v.size();//步长
    while (step < n) {
        submerge(v, t, step);
        step *= 2;
    }
}

int main() {
    vector<int > arr;
    int inp = 0;

    // 输入 44 13 76 25 44 58 92 33 67 82
    while (cin >> inp) {
        arr.push_back(inp);
        if (cin.get() == '\n')    break;
    }

    //selection_sort(arr);
    //insertion_sort(arr);
    //bubble_sort(arr);
    //heap_sort(arr);
    //quick_sort(arr, 0, (int)arr.size() - 1);
    vector<int > backup(arr);
    merge_sort(arr, backup);
    print(arr);

    return 0;
}