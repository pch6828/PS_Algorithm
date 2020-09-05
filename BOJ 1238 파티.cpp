#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<deque>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<functional>
#include<climits>

using namespace std;

int go[1005][1005], n, m, x, ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> x;

	for ( int i = 1; i <= n; i++ )
	{
		for ( int j = 1; j <= n; j++ )
		{
			go[i][j] = INT_MAX;
		}
		go[i][i] = 0;
	}

	for ( int i = 0; i < m; i++ )
	{
		int st, en, cost;
		cin >> st >> en >> cost;
		go[st][en] = min(cost, go[st][en]);
	}

	for ( int k = 1; k <= n; k++ )
	{
		for ( int i = 1; i <= n; i++ )
		{
			if ( go[i][k] != INT_MAX )
			{
				for ( int j = 1; j <= n; j++ )
				{
					if ( go[k][j] != INT_MAX )
					{
						go[i][j] = min(go[i][j], go[i][k] + go[k][j]);
					}
				}
			}
		}
	}

	ans = INT_MIN;
	for ( int i = 1; i <= n; i++ )
	{
		ans = max(ans, go[i][x] + go[x][i]);
	}
	cout << ans;
}
