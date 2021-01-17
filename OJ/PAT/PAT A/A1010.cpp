#include <cstdio>

const int maxn = 10;

int hash_val(char ch) {
	if (ch >= '0' && ch <= '9')    return ch - '0';
	else    return ch - 'a' + 10;
}

long long val_of_radix(char str[], long long rad, int len) {
	long long sum = 0;
	for (int i = 0; i < len; ++i) {
		sum *= rad;
		sum += hash_val(str[i]);
	}

	return sum;
}

int main() {
	char n1[maxn] = { 0 }, n2[maxn] = { 0 };
	char cha, *fst_str, *oth_str;//first str, other str
	int tag;
	int n1_len = 0, n2_len = 0, fst_len, oth_len;
	long long rad, fst_num;

	//1. INPUT
	while (scanf("%c", &cha), cha != ' ')    n1[n1_len++] = cha;
	while (scanf("%c", &cha), cha != ' ')    n2[n2_len++] = cha;
	scanf("%d%lld", &tag, &rad);
	if (tag == 1) {
		fst_str = n1;
		oth_str = n2;
		fst_len = n1_len;
		oth_len = n2_len;
	} else {
		fst_str = n2;
		oth_str = n1;
		fst_len = n2_len;
		oth_len = n1_len;
	}
	fst_num = val_of_radix(fst_str, rad, fst_len);

	//2. EXECUTE
	long long tmp = 0;
	rad = 0;
    ///2-1. FIND SMALLEST RADIX OF OTHER DIGIT
	for (int i = 0; i < oth_len; ++i) {
		tmp = hash_val(oth_str[i]);
		if (tmp > rad)    rad = tmp;
	}
	rad++;
    ///2-2. TRAVERSAL OTHER DIGIT FOR ALL RADIX
	while (rad <= 36) {
		tmp = val_of_radix(oth_str, rad, oth_len);
		if (tmp == fst_num)    break;
		else    rad++;
	}

	//3. OUTPUT
	if (rad <= 36)    printf("%lld\n", rad);
	else    printf("Impossible\n");

	return 0;
}