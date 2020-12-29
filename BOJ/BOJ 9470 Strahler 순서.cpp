#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<functional>
#include<climits>

using namespace std;

int test, n,m, num;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> test;
	while ( test-- )
	{
		int maximum = 1;
		cin >> num >> n >> m;
		vector<vector<int>>graph(n + 1);
		vector<int>indegree(n + 1);
		vector<pair<int, int>>strahler(n + 1);
		queue<int>topo;
		while ( m-- )
		{
			int fr, to;
			cin >> fr >> to;
			indegree[to]++;
			graph[fr].push_back(to);
		}
		for ( int i = 1; i <= n; i++ )
		{
			if ( !indegree[i] )
			{
				topo.push(i);
				strahler[i].first++;
			}
		}

		while ( !topo.empty() )
		{
			int now = topo.front();
			topo.pop();

			for ( auto there : graph[now] )
			{
				indegree[there]--;
				if ( strahler[there].first < strahler[now].first )
				{
					strahler[there].first = strahler[now].first;
					strahler[there].second = 1;
				}
				else if ( strahler[there].first == strahler[now].first )
				{
					strahler[there].second++;
				}
				if ( !indegree[there] )
				{
					if ( strahler[there].second > 1 )
					{
						strahler[there].first++;
					}
					maximum = max(maximum, strahler[there].first);
					topo.push(there);
				}
			}
		}
		cout << num << " " << maximum << "\n";

	}
}