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

int n, m, ans;
int farm[101][71];
bool visit[101][71];
int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[] = {-1, 1, 0, 0, 1, -1, -1, 1};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> farm[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (!visit[i][j])
            {
                ans++;
                queue<pii> bfs;
                bfs.push({i, j});
                visit[i][j] = true;

                bool flag = false;

                while (!bfs.empty())
                {
                    pii now = bfs.front();
                    bfs.pop();
                    for (int k = 0; k < 8; k++)
                    {
                        int tx = now.first + dx[k];
                        int ty = now.second + dy[k];

                        if (tx >= 1 && tx <= n && ty >= 1 && ty <= m)
                        {
                            if (farm[tx][ty] == farm[now.first][now.second] && !visit[tx][ty])
                            {
                                bfs.push({tx, ty});
                                visit[tx][ty] = true;
                            }
                            else if (farm[tx][ty] > farm[now.first][now.second])
                            {
                                flag = true;
                            }
                        }
                    }
                }
                if (flag)
                {
                    ans--;
                }
            }
        }
    }
    cout << ans;
}
