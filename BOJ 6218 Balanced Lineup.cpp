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
#include<algorithm>
#include<functional>
#include<numeric>

using namespace std;

#define LIMIT 10000000000000000
#define MOD 1000000007
#define PI 3.14159265359
#define SIZE 1000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int n, m, Size, d[1000005];
vector<pair<int, int>>SegTree;

void Update(int index, int x)
{
	index += Size / 2 - 1;
	SegTree[index] = { x, x };
	while (index > 1)
	{
		index /= 2;
		SegTree[index].first = min(SegTree[index * 2].first, SegTree[index * 2 + 1].first);
		SegTree[index].second = max(SegTree[index * 2].second, SegTree[index * 2 + 1].second);
	}
}

int minimum(int L, int R, int now_L, int now_R, int index)
{
	if (L > now_R || R < now_L)
	{
		return INT_MAX;
	}
	if (L <= now_L && now_R <= R)
	{
		return SegTree[index].first;
	}

	return min(minimum(L, R, now_L, (now_L + now_R) / 2, index * 2), minimum(L, R, (now_L + now_R) / 2 + 1, now_R, index * 2 + 1));
}

int maximum(int L, int R, int now_L, int now_R, int index)
{
	if (L > now_R || R < now_L)
	{
		return INT_MIN;
	}
	if (L <= now_L && now_R <= R)
	{
		return SegTree[index].second;
	}

	return max(maximum(L, R, now_L, (now_L + now_R) / 2, index * 2), maximum(L, R, (now_L + now_R) / 2 + 1, now_R, index * 2 + 1));
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> d[i];
	}
	Size = (1 << ((int)ceil(log2(n)) + 1));
	SegTree.resize(Size);

	for (int i = 1; i <= n; i++)
	{
		SegTree[i + Size / 2 - 1] = { d[i], d[i] };
	}

	for (int i = Size / 2 - 1; i >= 1; i--)
	{
		SegTree[i].first = min(SegTree[i * 2].first, SegTree[i * 2 + 1].first);
		SegTree[i].second = max(SegTree[i * 2].second, SegTree[i * 2 + 1].second);
	}

	while (m--)
	{

		int a, b;
		cin >> a >> b;
		cout << - minimum(a, b, 1, Size / 2, 1) + maximum(a, b, 1, Size / 2, 1) << "\n";

	}

}
