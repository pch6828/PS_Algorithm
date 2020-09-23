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

int n, t, q, Size;
ll sum;
vector<ll>SegTree, lazy, position;
vector<pii>query;
unordered_map<ll, int>idx;

void lazyUpdate(int idx, int L, int R)
{
	if (lazy[idx] == 0) return;
	SegTree[idx] = max(SegTree[idx], lazy[idx]);
	if (L != R)
	{
		lazy[2 * idx] = max(lazy[2 * idx], lazy[idx]);
		lazy[2 * idx + 1] = max(lazy[2 * idx + 1], lazy[idx]);
	}
	lazy[idx] = 0;
}

void Update(int idx, int curL, int curR, int dstL, int dstR, ll val)
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
	Update(2 * idx, curL, mid, dstL, dstR, val);
	Update(2 * idx + 1, mid + 1, curR, dstL, dstR, val);
	SegTree[idx] = max(SegTree[2 * idx], SegTree[2 * idx + 1]);
}

ll Get_Max(int idx, int curL, int curR, int dstL, int dstR)
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
	return max(Get_Max(2 * idx, curL, mid, dstL, dstR), Get_Max(2 * idx + 1, mid + 1, curR, dstL, dstR));
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	while (n--) {
		int a, b;
		cin >> a >> b;
		query.push_back({ b, a + b });
		position.push_back(b);
		position.push_back(a + b);
	}

	sort(position.begin(), position.end());
	for (int i = 0; i < position.size(); i++) {
		idx[position[i]] = i + 1;
	}
	Size = (1 << ((int)ceil(log2(position.size())) + 1));
	SegTree.resize(Size);
	lazy.resize(Size);


	for (pii p : query) {
		int a, b;
		a = idx[p.first];
		b = idx[p.second];
		int m = Get_Max(1, 1, Size / 2, a, b - 1);
		Update(1, 1, Size / 2, a, b - 1, m + 1);
	}
	cout << Get_Max(1, 1, Size / 2, 1, Size / 2);
}