#include<cstdio>
#include<climits>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<cassert>
#include<vector>
#include<iostream>
#include<fstream>
#include<sstream>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<deque>
#include<list>
#include<string>
#include<algorithm>
#include<functional>
#include<numeric>

using namespace std;

#define LIMIT 10000000000000000
#define MOD 1000000007
#define PI 3.14159265359
#define SIZE 1000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

typedef struct {
	double x, y;
}Point;

typedef Point Vector;

typedef struct {
	Point p1, p2;
}Line;

double cross(Vector a, Vector b) {
	return a.x * b.y - a.y * b.x;
}

double dot(Vector a, Vector b) {
	return a.x * b.x + a.y * b.y;
}

double dist(Point p1, Point p2) {
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

bool is_crossed(Line l1, Line l2) {
	Vector v1 = { l1.p1.x - l1.p2.x, l1.p1.y - l1.p2.y };
	Vector v2 = { l2.p1.x - l2.p2.x, l2.p1.y - l2.p2.y };

	double chk1 = cross(v1, { l2.p1.x - l1.p2.x, l2.p1.y - l1.p2.y }) * cross(v1, { l2.p2.x - l1.p2.x, l2.p2.y - l1.p2.y });
	double chk2 = cross(v2, { l1.p1.x - l2.p2.x, l1.p1.y - l2.p2.y }) * cross(v2, { l1.p2.x - l2.p2.x, l1.p2.y - l2.p2.y });

	if (chk1 == 0 && chk2 == 0) {
		pair<double, double>a = { l1.p1.x, l1.p1.y }, b = { l1.p2.x, l1.p2.y }, c = { l2.p1.x, l2.p1.y }, d = { l2.p2.x, l2.p2.y };

		if (b < a) {
			swap(a, b);
		}
		if (d < c) {
			swap(c, d);
		}

		return c <= b && a <= d;
	}
	return chk1 <= 0 && chk2 <= 0;
}

bool ccw(Point x, Point p1, Point p2) {
	Vector v1 = { p1.x - p2.x, p1.y - p2.y };
	Vector v2 = { x.x - p2.x, x.y - p2.y };

	double c = cross(v1, v2);

	return c > 0;
}

int tc, n,m, ans;
vector<Point>black, white;
Point start;

bool cmp1(Point p1, Point p2) {
	if (p1.y == p2.y) {
		return p1.x < p2.x;
	}
	return p1.y < p2.y;
}

bool cmp2(Point p1, Point p2) {
	Point q1 = { p1.x - start.x, p1.y - start.y };
	Point q2 = { p2.x - start.x, p2.y - start.y };
	if (q1.y * q2.x != q1.x * q2.y) {
		return q1.y * q2.x < q1.x* q2.y;
	}
	return cmp1(p1, p2);
}

vector<Point> get_convex_hull(vector<Point>& points){
	if (points.size() < 3) {
		return points;
	}
	sort(points.begin(), points.end(), cmp1);
	start = points[0];
	sort(points.begin() + 1, points.end(), cmp2);

	stack<int>st;
	st.push(0);
	st.push(1);

	for (int i = 2; i < points.size(); i++) {
		while (st.size() >= 2) {
			int idx1, idx2;
			idx1 = st.top();
			st.pop();
			idx2 = st.top();

			if (ccw(points[i], points[idx1], points[idx2])) {
				st.push(idx1);
				break;
			}
		}
		st.push(i);
	}
	vector<Point>res;
	while (!st.empty()) {
		res.push_back(points[st.top()]);
		st.pop();
	}
	return res;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> tc;

	while (tc--) {
		cin >> n >> m;

		white.clear();
		black.clear();
		
		while (n--) {
			double a, b;
			cin >> a >> b;
			white.push_back({ a, b });
		}
		while (m--) {
			double a, b;
			cin >> a >> b;
			black.push_back({ a, b });
		}

		black = get_convex_hull(black);
		white = get_convex_hull(white);

		if (black.size() < 3 && white.size() < 3) {
			if (black.size() == 0 || white.size() == 0) {
				cout << "YES\n";
			}
			else if (black.size() == 1 && white.size() == 1) {
				cout << "YES\n";
			}
			else {
				Line l1 = { white.front(), white.back() };
				Line l2 = { black.front(), black.back() };

				if (is_crossed(l1, l2)) {
					cout << "NO\n";
				}
				else {
					cout << "YES\n";
				}
			}
			continue;
		}

		bool flag = true;
		
		if (black.size() >= 3) {
			for (auto p : white) {
				if (!flag) {
					break;
				}
				bool chk = ccw(p, black.back(), black.front());
				int cnt = 0;
				for (int i = 0; i < black.size() - 1; i++) {
					if (chk != ccw(p, black[i], black[i + 1])) {
						cnt++;
						break;
					}
				}
				if (!cnt) {
					flag = false;
				}
			}
		}
		if (white.size() >= 3) {
			for (auto p : black) {
				if (!flag) {
					break;
				}
				bool chk = ccw(p, white.back(), white.front());
				int cnt = 0;
				for (int i = 0; i < white.size() - 1; i++) {
					if (chk != ccw(p, white[i], white[i + 1])) {
						cnt++;
						break;
					}
				}
				if (!cnt) {
					flag = false;
				}
			}
		}
		if (flag) {
			for (int i = 0; i < black.size(); i++) {
				if (!flag) {
					break;
				}
				Line l1 = { black[i], black[(i + 1) % black.size()] };
				for (int j = 0; j < white.size(); j++) {
					Line l2 = { white[j], white[(j + 1) % white.size()] };

					if (is_crossed(l1, l2)) {
						flag = false;
						break;
					}
				}
			}
		}
		cout << (flag ? "YES\n" : "NO\n");
	}
}
