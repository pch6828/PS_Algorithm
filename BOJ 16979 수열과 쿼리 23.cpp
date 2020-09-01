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

using namespace std;

#define LIMIT 10000000000000000
#define MOD 1000000007
#define PI 3.14159265359
#define MXH 21
#define SIZE 50005

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

typedef struct {
	int st, en, idx;
}Query;

ll arr[100001], n, m, k, sq, ans[100005], sum, s, e, tree[100010];
vector<Query>query;

bool cmp(Query a, Query b) {
	if (a.st / sq == b.st / sq) {
		if (a.en == b.en) {
			return a.idx < b.idx;
		}
		return a.en < b.en;
	}
	return a.st / sq < b.st / sq;
}

int Sum(int idx) {
	int result = 0;

	while (idx > 0) {
		result += tree[idx];
		idx -= (idx & -idx);
	}
	return result;
}

int Sum(int s, int e) {
	return Sum(e) - Sum(s - 1);
}

void Update(int idx, int val) {
	while (idx <= 100001) {
		tree[idx] += val;
		if (tree[idx] < 0) {
			assert(false);
		}
		idx += (idx & -idx);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	set<ll>S;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		S.insert(arr[i]);
	}
	unordered_map<int, int>idx;
	for (ll a : S) {
		k++;
		idx[a] = k;
	}

	for (int i = 1; i <= n; i++)
	{
		arr[i] = idx[arr[i]];
	}
	sq = 300;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		query.push_back({ a, b ,i });
	}

	sort(query.begin(), query.end(), cmp);

	for (int i = query[0].st; i <= query[0].en; i++) {
		sum += Sum(arr[i] + 1, 100001);
		Update(arr[i], 1);
	}
	ans[query[0].idx] = sum;
	s = query[0].st;
	e = query[0].en;

	for (int i = 1; i < m; i++) {
		auto q = query[i];

		while (s > q.st) {
			s--;
			sum += Sum(1, arr[s] - 1);
			if (sum < 0) {
				assert(false);
			}
			Update(arr[s], 1);
		}
		while (e < q.en) {
			e++;
			sum += Sum(arr[e] + 1, 100001);
			if (sum < 0) {
				assert(false);
			}
			Update(arr[e], 1);
		}
		while (s < q.st) {
			Update(arr[s], -1);
			sum -= Sum(1, arr[s] - 1);
			if (sum < 0) {
				assert(false);
			}
			s++;
		}
		while (e > q.en) {
			Update(arr[e], -1);
			sum -= Sum(arr[e] + 1, 100001);
			if (sum < 0) {
				assert(false);
			}
			e--;
		}

		ans[q.idx] = sum;
	}
	for (int i = 0; i < m; i++) {
		cout << ans[i] << "\n";
	}
}
