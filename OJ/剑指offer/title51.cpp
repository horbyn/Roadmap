// v1：归并用的 mooc-zju-ds 网课模板，这种方式是自底向上递归，即 1、2、4、8... 划分序列
// 测试了三次平均耗时 164ms
class Solution {
public:
    void merge(vector<int >& v, int l, int r, int rE, int &m) {
        vector<int > tmp((int)v.size(), 0);
        int lE = r - 1, p = l, n = rE - l + 1;

        while (l <= lE && r <= rE) {
            if (v[l] <= v[r])    tmp[p++] = v[l++];
            else {
                m += lE - l + 1;
                tmp[p++] = v[r++];
            }
        }
        while (l <= lE)    tmp[p++] = v[l++];
        while (r <= rE)    tmp[p++] = v[r++];
        for (int i = 0; i < n; ++i, --rE)    v[rE] = tmp[rE];
    }

    void submerge(vector<int >& v, int s, int &m) {
        int i, n = (int)v.size();
        for (i = 0; i <= n - 2 * s; i += 2 * s)    merge(v, i, i + s, i + 2 * s - 1, m);
        if (i + s < n)    merge(v, i, i + s, n - 1, m);
    }

    int reversePairs(vector<int>& nums) {
        int step = 1, ret = 0, size = (int)nums.size();
        while (step < size) {
            submerge(nums, step, ret);
            step *= 2;
        }
        return ret;
    }
};

// v2：参考路飞题解，自顶向下递归，即 n/2、n/4、...、1 顺序划分序列
// https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/solution/jian-zhi-offer-51-shu-zu-zhong-de-ni-xu-pvn2h/
// 测试了三次平均耗时 160ms
class Solution {
public:
    void merge(vector<int >& v, vector<int >& t, int l, int r, int& m) {
        if (l >= r)    return;              // 只有一个没办法归并，所以等于也是边界

        int mid = l + ((r - l) >> 1);
        merge(v, t, l, mid, m);
        merge(v, t, mid + 1, r, m);
        for (int i = l; i <= r; ++i)    t[i] = v[i];
        for (int i = l, j = mid + 1, p = l; p <= r; ++p) {
            if (i == mid + 1)    v[p] = t[j++];
            else if (j == r + 1 || t[i] <= t[j])    v[p] = t[i++];
            else {
                m += mid - i + 1;
                v[p] = t[j++];
            }
        }
    }

    int reversePairs(vector<int>& nums) {
        int step = 1, ret = 0, size = (int)nums.size();
        vector<int > tmp(size, 0);
        merge(nums, tmp, 0, size - 1, ret);
        return ret;
    }
}