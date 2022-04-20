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

int k;
string str;
char encrypt[20][200];
bool backward;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> k >> str;

    int i = 0, j = 0;

    for (char c : str)
    {
        encrypt[i][j] = c;
        if (backward)
        {
            i--;
        }
        else
        {
            i++;
        }
        if (i < 0 || i == k)
        {
            j++;

            backward = !backward;
            if (i == k)
            {
                i--;
            }
            else
            {
                i++;
            }
        }
    }

    for (int i = 0; i < k; i++)
    {
        cout << encrypt[i];
    }
}
