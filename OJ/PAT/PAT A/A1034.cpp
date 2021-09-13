/* A1034, PA(22/30) */
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct vertex_t {
	int v, w;
}ver_t;

typedef struct outcome_t {
	string id;
	int num;
}out_t;

const int maxn = 2000;
int n, k, tot;
map<string, int > s2i;
map<int, string > i2s;
vector<ver_t > graph[maxn];
int wei[maxn], head[maxn];
bool vis[maxn], ing[maxn];
vector<out_t > out;

void dfs(int v) {
	vis[v] = true;
	ing[v] = true;
	tot += wei[v];
	for (int i = 0; i < (int)graph[v].size(); ++i) {
		head[v] += graph[v][i].w;

		int nxt = graph[v][i].v;
		if (!vis[nxt])    dfs(nxt);
	}
}

bool cmp(out_t a, out_t b) {
	return a.id < b.id;
}

int main() {
	/* 1. INPUT MODULE */
	cin >> n >> k;
	int cr = 0;
	for (int i = 0; i < n; ++i) {
		string s1, s2;
		int weight;
		cin >> s1 >> s2 >> weight;

		//建立映射
		if (s2i.find(s1) == s2i.end()) {
			s2i[s1] = cr;
			i2s[cr] = s1;
			cr++;
		}
		if (s2i.find(s2) == s2i.end()) {
			s2i[s2] = cr;
			i2s[cr] = s2;
			cr++;
		}

		//初始化图
		wei[s2i[s2]] = weight;
		if (graph[s2i[s1]].empty()) {
			ver_t tmp;
			tmp.v = s2i[s2];
			tmp.w = weight;
			graph[s2i[s1]].push_back(tmp);
		} else {
			int j = 0;
			for (; j < (int)graph[s2i[s1]].size(); ++j) {
				if (graph[s2i[s1]][j].v == s2i[s2]) {
					graph[s2i[s1]][j].w += weight;
					break;
				}
			}
			if (j == (int)graph[s2i[s1]].size()) {
				ver_t tmp;
				tmp.v = s2i[s2];
				tmp.w = weight;
				graph[s2i[s1]].push_back(tmp);
			}
		}

		if (graph[s2i[s2]].empty()) {
			ver_t tmp;
			tmp.v = s2i[s1];
			tmp.w = weight;
			graph[s2i[s2]].push_back(tmp);
		}
		else {
			int j = 0;
			for (; j < (int)graph[s2i[s2]].size(); ++j) {
				if (graph[s2i[s2]][j].v == s2i[s1]) {
					graph[s2i[s2]][j].w += weight;
					break;
				}
			}
			if (j == (int)graph[s2i[s2]].size()) {
				ver_t tmp;
				tmp.v = s2i[s1];
				tmp.w = weight;
				graph[s2i[s2]].push_back(tmp);
			}
		}
	}

	/* 2. MAIN LOGIC */
	int gang = 0;
	for (int i = 0; i < cr; ++i) {
		memset(ing, false, sizeof(ing));
		tot = 0;
		if (!vis[i])    dfs(i);

		int num = 0, max = -1, max_id = 0;
		for (int j = 0; j < cr; ++j) {
			if (ing[j]) {
				num++;
				if (max < head[j]) {
					max = head[j];
					max_id = j;
				}
			}
		}

		if (tot > k && num > 2) {
			gang++;
			out_t tmp;
			tmp.id = i2s[max_id]; tmp.num = num;
			out.push_back(tmp);
		}
	}

	/* 3. OUTPUT MODULE */
	sort(out.begin(), out.end(), cmp);
	cout << (int)out.size() << endl;
	for (int i = 0; i < (int)out.size(); ++i)
		cout << out[i].id << " " << out[i].num << endl;

	return 0;
}