#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct graph_t {
	string           name;
	int              own_wei;//own weight
	int              tot_wei;//total weight
	vector<graph_t > rel;//relation
};

struct out_t {
	string max;
	int    num;
};

const int maxn = 26 * 26 * 26 + 1;
graph_t g[maxn];
bool vis[maxn];
vector<graph_t > temp;
vector<string > inp;
vector<out_t > out;
int k;

bool cmp1(graph_t a, graph_t b) {
	return a.tot_wei > b.tot_wei;
}

bool cmp2(out_t a, out_t b) {
	return a.max < b.max;
}

int hash_trans(string s, int n) {
	int sum = 0;
	for (int i = 0; i < n; ++i)
		sum += sum * 26 + (s[i] - 'A');
	return sum;
}

void dfs(graph_t u) {
	temp.push_back(u);
	vis[hash_trans(u.name, 3)] = true;
	for (int i = 0; i < (int)u.rel.size(); ++i) {
		int idx = hash_trans(u.rel[i].name, 3);
		if (!vis[idx])    dfs(g[idx]);
	}
}

bool is_greater_k() {
	int sum = 0;
	for (int i = 0; i < (int)temp.size(); ++i)
		sum += temp[i].own_wei;
	return sum > k;
}

void dfs_trans(vector<string >& v) {
	for (int i = 0; i < (int)v.size(); ++i) {
		int idx = hash_trans(v[i], 3);
		if (!vis[idx]) {
			dfs(g[idx]);
			if (temp.size() > 2 && is_greater_k()) {
				sort(temp.begin(), temp.end(), cmp1);
				out_t out_temp;
				out_temp.max = temp[0].name;
				out_temp.num = temp.size();
				out.push_back(out_temp);
			}
			temp.clear();
		}
	}
}

void inp_to_graph(string& s) {
	string s1, s2;
	int w, len = 0, idx1, idx2;
	s1 = s.substr(0, 3); idx1 = hash_trans(s1, 3);
	s2 = s.substr(4, 3); idx2 = hash_trans(s2, 3);
	for (int i = 8; i < (int)s.size(); ++i)    ++len;
	w = atoi((s.substr(8, len)).c_str());

	//1. 保存顶点
	if (!vis[idx1]) {
		vis[idx1] = true;
		g[idx1].name = s1;
		inp.push_back(s1);
	}
	if (!vis[idx2]) {
		vis[idx2] = true;
		g[idx2].name = s2;
		inp.push_back(s2);
	}
	//2. 串连关系（单向）: A -> B
	g[idx1].rel.push_back(g[idx2]);
	//3. 计算自己权值
	g[idx1].own_wei += w;
	//4. 计算总权值
	g[idx1].tot_wei += w;
	g[idx2].tot_wei += w;
}

int main() {
	int n;
	string str;

	//1. 输入
	cin >> n >> k;
	cin.ignore();
	memset(g, 0, maxn);
	for (int i = 0; i < n; ++i) {
		getline(cin, str);
		inp_to_graph(str);
	}
	memset(vis, 0, maxn);

	//2. 主逻辑
	dfs_trans(inp);

	//3. 输出
	cout << out.size() << endl;
	sort(out.begin(), out.end(), cmp2);
	for (int i = 0; i < (int)out.size(); ++i)
		cout << out[i].max << " " << out[i].num << endl;

	return 0;
}