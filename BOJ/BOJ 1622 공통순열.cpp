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

string str1, str2;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (getline(cin, str1), getline(cin, str2))
    {
        sort(str2.begin(), str2.end());
        int check[26] = {
            0,
        };

        for (char c : str1)
        {
            check[c - 'a']++;
        }
        for (char c : str2)
        {
            if (check[c - 'a'])
            {
                cout << c;
                check[c - 'a']--;
            }
        }
        cout << "\n";
    }
}
