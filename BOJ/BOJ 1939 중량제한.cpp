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
int root[10001];
vector<pair<int, pii>> edges;

int FIND(int a)
{
    if (a == root[a])
    {
        return a;
    }
    return root[a] = FIND(root[a]);
}

void UNION(int a, int b)
{
    int ra = FIND(a);
    int rb = FIND(b);

    if (ra == rb)
    {
        return;
    }

    root[ra] = rb;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        root[i] = i;
    }

    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, {a, b}});
    }
    sort(edges.begin(), edges.end(), greater<pair<int, pii>>());

    cin >> s >> e;

    for (auto edge : edges)
    {
        int cost = edge.first;
        int a = edge.second.first;
        int b = edge.second.second;

        UNION(a, b);
        if (FIND(s) == FIND(e))
        {
            cout << cost;
            return 0;
        }
    }
}
