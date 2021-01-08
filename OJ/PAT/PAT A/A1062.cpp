#include <iostream>
#include <algorithm>
#include <cstring>

#define MAXSIZE 1024

using namespace std;

struct man_t {
    char num[9];
    int  vir;
    int  tal;
    int  gra;
    int  typ;
};

bool cmp(struct man_t a, struct man_t b) {
    if (a.typ != b.typ)    return a.typ < b.typ;
    if (a.gra != b.gra)    return a.gra >= b.gra;
    else if (a.vir != b.vir)    return a.vir >= b.vir;
    else    return strcmp(a.num, b.num) < 0;
}

int main()
{
    struct man_t man[MAXSIZE] = { 0 };
    int n, l, h;
    int tot = 0;

    cin >> n >> l >> h;
    for (int i = 0; i < n; ++i) {
        cin >> man[i].num >> man[i].vir >> man[i].tal;
        //1. 最低要求
        if (man[i].vir < l || man[i].tal < l) {
            --i;
            --n;
            continue;
        }

        //2. 算总分
        else    man[i].gra = man[i].vir + man[i].tal;
        //3. 分类
        if (man[i].vir >= h && man[i].tal >= h) //圣人
            man[i].typ = 1;
        else if (man[i].vir >= h && h > man[i].tal) //君子
            man[i].typ = 2;
        else if (h > man[i].vir && h > man[i].tal
            && man[i].vir >= man[i].tal) //愚人
            man[i].typ = 3;
        else //小人
            man[i].typ = 4;
        tot++;
    }
    sort(man, man + n, cmp);

    cout << tot << endl;
    for (int i = 0; i < tot; ++i)
        cout << man[i].num << " "
            << man[i].vir << " "
            << man[i].tal << endl;
}