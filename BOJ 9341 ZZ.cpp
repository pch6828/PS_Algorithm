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
#define MOD 1000000009
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
int n, m, d, a, b;

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
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> a >> b >> n >> m;
		
		dp.clear();
		matrix x(n + 2), y(n + 2);

		for (int i = 0; i < n + 2; i++) {
			y.arr[i][i] = 1;
			for (int j = 0; j <= i; j++) {
				x.arr[i][j] = 1;
			}
		}
		x.arr[0][0] = 0;
		x.arr[0][1] = 1;
		m--;
		dp[0] = y;
		dp[1] = x;
		cal(m);
		auto v = dp[m];
		ll ans = v.arr[n + 1][0] * (b - a);
		ans += MOD;
		ans %= MOD;
		for (int i = 1; i < n + 2; i++) {
			ans += v.arr[n + 1][i] * a;
			ans %= MOD;
		}

		cout << ans << "\n";
	}
}
