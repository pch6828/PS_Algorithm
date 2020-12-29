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

set<int>color[100001];
int parent[100001], root[100001], n, q;
stack<pii>query;

int FIND(int a) {
	if (a == root[a]) {
		return a;
	}
	return root[a] = FIND(root[a]);
}

void UNION(int a, int b) {
	int ra = FIND(a);
	int rb = FIND(b);

	if (color[ra].size() > color[rb].size()) {
		swap(ra, rb);
	}
	root[ra] = rb;
	for (auto i : color[ra]) {
		color[rb].insert(i);
	}
	color[ra].clear();
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> q;
	root[1] = 1;
	for (int i = 2; i <= n; i++) {
		cin >> parent[i];
		root[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		color[i].insert(t);
	}

	for (int i = 1; i < n + q; i++) {
		int cmd, a;
		cin >> cmd >> a;
		query.push({ cmd, a });
	}

	stack<int>ans;

	while (!query.empty()) {
		auto p = query.top();
		query.pop();
		int cmd = p.first;
		int a = p.second;

		if (cmd == 1) {
			UNION(a, parent[a]);
		}
		else {
			ans.push(color[FIND(a)].size());
		}
	}
	while (!ans.empty()) {
		cout << ans.top() << "\n";
		ans.pop();
	}
}
