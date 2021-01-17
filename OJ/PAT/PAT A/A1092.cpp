#include <cstdio>
#define MAXSIZE 1000

int hash(char cha) {
	if (cha >= 'A' && cha <= 'Z')    return cha - 'A';
	else if (cha >= 'a' && cha <= 'z')    return cha - 'a' + 26;
	else if (cha >= '0' && cha <= '9')    return cha - '0' + 52;
}

int main() {
	int has_tab[62] = { 0 };
	int own_num = 0, eva_num = 0;
	int ext = 0, dif = 0;
	bool flag = false;

	char ch;
	while (1) {
		scanf("%c", &ch);
		if (ch == '\n')    break;
		own_num++;
		has_tab[hash(ch)]++;
	}
	int cou = 0;//count
	while (1) {
		scanf("%c", &ch);
		if (ch == '\n')    break;
		eva_num++;
		has_tab[hash(ch)]--;
		if (has_tab[hash(ch)] < 0) {
			dif++;
			has_tab[hash(ch)] = 0;
		} else    cou++;
	}
	if (cou == eva_num) {
		flag = true;
		ext = own_num - eva_num;
	}

	if (flag)    printf("Yes %d", ext);
	else    printf("No %d", dif);
	return 0;
}