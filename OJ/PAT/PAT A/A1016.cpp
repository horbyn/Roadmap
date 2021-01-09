#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct man_t {
	char nam[5];//name
	int  MM;
	int  dd;
	int  HH;
	int  mm;
	bool lab;//label
}man[1001];

int cen[24] = { 0 };//cent

bool cmp(struct man_t a, struct man_t b) {
	if (a.nam != b.nam)    return strcmp(a.nam, b.nam) < 0;
	else if (a.dd != b.dd)    return a.dd < b.dd;
	else if (a.HH != b.HH)    return a.HH < b.HH;
	else    return a.mm < b.mm;
}

void calc_time(struct man_t a, struct man_t b, int *dol, int *dur) {//dollar, duration
	/*
	 * 1
	 * int t0 = 0, n = 23
	 * while(T1>t0) t0++;
	 * while(T2<tn) tn--;
	 *
	 * 2
	 * min = t0-T1
	 * dol += cen[t0-1]*min
	 * dur += min
	 *
	 * min = T2-tn
	 * dol += cen[tn]*min
	 * dur += min
	 *
	 * 3
	 * for(){
	 *  d = dd1:HH1 - dd2:HH2
	 *  if(d) 转化为hour
	 * }
	 *
	 * 4
	 * for(i;次数;++i, ++t0){
	 *  if(t0 == 24) t0 = 0;
	 *  dol += cen[t0]*60
	 *  dur += 60
	 * }
	 */
	int T1 = a.HH, T2 = b.HH;
	int t0 = 0, tn = 23;
	while (T1 > t0)    t0++;
	while (T2 < tn)    tn--;

	int min;
	min = t0 - T1;
	dol = dol + cen[t0 - 1] * min;
	dur += min;

	min = T2 - tn;
	dol = dol + cen[tn] * min;
	dur += min;

	int dif = 0;
	if (a.HH < b.HH) {
		dif = a.HH + 24 - b.HH;
		a.dd--;
	} else    dif = a.HH - b.HH;
	dif = dif + (a.dd - b.dd) * 24;

	for (int i = 0; i < dif; ++i, ++t0) {
		if (t0 == 24)    t0 = 0;
		dol = dol + cen[t0] * 60;
		dur += 60;
	}
}

int main() {
	return 0;
}
