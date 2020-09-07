#include<cstdio>
#include<climits>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<deque>
#include<string>
#include<iostream>
#include<algorithm>
#include<functional>
#include<unordered_map>

#define PI 3.14159265359

using namespace std;

int root[100005], g, p, ans, temp, now;
bool flag = true;

int find(int i) {
	if (root[i] == i) {
		return i;
	}
	else {
		return root[i] = find(root[i]);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g >> p;

	for (int i = 0; i <= g; i++) {
		root[i] = i;
	}

	while (p--) {
		cin >> temp;
		if (flag) {
			now = find(temp);
			if (now) {
				root[now] = now - 1;
				ans++;
			}
			else {
				flag = false;
			}
		}
	}
	cout << ans;
}
