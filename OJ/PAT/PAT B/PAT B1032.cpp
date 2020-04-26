/* access:
 * https://pintia.cn/problem-sets/994805260223102976/problems/994805289432236032
 * completation: Apr 26th, 2020
 * result: AC 20/20
 */

/*
 *   3    2      1
 *  65   80    100
 * +40  +70
 * ---  ---             => sort()  => "2 150"
 * 105  150
 * + 0
 * ---
 * 105
 */

#include <cstdio>
#include <algorithm>

//#pragma warning(disable: 4996)

using namespace std;

#define MAXSIZE 100010

typedef struct infor_t {
    int school_no;
    int grade;
}infor_t;

bool cmp(infor_t a, infor_t b) {
    return a.grade > b.grade;
}

int main() {
    int inp;
    int school_no, grade;
    infor_t infor[MAXSIZE] = { 0 };

    // input module
    scanf("%d", &inp);
    for (int i = 0; i < inp; i++) {
        scanf("%d%d", &school_no, &grade);
        infor[school_no].school_no = school_no;
        infor[school_no].grade += grade;
    }

    // calculate module
    sort(infor, infor + inp + 1, cmp);

    // output module
    printf("%d %d", infor[0].school_no, infor[0].grade);

    return 0;
}