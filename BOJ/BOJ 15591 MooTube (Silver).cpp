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
vector<pii> adj[5001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    while (m--)
    {
        vector<bool> visit(n + 1);
        int v, k, cnt = 0;
        cin >> k >> v;

        visit[v] = true;
        queue<int> bfs;
        bfs.push(v);

        while (!bfs.empty())
        {
            int current = bfs.front();
            cnt++;
            bfs.pop();

            for (pii &p : adj[current])
            {
                if (p.second >= k && !visit[p.first])
                {
                    visit[p.first] = true;
                    bfs.push(p.first);
                }
            }
        }
        cout << cnt - 1 << "\n";
    }
}
