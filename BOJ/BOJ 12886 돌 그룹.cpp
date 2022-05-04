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

bool visit[1501][1501];
int a, b, c, total, minimum, maximum;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b >> c;
    total = a + b + c;
    minimum = min(a, min(b, c));
    maximum = max(a, max(b, c));

    queue<pii> bfs;
    bfs.push({minimum, maximum});
    visit[minimum][maximum] = true;

    while (!bfs.empty())
    {
        pii now = bfs.front();
        int x, y, z;
        int mid = total - now.first - now.second;
        bfs.pop();
        if (now.first == now.second)
        {
            cout << 1;
            return 0;
        }

        x = now.first * 2;
        y = now.second - now.first;
        z = mid;

        minimum = min(x, min(y, z));
        maximum = max(x, max(y, z));

        if (!visit[minimum][maximum])
        {
            bfs.push({minimum, maximum});
            visit[minimum][maximum] = true;
        }

        x = now.first * 2;
        y = mid - now.first;
        z = now.second;

        minimum = min(x, min(y, z));
        maximum = max(x, max(y, z));

        if (!visit[minimum][maximum])
        {
            bfs.push({minimum, maximum});
            visit[minimum][maximum] = true;
        }

        x = mid * 2;
        y = now.second - mid;
        z = now.first;

        minimum = min(x, min(y, z));
        maximum = max(x, max(y, z));

        if (!visit[minimum][maximum])
        {
            bfs.push({minimum, maximum});
            visit[minimum][maximum] = true;
        }
    }
    cout << 0;
}
