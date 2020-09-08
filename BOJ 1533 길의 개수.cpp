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
#define MOD 1000003;
#define PI 3.14159265359
#define SIZE 1000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

class matrix {
public:
	int size;
	vector<vector<ll>>arr;
	matrix(int n) {
		size = n;
		arr = vector<vector<ll>>(n, vector<ll>(n));
	}
	matrix() {};
};

unordered_map<ll, matrix>dp;
ll n, s, e, t;

matrix multiple(matrix a, matrix b) {
	matrix res(a.size);
	int n = a.size;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				res.arr[i][j] += a.arr[i][k] * b.arr[k][j];
				res.arr[i][j] %= MOD;
			}
		}
	}
	return res;
}

matrix cal(ll n) {
	if (dp.count(n)) {
		return dp[n];
	}
	else {
		return dp[n] = multiple(cal(n / 2), cal(n - n / 2));
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	int nxt = n;
	map<int, vector<int>>adj;
	for (int i = 0; i < n; i++) {
		adj[i].push_back(i);
		for (int j = 0; j < 4; j++) {
			adj[i].push_back(nxt);
			nxt++;
		}
	}

	matrix a(5 * n), b(5 * n);

	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= 4; j++) {
			a.arr[adj[i][j]][adj[i][j - 1]] = 1;
		}
	}
	for (int i = 0; i < 5 * n; i++) {
		b.arr[i][i] = 1;
	}	
	cin >> s >> e >> t;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c;
			cin >> c;
			int t = c - '0';
			if (t) {
				a.arr[i][adj[j][t - 1]] = 1;
			}
		}
	}
	dp[0] = b;
	dp[1] = a;
	cal(t);

	cout << dp[t].arr[s-1][e-1];
}
