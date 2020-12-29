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

int root[200005], remember[200005], n, q;
stack<pair<int, pair<int, int>>>cmd;
stack<string>ans;

int getRoot(int now)
{
	if ( root[now] == now )return now;
	else return root[now] = getRoot(root[now]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> q;

	root[1] = 1;
	for ( int i = 2; i <= n; i++ )
	{
		int temp;
		cin >> temp;
		remember[i] = temp;
		root[i] = i;
	}

	for ( int i = 0; i < n + q - 1; i++ )
	{
		int t, a = 0, b = 0;
		cin >> t;
		if ( t )
		{
			cin >> a >> b;
		}
		else
		{
			cin >> a;
		}
		cmd.push({ t, { a,b } });
	}

	while ( !cmd.empty() )
	{
		auto now = cmd.top();
		cmd.pop();

		if ( now.first )
		{
			int root_A = getRoot(now.second.first), root_B = getRoot(now.second.second);

			if ( root_A == root_B )
			{
				ans.push("YES\n");
			}
			else
			{
				ans.push("NO\n");
			}
		}
		else
		{
			int root_A = getRoot(now.second.first);
			root[root_A] = remember[now.second.first];
		}
	}
	while ( !ans.empty() )
	{
		cout << ans.top();
		ans.pop();
	}

	return 0;
}
