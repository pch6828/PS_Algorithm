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

int n, k, durability[200], ans;
deque<int> robots;
bool occupied[200];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    for (int i = 0; i < 2 * n; i++)
    {
        cin >> durability[i];
    }
    int store = n - 1, load = 0, belt = 2 * n;
    while (++ans)
    {
        if (!robots.empty() && (robots.front() + ans) % belt == store)
        {
            occupied[robots.front()] = false;
            robots.pop_front();
        }
        for (int &robot : robots)
        {
            int idx = (robot + 1) % belt;
            if (!occupied[idx] && durability[idx])
            {
                occupied[idx] = true;
                occupied[robot] = false;
                durability[idx]--;
                if (durability[idx] == 0)
                {
                    k--;
                }
                robot = idx;
            }
        }
        if (!robots.empty() && (robots.front() + ans) % belt == store)
        {
            occupied[robots.front()] = false;
            robots.pop_front();
        }
        if (durability[((belt - ans % belt) % belt)])
        {
            occupied[((belt - ans % belt) % belt)] = true;
            durability[((belt - ans % belt) % belt)]--;
            if (durability[((belt - ans % belt) % belt)] == 0)
            {
                k--;
            }
            robots.push_back(((belt - ans % belt) % belt));
        }

        if (k <= 0)
        {
            break;
        }
    }
    cout << ans;
}
