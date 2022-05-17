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

string str1, str2;
int cnt[26], n;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> str1 >> str2;

    for (int i = 0; i < n; i++)
    {
        cnt[str1[i] - 'a']++;
        cnt[str2[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++)
    {
        if (cnt[i])
        {
            cout << "NO";
            return 0;
        }
    }

    if (str1.front() != str2.front() || str1.back() != str2.back())
    {
        cout << "NO";
        return 0;
    }
    string t1, t2;
    for (int i = 0; i < n; i++)
    {
        if (str1[i] != 'a' && str1[i] != 'e' && str1[i] != 'i' && str1[i] != 'o' && str1[i] != 'u')
        {
            t1.push_back(str1[i]);
        }

        if (str2[i] != 'a' && str2[i] != 'e' && str2[i] != 'i' && str2[i] != 'o' && str2[i] != 'u')
        {
            t2.push_back(str2[i]);
        }
    }
    if (t1 == t2)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}
