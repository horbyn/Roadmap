#include <cstdio>
#include <cstring>
#include <algorithm>

#pragma warning(disable: 4996)

using namespace std;

#define MAXSIZE 1000

struct man_t {
	char nam[21];//name
	int  MM;
	int  dd;
	int  HH;
	int  mm;
	bool lab;//label
}man[1001];

int cen[24] = { 0 };//cent

bool cmp(struct man_t a, struct man_t b) {
	if (a.nam != b.nam)    return strcmp(a.nam, b.nam) < 0;
	else if (a.MM != b.MM)    return a.MM < b.MM;
	else if (a.dd != b.dd)    return a.dd < b.dd;
	else if (a.HH != b.HH)    return a.HH < b.HH;
	else    return a.mm < b.mm;
}

void calc_time (struct man_t a, struct man_t b, double* dol, int* dur) {//dollar, duration
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
	}
	else    dif = a.HH - b.HH;
	dif = dif + (a.dd - b.dd) * 24;

	for (int i = 0; i < dif; ++i, ++t0) {
		if (t0 == 24)    t0 = 0;
		dol = dol + cen[t0] * 60;
		dur += 60;
	}
}

int main() {
	bool flag = false;
	double dol = 0.0;
	int dur = 0;
	char ch, str[9];
	int n;

	//INPUT
	for (int i = 0; i < 24; ++i)    scanf("%d", &cen[i]);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", man[i].nam);///%s遇空格会停止读入；而且会自动加上'\0'
		scanf("%2d:%2d:%2d:%2d ", &man[i].MM, &man[i].dd,
			&man[i].HH, &man[i].mm);
		scanf("%s", str);
		if (!strcmp(str, "on-line"))    man[i].lab = 1;
		else    man[i].lab = 0;
	}

	//EXECUTE
	sort(man, man + n, cmp);///排序这里执行完不对，暂时看不出什么问题
	char *tmp_nam = NULL;
	for (int i = 0; i < n; ) {
		if (strcmp(tmp_nam, man[i].nam)) {
			if (i != 0)
				printf("Total amount: $%.2f\n", dol / 1000.0);
			printf("%s %02d\n", man[i].nam, man[i].MM);
			tmp_nam = man[i].nam;
			dol = 0.0;
		}
		if (i + 1 == n)    break;
		if (man[i].lab == 1 && man[i + 1].lab == 0) {
			calc_time(man[i], man[i + 1], &dol, &dur);
			i += 2;
			flag = true;
		} else    i += 1;
		if (flag) {
			printf("%d:%d:%d ", man[i].dd, man[i].HH, man[i].mm);
			printf("%d:%d:%d ", man[i + 1].dd, man[i + 1].HH, man[i + 1].mm);
			printf("%d %.2f\n", dur, dol / 1000.0);
			flag = false;
		}
	}
	printf("Total amount: $%.2f\n", dol / 1000.0);

	return 0;
}