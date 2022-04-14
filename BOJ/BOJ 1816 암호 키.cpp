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

int n;
ll key;
vector<int> primes;
bool not_prime[1000000];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    not_prime[0] = not_prime[1] = true;

    for (ll i = 2; i < 1000000; i++)
    {
        if (!not_prime[i])
        {
            primes.push_back(i);
            for (ll j = i * i; j < 1000000; j += i)
            {
                not_prime[j] = true;
            }
        }
    }

    while (n--)
    {
        cin >> key;

        bool chk = true;

        for (int prime : primes)
        {
            if (key % prime == 0)
            {
                chk = false;
                break;
            }
        }
        cout << (chk ? "YES\n" : "NO\n");
    }
}
