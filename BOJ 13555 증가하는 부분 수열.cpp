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

using namespace std;

#define LIMIT 10000000000000000
#define MOD 1000000007
#define PI 3.14159265359
#define SIZE 1000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, k, Size;
vector<ll>SegTree[51];
ll dp[100001];

void Update(int len, int index, ll x)
{
	int t = index % 2;
	index += Size / 2 - 1;
	SegTree[len][index] += x;
	SegTree[len][index] %= 5000000;
	while (index > 1)
	{
		index /= 2;
		SegTree[len][index] = (SegTree[len][index * 2] + SegTree[len][index * 2 + 1]) % 5000000;
	}
}

ll Sum(int len, int L, int R, int now_L, int now_R, int index)
{
	if (L > now_R || R < now_L)
	{
		return 0;
	}
	if (L <= now_L && now_R <= R)
	{
		return SegTree[len][index];
	}

	return (Sum(len, L, R, now_L, (now_L + now_R) / 2, index * 2) + Sum(len, L, R, (now_L + now_R) / 2 + 1, now_R, index * 2 + 1)) % 5000000;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	Size = (1 << ((int)ceil(log2(100000)) + 1));
	for (int i = 1; i <= k; i++) { 
		SegTree[i].resize(Size); 
	}
	vector<int>lis;
	while (n--) {
		int t, idx;
		cin >> t;
		if (lis.empty() || lis.back() < t) {
			lis.push_back(t);
			idx = lis.size();
		}
		else {
			idx = lower_bound(lis.begin(), lis.end(), t) - lis.begin();
			lis[idx] = t;
			idx++;
		}
		idx = min(k, idx);

		Update(1, t, 1);

		for (int i = 2; i <= idx; i++) {
			Update(i, t, Sum(i - 1, 1, t - 1, 1, Size / 2, 1));
		}
	}
	cout << Sum(k, 1, Size / 2, 1, Size / 2, 1);
}
