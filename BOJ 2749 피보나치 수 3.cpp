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

typedef long long ll;
typedef pair<int, int> pii;

typedef struct {
	ll a, b, c, d;
}matrix;

unordered_map<ll, matrix>dp;
ll n;

matrix multiple(matrix a, matrix b) {
	matrix res;
	res.a = (a.a * b.a + a.b * b.c) % 1000000;
	res.b = (a.a * b.b + a.b * b.d) % 1000000;
	res.c = (a.c * b.a + a.d * b.c) % 1000000;
	res.d = (a.c * b.b + a.d * b.d) % 1000000;
	return res;
}

matrix fibo(ll n) {
	if (dp.count(n)) {
		return dp[n];
	}
	else {
		return dp[n] = multiple(fibo(n / 2), fibo(n - n / 2));
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	dp[0] = { 1,0,0,0 };
	dp[1] = { 1,1,1,0 };

	cout << fibo(n-1).a;
}

