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

int paper[100][100], n, m, t;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
queue<pii> cheese[2];
queue<pii> melt;

void dfs(int x, int y)
{
    paper[x][y] = 2;

    for (int i = 0; i < 4; i++)
    {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (tx >= 0 && tx < n && ty >= 0 && ty < m && paper[tx][ty] == 0)
        {
            dfs(tx, ty);
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> paper[i][j];
            if (paper[i][j])
            {
                cheese[t].push({i, j});
            }
        }
    }

    dfs(0, 0);

    while (!cheese[t % 2].empty())
    {
        while (!cheese[t % 2].empty())
        {
            int cheese_x = cheese[t % 2].front().first;
            int cheese_y = cheese[t % 2].front().second;
            int cnt = 0;

            cheese[t % 2].pop();

            for (int i = 0; i < 4; i++)
            {
                int next_x = cheese_x + dx[i];
                int next_y = cheese_y + dy[i];

                if (paper[next_x][next_y] == 2)
                {
                    cnt++;
                }
            }

            if (cnt >= 2)
            {
                melt.push({cheese_x, cheese_y});
                paper[cheese_x][cheese_y] = 0;
            }
            else
            {
                cheese[(t + 1) % 2].push({cheese_x, cheese_y});
            }
        }
        t++;
        while (!melt.empty())
        {
            int x = melt.front().first;
            int y = melt.front().second;

            melt.pop();
            dfs(x, y);
        }
    }
    cout << t;
}
