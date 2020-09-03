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
#include<complex>

using namespace std;

#define LIMIT 10000000000000000
#define MOD 1000000007
#define MXH 21
#define SIZE 50005

const double PI = acos(-1);

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> cpx;
typedef vector<cpx> vec;

int n, Size;
ll ans, flowers[100001];
vector<ll>SegTree, lazy;

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

	Size = (1 << ((int)ceil(log2(100000)) + 1));
	SegTree.resize(Size);
	lazy.resize(Size);

	cin >> n;

	while (n--) {
		int l, r;
		cin >> l >> r;
		ll sum_l = Get(1, 1, Size / 2, l, l) - flowers[l];
		ll sum_r = Get(1, 1, Size / 2, r, r) - flowers[r];
		flowers[l] += sum_l;
		flowers[r] += sum_r;
		cout << sum_l + sum_r << "\n";

		l++;
		r--;
		if (l > r) {
			continue;
		}
		update(1, 1, Size / 2, l, r, 1);

	}
}


