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

int n;
ll ans;
vector<int> zeros;
vector<int> ones;
vector<int> two_or_largers;
bool flag;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    flag = true;

    while (n--)
    {
        int t;
        cin >> t;

        if (flag)
        {
            zeros.push_back(0);
            ones.push_back(0);
            two_or_largers.push_back(0);
        }
        else
        {
            if (t == 0)
            {
                ans += zeros.back() + two_or_largers.back();
                ans += 2 * ones.back();
            }
            else if (t == 1)
                ans += 2 * zeros.back();
            else
                ans += zeros.back();

            zeros.push_back(zeros.back());
            ones.push_back(ones.back());
            two_or_largers.push_back(two_or_largers.back());
        }
        flag = false;
        if (t == 0)
            zeros.back()++;
        else if (t == 1)
            ones.back()++;
        else
            two_or_largers.back()++;
    }

    cout << ans;
}