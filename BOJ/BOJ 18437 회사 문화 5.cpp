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

int n, m, k, Size, cnt;
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
	if (lazy[idx] == -1) return;
	SegTree[idx] = (R - L + 1) * lazy[idx];
	if (L != R)
	{
		lazy[2 * idx] = lazy[idx];
		lazy[2 * idx + 1] = lazy[idx];
	}
	lazy[idx] = -1;
}

void update(int idx, int curL, int curR, int dstL, int dstR, ll val)
{
	lazyUpdate(idx, curL, curR);
	if (curR < dstL || dstR < curL) return;
	if (dstL <= curL && curR <= dstR)
	{
		lazy[idx] = val;
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

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		if (a != 0) {
			adj[a].push_back(i);
		}
	}

	dfs(1);

	Size = (1 << ((int)ceil(log2(n)) + 1));
	SegTree.resize(Size, 1);
	lazy.resize(Size, -1);

	for (int i = Size / 2 - 1; i >= 1; i--)
	{
		SegTree[i] = SegTree[i * 2] + SegTree[i * 2 + 1];
	}

	cin >> m;
	
	while (m--)
	{
		int cmd, a;
		cin >> cmd >> a;

		if (cmd == 1)
		{
			if (st[a] == en[a]) {
				continue;
			}
			update(1, 1, Size / 2, st[a] + 1, en[a], 1);
		}
		else if (cmd == 2) {
			if (st[a] == en[a]) {
				continue;
			}
			update(1, 1, Size / 2, st[a] + 1, en[a], 0);
		}
		else {
			if (st[a] == en[a]) {
				cout << 0 << "\n";
				continue;
			}
			cout << Get(1, 1, Size / 2, st[a]+1, en[a]) << "\n";
		}
	}
}