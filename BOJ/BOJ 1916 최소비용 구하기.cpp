#include <cstdio>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <list>
#include <string>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

#define LIMIT 10000000000000000
#define MOD 1000000007
#define PI 3.14159265359
#define SIZE 1000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

typedef vector<int> LargeNum;

int n, m, s, e;
vector<pii> adj[1001];
int dist[1001];
priority_queue<pii, vector<pii>, greater<pii>> dijkstra;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INT_MAX;
    }

    while (m--)
    {
        int src, end, cost;
        cin >> src >> end >> cost;

        adj[src].push_back({end, cost});
    }

    cin >> s >> e;

    dist[s] = 0;
    dijkstra.push({dist[s], s});

    while (!dijkstra.empty())
    {
        int cost = dijkstra.top().first;
        int city = dijkstra.top().second;
        dijkstra.pop();

        if (city == e)
        {
            cout << cost;
            return 0;
        }
        if (dist[city] != cost)
        {
            continue;
        }

        for (auto edge : adj[city])
        {
            if (dist[edge.first] > cost + edge.second)
            {
                dist[edge.first] = cost + edge.second;
                dijkstra.push({dist[edge.first], edge.first});
            }
        }
    }
}
