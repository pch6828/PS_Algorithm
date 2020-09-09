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
#define MXH 20
#define SIZE 40005

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

map<ll, ll>dp;
ll n, p, q, x, y;

ll solve(ll now) {
	if (now <= 0) {
		return 1;
	}
	if (dp.find(now) != dp.end()) {
		return dp[now];
	}
	return dp[now] = solve(now / p - x) + solve(now / q - y);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> p >> q >> x >> y;

	cout << solve(n);
}


