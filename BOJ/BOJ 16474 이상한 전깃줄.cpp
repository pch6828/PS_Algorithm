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
#define PI 3.14159265359

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

bool cmp(pii a, pii b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}
	return a.first < b.first;
}

unordered_map<int, int>l, r;
vector<pii>wire;
vector<int>lis;
int n, m, k;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;

		l[a] = i;
	}
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;

		r[a] = i;
	}
	
	cin >> k;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;

		wire.push_back({ l[a], r[b] });
	}

	sort(wire.begin(), wire.end(), cmp);

	for (pii p : wire) {
		if (lis.empty() || lis.back() < p.second) {
			lis.push_back(p.second);
		}
		else {
			lis[lower_bound(lis.begin(), lis.end(), p.second) - lis.begin()] = p.second;
		}
	}

	cout << k - lis.size();
}


