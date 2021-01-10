#include <cstdio>

#pragma warning(disable: 4996)

#define MAXSIZE 80

using namespace std;

struct has_t {//hash
	bool has;//hash
	bool dis;//display
}has[63] = { 0 };

int hash_table(char cha) {
	if (cha >= 'A' && cha <= 'Z')    return cha - 'A';
	else if (cha >= 'a' && cha <= 'z')    return cha - 'a' + 26;
	else if (cha >= '0' && cha <= '9')    return cha - '0' + 52;
	else    return 62;
}

int main() {
	char ori[MAXSIZE] = { 0 }, typ[MAXSIZE] = { 0 };//original; typed-out

	//1. INPUT: storage two string
	scanf("%s%s", ori, typ);

	//2. EXECUTE: the broken string translate to hash value
	char* s = typ;
	int idx = 0;
	while (*s) {
		idx = hash_table(*s);
		has[idx].has = true;
		s++;
	}

	//3. OUTPUT: traversal the original string
	s = ori;
	char tmp;
	while (*s) {
		idx = hash_table(*s);
		if (!has[idx].has) {
			if ((*s >= 'A' && *s <= 'Z')
				|| (*s >= 'a' && *s <= 'z')) {
				tmp = *s ^ 32;// translate to CAP or low
				if (!has[idx].dis && !has[hash_table(tmp)].dis) {
					has[idx].dis = true;
					has[hash_table(tmp)].dis = true;
					printf("%c", *s & 223);// always CAP;
				}
			} else {
				has[idx].dis = true;
				printf("%c", *s);
			}
		}
		s++;
	}

	return 0;
}