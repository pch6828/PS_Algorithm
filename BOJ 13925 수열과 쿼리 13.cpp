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

#define MOD 1000000007

ll n, m, k, Size;
long long d[1000005];
vector<pair<ll, ll>>lazy;
vector<long long>SegTree;

void lazyUpdate(int idx, int L, int R)
{
	if (lazy[idx].first == 1 && lazy[idx].second == 0) return; //lazy 가 없는 경우
	SegTree[idx] *= lazy[idx].first;
	SegTree[idx] %= MOD;
	SegTree[idx] += (R - L + 1) * lazy[idx].second; 
	SegTree[idx] %= MOD;// lazy 적용

	if (L != R)
	{
		//Leaf Node 가 아닌 경우, 자식 노드에 전파 
		lazy[2 * idx].first *= lazy[idx].first; 
		lazy[2 * idx + 1].first *= lazy[idx].first;
		lazy[2 * idx].first %= MOD; 
		lazy[2 * idx + 1].first %= MOD;
		lazy[2 * idx].second *= lazy[idx].first; 
		lazy[2 * idx + 1].second *= lazy[idx].first;
		lazy[2 * idx].second %= MOD; 
		lazy[2 * idx + 1].second %= MOD;
		lazy[2 * idx].second += lazy[idx].second; 
		lazy[2 * idx + 1].second += lazy[idx].second;
		lazy[2 * idx].second %= MOD; 
		lazy[2 * idx + 1].second %= MOD;

	}
	lazy[idx].first = 1;
	lazy[idx].second = 0;// lazy 초기화
}

void update(int idx, int curL, int curR, int dstL, int dstR, ll a, ll b)
{
	lazyUpdate(idx, curL, curR); //Lazy가 있는 경우 그것을 적용
	if (curR < dstL || dstR < curL) return; //update 구간을 벗어나는 경우
	if (dstL <= curL && curR <= dstR)
	{
		//현재 구간이 update 구간에 포함되는 경우 
		lazy[idx].first *= a;
		lazy[idx].first %= MOD;
		lazy[idx].second *= a;
		lazy[idx].second %= MOD;
		lazy[idx].second += b;
		lazy[idx].second %= MOD;
		lazyUpdate(idx, curL, curR); //Lazy 생성 및 적용하고 반환 
		return;
	}
	int mid = (curL + curR) / 2; // 이 밑으로는 일반 Segment Tree와 동일! 
	update(2 * idx, curL, mid, dstL, dstR, a, b);
	update(2 * idx + 1, mid + 1, curR, dstL, dstR, a, b);
	SegTree[idx] = SegTree[2 * idx] + SegTree[2 * idx + 1];
	SegTree[idx] %= MOD;
}

long long Get(int idx, int curL, int curR, int dstL, int dstR)
{
	lazyUpdate(idx, curL, curR);
	//Lazy가 있는 경우 그것을 적용
	// 이 밑으로는 일반 Segment Tree와 동일!
	if (curR < dstL || dstR < curL)
	{
		//Get 구간을 벗어나는 경우
		return 0;
	}
	if (dstL <= curL && curR <= dstR)
	{
		//현재 구간이 Get 구간에 포함되는 경우 
		return SegTree[idx] % MOD;
	}
	int mid = (curL + curR) / 2;
	return (Get(2 * idx, curL, mid, dstL, dstR) + Get(2 * idx + 1, mid + 1, curR, dstL, dstR)) % MOD;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> d[i];
	}
	cin >> m;
	Size = (1 << ((int)ceil(log2(n)) + 1));
	SegTree.resize(Size);
	lazy.resize(Size, { 1, 0 });

	for (int i = 1; i <= n; i++)
	{
		SegTree[i + Size / 2 - 1] = d[i];
	}
	for (int i = Size / 2 - 1; i >= 1; i--)
	{
		SegTree[i] = (SegTree[i * 2] + SegTree[i * 2 + 1]) % MOD;
	}

	while (m--)
	{
		int cmd;
		int a, b;
		long long c;
		cin >> cmd;

		if (cmd == 1)
		{
			cin >> a >> b >> c;
			update(1, 1, Size / 2, a, b, 1, c);
		}
		else if (cmd == 2) {
			cin >> a >> b >> c;
			update(1, 1, Size / 2, a, b, c, 0);
		}
		else if (cmd == 3) {
			cin >> a >> b >> c;
			update(1, 1, Size / 2, a, b, 0, c);
		}
		else {
			cin >> a >> b;
			cout << Get(1, 1, Size / 2, a, b) << "\n";
		}
	}

}