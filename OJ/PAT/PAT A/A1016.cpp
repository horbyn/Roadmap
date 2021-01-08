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

bool cmp(struct man_t a, struct man_t b) {
	if (a.nam != b.nam)    return strcmp(a.nam, b.nam) < 0;
	else if (a.dd != b.dd)    return a.dd < b.dd;
	else if (a.HH != b.HH)    return a.HH < b.HH;
	else    return a.mm < b.mm;
}

int calc_time(struct man_t a, struct man_t b) {
	return 1;
}

int main() {
	return 0;
}