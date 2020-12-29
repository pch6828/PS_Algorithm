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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int n, m, k, Size, cnt, root;
ll d[100001], st[100001], en[100001];
vector<ll>SegTree, lazy;
vector<int>adj[100001];

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

void lazyUpdate(int idx, int L, int R)
{
	if (lazy[idx] == 0) return;
	SegTree[idx] += (R - L + 1) * lazy[idx];
	if (L != R)
	{
		lazy[2 * idx] += lazy[idx];
		lazy[2 * idx + 1] += lazy[idx];
	}
	lazy[idx] = 0;
}

void update(int idx, int curL, int curR, int dstL, int dstR, ll val)
{
	lazyUpdate(idx, curL, curR);
	if (curR < dstL || dstR < curL) return;
	if (dstL <= curL && curR <= dstR)
	{
		lazy[idx] += val;
		lazyUpdate(idx, curL, curR);
		return;
	}
	int mid = (curL + curR) / 2;
	update(2 * idx, curL, mid, dstL, dstR, val);
	update(2 * idx + 1, mid + 1, curR, dstL, dstR, val);
	SegTree[idx] = SegTree[2 * idx] + SegTree[2 * idx + 1];
}

ll Get(int idx, int curL, int curR, int dstL, int dstR)
{
	lazyUpdate(idx, curL, curR);
	if (curR < dstL || dstR < curL)
	{
		return 0;
	}
	if (dstL <= curL && curR <= dstR)
	{
		return SegTree[idx];
	}
	int mid = (curL + curR) / 2;
	return Get(2 * idx, curL, mid, dstL, dstR) + Get(2 * idx + 1, mid + 1, curR, dstL, dstR);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		if (a != -1) {
			adj[a].push_back(i);
		}
		else {
			root = i;
		}
	}

	dfs(root);

	Size = (1 << ((int)ceil(log2(n)) + 1));
	SegTree.resize(Size);
	lazy.resize(Size);

	while (m--)
	{
		int cmd;
		cin >> cmd;

		if (cmd == 1)
		{
			int a;
			ll c;
			cin >> a >> c;

			update(1, 1, Size / 2, st[a], en[a], c);
		}
		else
		{
			int a;
			cin >> a;
			cout << Get(1, 1, Size / 2, st[a], st[a]) << "\n";
		}
	}
}