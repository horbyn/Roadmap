/*
 * 写在前面：才疏学浅不知道怎么在类内使用自定义排序算法并使用 sort()
 * 其实以下这个版本，思路是像 30 vs. 5 结果应为 305，所以若 5->50，那就可以直接比较了，所以核心思路是给每一个数补数位
 * 然后不知道应该怎么写这个 sort()，所以先挖个坑，以后学有所成再 debug
 * 写于 2020-02-07, 某菜鸡
class Solution {
public:
    typedef struct node_t{
        string str;
        int flg, ori;

        node_t(string s, int f, int o) : str(s), flg(f), ori(o) {}
    } node;

    static bool cmp(const Solution::node &a, const Solution::node &b) {
        if (a.str < b.str)    return a.str < b.str;
        else if (a.str > b.str)    return a.str > b.str;
        else    return a.flg < b.flg;
    }

    string minNumber(vector<int>& nums) {
        // 找最大
        int maxi = 0xffffffff;
        for (auto v : nums)
            if (maxi < v)    maxi = v;

        // 找出最大数是 10 的多少个数量级
        int bit = 0;
        while (maxi) {
            bit++;
            maxi /= 10;
        }

        // int 数组转化为 string 数组
        vector<Solution::node > vc;
        for (auto v : nums) {
            string tmp = to_string(v);
            int flg = 0, ori = v;
            if ((int)tmp.size() < bit)    flg = 1;
            while ((int)tmp.size() < bit)    tmp += '0';
            vc.emplace_back(node(tmp, flg, ori));
        }
        sort(vc.begin(), vc.end(), cmp);//bug

        string ret("");
        for (auto s : vc) {
            if (s.flg == 0)    ret += s.str;
            else    ret += to_string(s.ori);
        }
        return ret;
    }
};
*/

/*
 * 以下是参考题解思路后，重新做的
*/
class Solution {
public:
    string minNumber(vector<int>& nums) {
        /* 转化为 string 数组 */
        vector<string > vc;
        for (auto v : nums)    vc.emplace_back(to_string(v));

        /* 类冒泡法排序 */
        string ret("");
        for (int i = 0; i < (int)vc.size(); ++i) {
            for (int j = (int)vc.size() - 1; j > i; --j) {
                if (vc[j - 1][0] < vc[j][0]);
                else if (vc[j - 1][0] > vc[j][0])    swap(vc[j - 1], vc[j]);
                else {
                    string s1 = vc[j - 1] + vc[j];
                    string s2 = vc[j] + vc[j - 1];
                    if (s2 < s1)    swap(vc[j - 1], vc[j]);
                }
            }
        }

        /* 最后拼接 */
        for (auto s : vc)    ret += s;
        return ret;
    }
};