#include<cstdio>
#include<climits>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#include<deque>
#include<list>
#include<string>
#include<iostream>
#include<algorithm>
#include<functional>
#include<cassert>
#include<fstream>

using namespace std;

#define LIMIT 10000000000000000
#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int n, m, k, Size, cnt;
ll d[200001], st[200001], en[200001];
vector<vector<int>>SortMergeTree;
vector<int>adj[200001];

void dfs(int now) {
	cnt++;
	st[now] = cnt;
	for (int nxt : adj[now]) {
		if (!st[nxt]) {
			dfs(nxt);
		}
	}
	en[now] = cnt;
}

void Update(int target, int idx, int now_L, int now_R, int value) {
	if (idx < now_L || idx > now_R) {
		return;
	}
	SortMergeTree[target].push_back(value);
	if (now_L != now_R) {
		Update(target * 2, idx, now_L, (now_L + now_R) / 2, value);
		Update(target * 2 + 1, idx, (now_L + now_R) / 2 + 1, now_R, value);
	}
}

int Get(int target, int L, int R, int now_L, int now_R, int value) {
	if (L > now_R || R < now_L)
	{
		return 0;
	}
	if (L <= now_L && now_R <= R)
	{
		return upper_bound(SortMergeTree[target].begin(), SortMergeTree[target].end(), value) - SortMergeTree[target].begin();
	}

	return Get(target * 2, L, R, now_L, (now_L + now_R) / 2, value) + Get(target * 2 + 1, L, R, (now_L + now_R) / 2 + 1, now_R, value);
}

int Binary_Search(int l, int r, int a, int b, int target) {
	int mid = (l + r) / 2;
	if (l == r) {
		return l;
	}
	ll result = Get(1, a, b, 1, n, mid);
	if (result < target) {
		return Binary_Search(mid + 1, r, a, b, target);
	}
	else {
		return Binary_Search(l, mid, a, b, target);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;
	
	Size = (1 << ((int)ceil(log2(n)) + 1));
	SortMergeTree.resize(Size);

	for (int i = 1; i <= n; i++) {
		cin >> d[i];
	}

	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1);

	for (int i = 1; i <= n; i++) {
		Update(1, st[i], 1, n, d[i]);
	}

	for (auto& v : SortMergeTree) {
		sort(v.begin(), v.end());
	}

	int ans = 0;
	while (m--) {
		int a, b;
		cin >> a >> b;
		int temp = Get(1, st[a], en[a], 1, n, b);
		ans += temp;
		ans %= MOD;
	}
	cout << ans;
}


