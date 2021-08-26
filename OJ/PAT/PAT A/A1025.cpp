#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct record_t {
	string id;
	int score, addr, rank_local, rank_total;
}rec_t;

const int maxn = 30001;
int n, k;
vector<rec_t > people;

bool cmp(rec_t a, rec_t b) {
	if (a.score != b.score)    return a.score > b.score;
	else    return a.id < b.id;
}

int main() {
	/* 1. INPUT MODULE */
	int beg = 0, end = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> k;
		end += k;
		//输入
		for (int j = 0; j < k; ++j) {
			rec_t tmp;
			cin >> tmp.id >> tmp.score;
			tmp.addr = i;
			people.push_back(tmp);
		}

		//局部排序
		sort(people.begin() + beg, people.begin() + end, cmp);
		people[beg].rank_local = 1;
		for (int j = beg + 1; j < end; ++j) {
			if (people[j].score == people[j - 1].score)    people[j].rank_local = people[j - 1].rank_local;
			else    people[j].rank_local = j - beg + 1;
		}
		beg = end;
	}

	/* 2. MAIN LOGIC */
	//总体排序
	sort(people.begin(), people.end(), cmp);
	people[0].rank_total = 1;
	for (int i = 1; i < end; ++i) {
		if (people[i].score == people[i - 1].score)    people[i].rank_total = people[i - 1].rank_total;
		else    people[i].rank_total = i + 1;
	}

	/* 3. OUTPUT MODULE */
	cout << end << endl;
	for (int i = 0; i < end; ++i)    cout << people[i].id << " " << people[i].rank_total << " " << people[i].addr << " " << people[i].rank_local << endl;

	return 0;
}