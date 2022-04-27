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
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
pii root[1501][1501], swan[2];
char pond[1501][1501];

pii FIND(const pii &a)
{
    if (a == root[a.first][a.second])
    {
        return a;
    }
    return root[a.first][a.second] = FIND(root[a.first][a.second]);
}

void UNION(const pii &a, const pii &b)
{
    pii ra = FIND(a), rb = FIND(b);
    if (ra == rb)
    {
        return;
    }
    root[ra.first][ra.second] = rb;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int idx = 0;
    queue<pair<int, pii>> bfs;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> pond[i][j];
            if (pond[i][j] == 'L')
            {
                swan[idx] = {i, j};
                idx++;
            }
            root[i][j] = {i, j};
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (pond[i][j] != 'X')
            {
                for (int k = 0; k < 4; k++)
                {
                    int tx = i + dx[k];
                    int ty = j + dy[k];

                    if (tx >= 1 && tx <= n && ty >= 1 && ty <= m)
                    {
                        if (pond[tx][ty] != 'X')
                        {
                            UNION({i, j}, {tx, ty});
                        }
                        else
                        {
                            bfs.push({0, {tx, ty}});
                        }
                    }
                }
            }
        }
    }

    if (FIND(swan[0]) == FIND(swan[1]))
    {
        cout << 0;
        return 0;
    }

    while (!bfs.empty())
    {
        auto p = bfs.front();
        int day = p.first;
        pii ice = p.second;
        bfs.pop();

        if (pond[ice.first][ice.second] != 'X')
        {
            continue;
        }
        pond[ice.first][ice.second] = '.';

        for (int k = 0; k < 4; k++)
        {
            int tx = ice.first + dx[k];
            int ty = ice.second + dy[k];

            if (tx >= 1 && tx <= n && ty >= 1 && ty <= m)
            {
                if (pond[tx][ty] != 'X')
                {
                    UNION({ice.first, ice.second}, {tx, ty});
                    if (FIND(swan[0]) == FIND(swan[1]))
                    {
                        cout << day + 1;
                        return 0;
                    }
                }
                else
                {
                    bfs.push({day + 1, {tx, ty}});
                }
            }
        }
    }
}
