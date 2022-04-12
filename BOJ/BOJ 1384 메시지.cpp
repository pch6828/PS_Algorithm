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

int n, group;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> n)
    {
        group++;
        vector<string> names;
        vector<pii> nasty;
        if (!n)
        {
            return 0;
        }

        for (int i = 0; i < n; i++)
        {
            string name;
            cin >> name;
            names.push_back(name);

            for (int j = 1; j < n; j++)
            {
                string message;
                cin >> message;
                if (message == "N")
                {
                    nasty.push_back({(i - j + n) % n, i});
                }
            }
        }
        cout << "Group " << group << "\n";
        if (nasty.empty())
        {
            cout << "Nobody was nasty\n";
        }
        else
        {
            for (pii p : nasty)
            {
                cout << names[p.first] << " was nasty about " << names[p.second] << "\n";
            }
        }
        cout << "\n";
    }
}
