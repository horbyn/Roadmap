/* access:
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805474338127872
 * result: PA 13/25
 * duration: 144 mins
 */

 /*
  * local:
  *     read input to inp[]                     move inp[] to inp_sort[]
  *             |                                           |
  *             v                                           v
  *  according "a.score > b.score"      =>    according "a.score > b.score"
  *         to sort()                                   to sort()
  *             |                                           |
  *             v                                           v
  *      set location number                        set local rank
  *        set local rank  
  */

#include <cstdio>
#include <algorithm>

#pragma warning(disable: 4996)

using namespace std;

#define MAXSIZE 30000

typedef struct testee {
    long long registration_number;
    int score;
    int final_rank;
    int location_number;
    int local_rank;
}testee_t;

testee_t inp[300] = { 0 };
testee_t inp_sort[MAXSIZE] = { 0 };
static int location_no = 1;
static int final_testee_num = 0;

void read_input(void);
void manual_sort(int, bool);

int main() {
    // input module
    read_input();

    // calculate module
    manual_sort(final_testee_num, 1);

    // output module
    printf("%d\n", final_testee_num);
    for (int i = 0; i < final_testee_num; i++) {
        printf("%lld %d %d %d\n",
            inp_sort[i].registration_number,
            inp_sort[i].final_rank,
            inp_sort[i].location_number,
            inp_sort[i].local_rank
        );
    }

    return 0;
}

void read_input() {
    int test_location;
    int testee_num;
    int i, j, k;

    scanf("%d", &test_location);
    for (i = 0; i < test_location; i++) {
        // input module
        scanf("%d", &testee_num);
        for (j = 0; j < testee_num; j++) {
            scanf("%lld%d", &inp[j].registration_number, &inp[j].score);
        }

        // calculate module
        manual_sort(testee_num, 0);                             // calculate local rank
        location_no++;
        // move local input to fianl input
        for (j = final_testee_num, k = 0; j < final_testee_num + testee_num; j++, k++) {
            inp_sort[j] = inp[k];
        }
        final_testee_num += testee_num;                         // renew testees num
    }
}

bool cmp(testee_t a, testee_t b) {
    return a.score > b.score;
}

/*
 * flag = 0: rank is local_rank
 * flag = 1: rank is final_rank
 */
void manual_sort(int inp_num, bool flag) {
    // judge
    if (!flag) {
        sort(inp, inp + inp_num, cmp);                          // sort() sorted in nondecreasing order

        inp[0].local_rank = 1;                                  // set fst person rank to 1
        for (int i = 0; i < inp_num; i++) {
            if (!i) {
                inp[i].location_number = location_no;
                continue;
            }

            // set localtion number
            if (!flag) {
                inp[i].location_number = location_no;
            }

            // set rank number
            if (inp[i].score == inp[i - 1].score) {             // cur score is same as pre, set the same rank
                inp[i].local_rank = inp[i - 1].local_rank;
            }
            else {                                              // otherwise rank plus
                inp[i].local_rank = i + 1;
            }
        }
    }
    else {
        sort(inp_sort, inp_sort + inp_num, cmp);                // sort() sorted in nondecreasing order

        inp_sort[0].final_rank = 1;                             // set fst person rank to 1
        for (int i = 0; i < inp_num; i++) {
            // set rank number
            if (inp_sort[i].score == inp_sort[i - 1].score) {   // cur score is same as pre, set the same rank
                inp_sort[i].final_rank = inp_sort[i - 1].final_rank;
            }
            else {                                              // otherwise rank plus
                inp_sort[i].final_rank = i + 1;
            }
        }
    }
}

/*
Fst submit:
Case    Result	        Run Time	Memory
0       Accepted        3 ms	    328 KB
1       Wrong Answer    3 ms	    228 KB
2       Wrong Answer    3 ms	    224 KB
3       Wrong Answer    37 ms	    1664 KB
*/