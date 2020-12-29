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

int n, m, Size;
vector<ll>lazy;
vector<ll>SumTree, MinTree;

void lazyUpdate(int idx, int L, int R)
{
	if (lazy[idx] == 0) return; //lazy 가 없는 경우
	SumTree[idx] += (R - L + 1) * lazy[idx]; // lazy 적용
	MinTree[idx] += lazy[idx];
	if (L != R)
	{
		//Leaf Node 가 아닌 경우, 자식 노드에 전파 
		lazy[2 * idx] += lazy[idx];
		lazy[2 * idx + 1] += lazy[idx];
	}
	lazy[idx] = 0; // lazy 초기화
}

void Update(int idx, int curL, int curR, int dstL, int dstR, ll val)
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
	Update(2 * idx, curL, mid, dstL, dstR, val);
	Update(2 * idx + 1, mid + 1, curR, dstL, dstR, val);
	SumTree[idx] = SumTree[2 * idx] + SumTree[2 * idx + 1];
	MinTree[idx] = min(MinTree[2 * idx], MinTree[2 * idx + 1]);
}

ll Get_Sum(int idx, int curL, int curR, int dstL, int dstR)
{
	lazyUpdate(idx, curL, curR);
	if (curR < dstL || dstR < curL)
	{
		return 0;
	}
	if (dstL <= curL && curR <= dstR)
	{
		return SumTree[idx];
	}
	int mid = (curL + curR) / 2;
	return Get_Sum(2 * idx, curL, mid, dstL, dstR) + Get_Sum(2 * idx + 1, mid + 1, curR, dstL, dstR);
}

ll Get_Min(int idx, int curL, int curR, int dstL, int dstR)
{
	lazyUpdate(idx, curL, curR);
	if (curR < dstL || dstR < curL)
	{
		return LLONG_MAX;
	}
	if (dstL <= curL && curR <= dstR)
	{
		return MinTree[idx];
	}
	int mid = (curL + curR) / 2;
	return min(Get_Min(2 * idx, curL, mid, dstL, dstR), Get_Min(2 * idx + 1, mid + 1, curR, dstL, dstR));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	Size = (1 << ((int)ceil(log2(n)) + 1));
	SumTree.resize(Size);
	MinTree.resize(Size);
	lazy.resize(Size);
	for (int i = 1; i <= n; i++)
	{
		cin >> SumTree[i + Size / 2 - 1];
		MinTree[i + Size / 2 - 1] = SumTree[i + Size / 2 - 1];
	}
	for (int i = Size / 2 - 1; i >= 1; i--)
	{
		SumTree[i] = SumTree[i * 2] + SumTree[i * 2 + 1];
		MinTree[i] = min(MinTree[i * 2], MinTree[i * 2 + 1]);
	}

	while (m--) {
		string cmd;
		int a, b;
		cin >> cmd >> a >> b;

		if (cmd == "M") {
			cout << Get_Min(1, 1, Size / 2, a, b) << "\n";
		}
		else if (cmd == "S") {
			cout << Get_Sum(1, 1, Size / 2, a, b) << "\n";
		}
		else {
			ll val;
			cin >> val;

			Update(1, 1, Size / 2, a, b, val);
		}
	}

}


