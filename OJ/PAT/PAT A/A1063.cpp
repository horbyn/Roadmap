#include <cstdio>
#include <vector>
#include <set>
using namespace std;

static const int maxn = 50;
static const int maxk = 2000;

set<int> set_tot[maxn];//set total
vector<vector<int> > set_pai(maxk);//set total

static bool
set_cmp(set<int>& s2, set<int>::iterator& it) {
	set<int>::iterator it_tmp = s2.find(*it);
	if (it_tmp == s2.end())    return false;
	else    return true;
}

int main() {
	int n, k, m;

	//1. INPUT
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &k);
		for (int j = 0; j < k; ++j) {
			int inp;
			scanf("%d", &inp);
			set_tot[i].insert(inp);
		}
	}
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < 2; ++j) {
			int inp;
			scanf("%d", &inp);
			set_pai[i].push_back(inp);
		}
	}

	//2. EXECUTE
	int and_set, or_set;
	for (int i = 0; i < m; ++i) {
		int idx1 = set_pai[i][0] - 1;
		int idx2 = set_pai[i][1] - 1;
		and_set = set_tot[idx2].size();
		or_set = 0;
		for (set<int>::iterator it = set_tot[idx1].begin();
			it != set_tot[idx1].end(); ++it) {
			if (set_cmp(set_tot[idx2], it)) {
				//另一个集合有，交集+1
				or_set++;
			} else {
				//另一集合没有，并集+1
				and_set++;
			}
		}
		printf("%.1lf%%\n", (double)or_set / and_set * 100);
	}

	return 0;
}