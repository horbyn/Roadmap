#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

typedef struct worth_t {
	string name;
	int age, worth;
}worth_t;

typedef struct query_t {
	int num, min, max;
}query_t;

const int maxn = 100000;
int n, k;
worth_t hash_name[maxn], age[maxn], tmp[maxn];
map<string, int > s2i;
query_t query[maxn];

/* 排序一: 按年龄排 */
bool cmp1(worth_t a, worth_t b) {
	return a.age < b.age;
}

/* 排序二: 结构体之间排序 */
bool cmp2(worth_t a, worth_t b) {
	if (a.worth != b.worth)    return a.worth > b.worth;
	else if (a.age != b.age)    return a.age < b.age;
	else    return a.name < b.name;
}

int main() {
	/* 1. INPUT MODULE */
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> hash_name[i].name >> hash_name[i].age >> hash_name[i].worth;
		s2i.insert(make_pair(hash_name[i].name, i));//若键重复则放弃加入 map
	}
	for (int i = 0; i < k; ++i)    cin >> query[i].num >> query[i].min >> query[i].max;

	/* 2. MAIN LOGIC */
	for (int i = 0; i < n; ++i)    age[i] = hash_name[i];
	sort(age, age + n, cmp1);//按年龄排序所有记录
	//遍历 query
	for (int i = 0; i < k; ++i) {
		cout << "Case #" << i + 1 << ":\n";

		//确定年龄范围
		int age_min = query[i].min, age_max = query[i].max;
		int low = -1, high = -1;
		for (int j = 0; j < n; ++j) {//确定年龄范围
			if (low != -1 && high != -1)    break;
			if (age[j].age >= age_min && low == -1)    low = j;
			if (age[j].age >= age_max && high == -1)    high = age[j].age == age_max ? j : j - 1;
		}
		if (low > high) {
			cout << "None\n";
			continue;
		}
		
		/* 3. OUTPUT MODULE */
		for (int j = low; j <= high; ++j)    tmp[j - low] = age[j];
		sort(tmp, tmp + (high - low + 1), cmp2);//结构体之间排序
		int len = query[i].num < high - low + 1 ? query[i].num : high - low + 1;
		for (int j = 0; j < len; ++j) {
			string name = tmp[j].name;
			int idx = s2i[name];
			cout << hash_name[idx].name << " " << hash_name[idx].age << " " << hash_name[idx].worth << endl;
		}
	}
	return 0;
}