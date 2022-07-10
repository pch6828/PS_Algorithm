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

int gcd(int a, int b)
{
    if (a % b == 0)
    {
        return b;
    }
    return gcd(b, a % b);
}

int sx, sy, ex, ey, dx, dy, dist;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> sx >> sy >> ex >> ey >> dx >> dy;

    dist = (sx - ex) * (sx - ex) + (sy - ey) * (sy - ey);
    int new_dist = dist;
    if (dx && dy)
    {
        int g = gcd(abs(dx), abs(dy));
        dx /= g;
        dy /= g;
    }
    else if (dx == 0)
    {
        dy = 1;
    }
    else
    {
        dx = 1;
    }

    do
    {
        dist = new_dist;
        ex += dx;
        ey += dy;
        new_dist = (sx - ex) * (sx - ex) + (sy - ey) * (sy - ey);
    } while (dist >= new_dist);

    cout << ex - dx << " " << ey - dy;
}
