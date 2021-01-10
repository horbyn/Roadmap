#include <cstdio>
#include <cstring>
#include <algorithm>

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
	int ret = strcmp(a.nam, b.nam);
	if (ret)    return ret < 0;///字符串比较不能直接拿两个变量比较
	else if (a.MM != b.MM)    return a.MM < b.MM;
	else if (a.dd != b.dd)    return a.dd < b.dd;
	else if (a.HH != b.HH)    return a.HH < b.HH;
	else    return a.mm < b.mm;
}

int calc_time_diff(int a1, int b1, int a2, int b2, int bas) {//base
	int dif = 0;//difference value
	if (b1 < b2) {
		a1--;
		dif = b1 + bas - b2;
	} else    dif = b1 - b2;
	dif = dif + (a1 - a2) * bas;
	return dif;
}

void calc_time (struct man_t a, struct man_t b, double* dol, int* dur) {//dollar, duration
	int T1 = a.HH, T2 = b.HH;
	int t0 = 0, tn = 23;
	while (T1 > t0++);
	while (T2 < tn)    tn--;

	int min;
	min = calc_time_diff(t0, 0, T1, a.mm, 60);
	*dol = *dol + cen[t0 - 1] * min;
	*dur += min;

	min = calc_time_diff(T2, b.mm, tn, 00, 60);
	*dol = *dol + cen[tn] * min;
	*dur += min;

	int hou = calc_time_diff(b.dd, tn, a.dd, t0, 24);//hour

	for (int i = 0; i < hou; ++i, ++t0) {
		if (t0 == 24)    t0 = 0;
		*dol = *dol + cen[t0] * 60;
		*dur += 60;
	}
}

int main() {
	bool flag = false;
	double dol = 0.0;
	int dur = 0;
	char str[9];
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
	sort(man, man + n, cmp);
	char tmp_nam[21];
	double sum;
	strcpy(tmp_nam, "NULL");///strcpy()赋值是会覆盖的，而且自动带上'\0'
	for (int i = 0; i < n; ) {
		if (strcmp(tmp_nam, man[i].nam)) {
			if (i != 0)
				printf("Total amount: $%.2f\n", sum / 100.0);
			printf("%s %02d\n", man[i].nam, man[i].MM);
			strcpy(tmp_nam, man[i].nam);
			sum = 0.0;
		}
		if (i + 1 == n)    break;
		if (man[i].lab == 1 && man[i + 1].lab == 0) {
			dol = 0.0;
			dur = 0;
			calc_time(man[i], man[i + 1], &dol, &dur);
			sum += dol;
			flag = true;
		}
		if (flag) {
			printf("%02d:%02d:%02d ", man[i].dd, man[i].HH, man[i].mm);
			printf("%02d:%02d:%02d ", man[i + 1].dd, man[i + 1].HH, man[i + 1].mm);
			printf("%d $%.2f\n", dur, dol / 100.0);
			flag = false;
			i += 2;
		} else    i += 1;
	}
	printf("Total amount: $%.2f\n", sum / 100.0);

	return 0;
}