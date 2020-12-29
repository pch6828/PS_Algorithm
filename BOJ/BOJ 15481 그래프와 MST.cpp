#include<cstdio>
#include<climits>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<cassert>
#include<vector>
#include<iostream>
#include<fstream>
#include<sstream>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<deque>
#include<list>
#include<string>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<random>

using namespace std;

#define LIMIT 10000000000000000
#define MOD 1000000007
#define PI 3.14159265359
#define MXH 21
#define SIZE 200005

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

typedef struct {
	int a, b, idx;
	ll weight;
}Edge;

bool cmp(Edge& e1, Edge& e2) {
	return e1.weight < e2.weight;
}

int root[SIZE], n, m, max_edge[SIZE], used[200000];
vector<Edge>edges;

int Find(int a) {
	if (a == root[a]) {
		return a;
	}
	return root[a] = Find(root[a]);
}

bool Union(int a, int b) {
	int ra = Find(a), rb = Find(b);

	if (ra == rb) {
		return false;
	}

	root[ra] = rb;
	return true;
}

vector<pii>adj[SIZE];
int level[SIZE];
int parent[MXH][SIZE], max_weight[MXH][SIZE];

void dfs(int now, int par, int lvl, int d) {
	parent[0][now] = par;
	max_weight[0][now] = d;
	level[now] = lvl;

	for (auto nxt : adj[now]) {
		int a = nxt.first, dist_a = nxt.second;
		if (par != a) {
			dfs(a, now, lvl + 1, dist_a);
		}
	}
}

void memo() {
	for (int i = 1; i < MXH; i++) {
		for (int j = 1; j <= n; j++) {
			parent[i][j] = parent[i - 1][parent[i - 1][j]];
			max_weight[i][j] = max(max_weight[i - 1][j], max_weight[i - 1][parent[i - 1][j]]);
		}
	}
}

int level_up(int now, int diff) {
	for (int i = MXH - 1; i >= 0; i--) {
		if (diff & (1 << i)) {
			now = parent[i][now];
		}
	}
	return now;
}

int LCA(int a, int b) {
	a = level_up(a, max(0, level[a] - level[b]));
	b = level_up(b, max(0, level[b] - level[a]));

	if (a == b) {
		return a;
	}

	for (int i = MXH - 1; i >= 0; i--) {
		if (parent[i][a] != parent[i][b]) {
			a = parent[i][a];
			b = parent[i][b];
		}
	}

	return parent[0][a];
}

int LCA_MAX(int a, int b, ll weight) {
	int lca = LCA(a, b);
	int now, diff, res = 0;;

	now = a;
	diff = max(0, level[a] - level[lca]);

	for (int i = MXH - 1; i >= 0; i--) {
		if (diff & (1 << i)) {
			res = max(res, max_weight[i][now]);
			now = parent[i][now];
		}
	}

	now = b;
	diff = max(0, level[b] - level[lca]);

	for (int i = MXH - 1; i >= 0; i--) {
		if (diff & (1 << i)) {
			res = max(res, max_weight[i][now]);
			now = parent[i][now];
		}
	}
	return res;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		root[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		ll w;
		cin >> a >> b >> w;
		edges.push_back({ a, b, i, w });
	}

	sort(edges.begin(), edges.end(), cmp);
	ll mst = 0;
	for (int i = 0; i < m; i++) {
		if (Union(edges[i].a, edges[i].b)) {
			adj[edges[i].a].push_back({ edges[i].b , edges[i].weight });
			adj[edges[i].b].push_back({ edges[i].a , edges[i].weight });
			used[i] = true;
			mst += edges[i].weight;
		}
	}

	dfs(1, 0, 0, 0);
	memo();

	vector<ll>ans(m);
	for (int i = 0; i < m; i++) {
		int max_edge = LCA_MAX(edges[i].a, edges[i].b, edges[i].weight);
		ans[edges[i].idx] = mst - max_edge + edges[i].weight;
	}

	for (auto a : ans) {
		cout << a << "\n";
	}
}

