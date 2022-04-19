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

typedef struct
{
    int x, y;
} coin;

typedef struct
{
    coin c1, c2;
    int moves;
} state;

int n, m, cx[2], cy[2];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char board[20][20];
bool visit[20][20][20][20];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    int idx = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'o')
            {
                cx[idx] = i;
                cy[idx] = j;
                idx++;
            }
        }
    }

    queue<state> bfs;
    bfs.push({{cx[0], cy[0]}, {cx[1], cy[1]}, 0});
    visit[cx[0]][cy[0]][cx[1]][cy[1]] = true;

    while (!bfs.empty())
    {
        state current = bfs.front();
        bfs.pop();
        for (int i = 0; i < 4; i++)
        {
            int tx[] = {current.c1.x + dx[i], current.c2.x + dx[i]};
            int ty[] = {current.c1.y + dy[i], current.c2.y + dy[i]};
            int drop = 0;
            for (int j = 0; j < 2; j++)
            {
                if (tx[j] < 0 || tx[j] == n || ty[j] < 0 || ty[j] == m)
                {
                    drop++;
                }
                else if (board[tx[j]][ty[j]] == '#')
                {
                    tx[j] -= dx[i];
                    ty[j] -= dy[i];
                }
            }
            if (drop == 1)
            {
                cout << current.moves + 1;
                return 0;
            }
            else if (drop == 0 && !visit[tx[0]][ty[0]][tx[1]][ty[1]] && current.moves + 1 < 10)
            {
                visit[tx[0]][ty[0]][tx[1]][ty[1]] = true;
                bfs.push({{tx[0], ty[0]}, {tx[1], ty[1]}, current.moves + 1});
            }
        }
    }
    cout << -1;
}
