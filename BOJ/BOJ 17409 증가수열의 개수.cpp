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

int n, m, Size;
vector<vector<ll>>SegTree;

void Update(int len, int index, ll x)
{
	index += Size / 2 - 1;
	SegTree[len][index] = x;
	while (index > 1)
	{
		index /= 2;
		SegTree[len][index] = (SegTree[len][index * 2] + SegTree[len][index * 2 + 1]) % MOD;
	}
}

ll Sum(int L, int R, int now_L, int now_R, int index, int len)
{
	if (L > now_R || R < now_L)
	{
		return 0;
	}
	if (L <= now_L && now_R <= R)
	{
		return SegTree[len][index];
	}

	return (Sum(L, R, now_L, (now_L + now_R) / 2, index * 2, len) + Sum(L, R, (now_L + now_R) / 2 + 1, now_R, index * 2 + 1, len)) % MOD;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	Size = (1 << ((int)ceil(log2(n+1)) + 1));
	SegTree.resize(m + 1, vector<ll>(Size, 0));

	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		t++;
		for (int j = 1; j <= m; j++) {
			ll temp = Sum(1, t - 1, 1, Size / 2, 1, j - 1);
			if (temp) {
				Update(j, t, temp % MOD);
			}
			else if (j == 1) {
				Update(j, t, 1);
			}
		}
	}

	cout << Sum(1, Size / 2, 1, Size / 2, 1, m) % MOD;
}
