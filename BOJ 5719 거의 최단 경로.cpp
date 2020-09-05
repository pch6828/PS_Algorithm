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

int n, m, a, b, edges[505][505], dist[505];

void dijkstra()
{
	for ( int i = 0; i < 505; i++ )
	{
		dist[i] = INT_MAX;
	}
	priority_queue<pair<int, int>>pq;
	dist[a] = 0;
	pq.push({ 0,a });

	while ( !pq.empty() )
	{
		int now = pq.top().second;
		int now_cost = pq.top().first;
		pq.pop();

		if ( dist[now] < now_cost )
		{
			continue;
		}

		for ( int i = 0; i < n; i++ )
		{
			if ( edges[now][i] == -1 )
			{
				continue;
			}
			if ( dist[i] > now_cost + edges[now][i] )
			{
				dist[i] = now_cost + edges[now][i];
				pq.push({ dist[i], i });
			}
		}
	}
}

void deledges()
{
	queue<int>bfs;

	bfs.push(b);

	while ( !bfs.empty() )
	{
		int now = bfs.front();
		bfs.pop();

		for ( int i = 0; i < n; i++ )
		{
			if ( edges[i][now] != -1 && dist[now] == dist[i] + edges[i][now] )
			{
				edges[i][now] = -1;
				bfs.push(i);
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while ( cin >> n >> m )
	{
		if ( n == 0 && m == 0 )
		{
			return 0;
		}
		memset(edges, -1, sizeof(edges));
		
		cin >> a >> b;

		for ( int i = 0; i < m; i++ )
		{
			int st, en, cost;
			cin >> st >> en >> cost;
			edges[st][en] = cost;
		}

		dijkstra();
		deledges();
		dijkstra();

		if ( dist[b] != INT_MAX )
		{
			cout << dist[b] << "\n";
		}
		else
		{
			cout << -1 << "\n";
		}
	}
}