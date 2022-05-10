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

int n, m;
vector<pii> adj[1001];
int visit[1001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;

        queue<pii> bfs;
        bfs.push({a, 0});
        visit[a] = i;

        while (!bfs.empty())
        {
            auto now = bfs.front();
            int node = now.first;
            int dist = now.second;
            bfs.pop();
            if (node == b)
            {
                cout << dist << "\n";
                break;
            }
            for (auto p : adj[node])
            {
                int nxt = p.first;
                int cost = p.second;
                if (visit[nxt] != i)
                {
                    visit[nxt] = i;
                    bfs.push({nxt, dist + cost});
                }
            }
        }
    }
}
