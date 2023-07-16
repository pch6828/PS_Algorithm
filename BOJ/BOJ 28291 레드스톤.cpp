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

int circuit[50][50], n, m, b;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> b;

    while (b--)
    {
        string block_type;
        int x, y;

        cin >> block_type >> x >> y;
        if (block_type == "redstone_block")
            circuit[x][y] = 1;
        else if (block_type == "redstone_dust")
            circuit[x][y] = -1;
        else
            circuit[x][y] = 2;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (circuit[i][j] == 1)
            {
                queue<pair<pii, int>> bfs;
                bfs.push({{i, j}, -17});

                while (!bfs.empty())
                {
                    pair<pii, int> cur = bfs.front();
                    bfs.pop();
                    int x = cur.first.first;
                    int y = cur.first.second;
                    int power = cur.second;

                    for (int k = 0; k < 4; k++)
                    {
                        int tx = x + dx[k];
                        int ty = y + dy[k];

                        if (tx >= 0 && tx < n && ty >= 0 && ty < m)
                        {
                            if (circuit[tx][ty] == 2 && power < -2)
                                circuit[tx][ty] = 3;
                            else if (circuit[tx][ty] < 0 && circuit[tx][ty] > power + 1)
                            {
                                circuit[tx][ty] = power + 1;
                                bfs.push({{tx, ty}, power + 1});
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (circuit[i][j] == 2)
            {
                cout << "failed";
                return 0;
            }
        }
    }
    cout << "success";
}