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
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<random>
#include<complex>

using namespace std;

#define LIMIT 10000000000000000
#define MOD 998244353
#define MXH 21
#define SIZE 50005

const double PI = acos(-1);

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> cpx;
typedef vector<cpx> vec;

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

	return cross(v1, { l2.p1.x - l1.p2.x, l2.p1.y - l1.p2.y }) * cross(v1, { l2.p2.x - l1.p2.x, l2.p2.y - l1.p2.y }) <= 0
		&& cross(v2, { l1.p1.x - l2.p2.x, l1.p1.y - l2.p2.y }) * cross(v2, { l1.p2.x - l2.p2.x, l1.p2.y - l2.p2.y }) <= 0;
}

bool has_same_vector(Line l1, Line l2) {
	Vector v1 = { l1.p1.x - l1.p2.x, l1.p1.y - l1.p2.y };
	Vector v2 = { l2.p1.x - l2.p2.x, l2.p1.y - l2.p2.y };
	return cross(v1, v2) == 0;
}

bool is_on_line(Point p, Line l2) {
	Vector v0 = { l2.p1.x - l2.p2.x, l2.p1.y - l2.p2.y };
	Vector v1 = { p.x - l2.p2.x, p.y - l2.p2.y };
	Vector v2 = { p.x - l2.p1.x, p.y - l2.p1.y };

	double norm0 = sqrt(dot(v0, v0)), norm1 = sqrt(dot(v1, v1)), norm2 = sqrt(dot(v2, v2));

	bool chk = cross(v0, v1) == 0 && cross(v0, v2) == 0;
	return chk && norm0 >= norm1 && norm0 >= norm2;
}

bool has_intersection(Line l1, Line l2) {
	Point p1 = l1.p1, p2 = l1.p2, p3 = l2.p1, p4 = l2.p2;

	if ((p1.x == p3.x && p1.y == p3.y) || (p1.x == p4.x && p1.y == p4.y) || (p2.x == p3.x && p2.y == p3.y) || (p2.x == p4.x && p2.y == p4.y)) {
		return false;
	}
	bool res = false;
	res |= is_on_line(l1.p1, l2) && is_on_line(l2.p1, l1);
	res |= is_on_line(l1.p2, l2) && is_on_line(l2.p1, l1);
	res |= is_on_line(l1.p1, l2) && is_on_line(l2.p2, l1);
	res |= is_on_line(l1.p2, l2) && is_on_line(l2.p2, l1);
	return res;
}

int is_cross_square(const vector<Line>& square, const Line& l1) {
	double ans = 0;
	for (auto l2 : square) {
		if (is_crossed(l1, l2)) {
			if (has_same_vector(l1, l2)) {
				if ((is_on_line(l2.p1, l1) && is_on_line(l2.p2, l1)) || (is_on_line(l1.p1, l2) && is_on_line(l1.p2, l2)) || has_intersection(l1, l2)) {
					ans = 0;
					break;
				}
				else {
					ans += 0.5;
				}
			}
			else {
				if (is_on_line(l2.p1, l1) || is_on_line(l2.p2, l1)) {
					ans += 0.5;
				}
				else {
					ans += 1;
				}
			}
		}
	}
	return (int)ans;
}

Point get_intersection(Line l1, Line l2) {
	double denom = (l1.p1.x - l1.p2.x) * (l2.p1.y - l2.p2.y) - (l2.p1.x - l2.p2.x) * (l1.p1.y - l1.p2.y);

	double x = (l1.p1.x * l1.p2.y - l1.p1.y * l1.p2.x) * (l2.p1.x - l2.p2.x) - (l2.p1.x * l2.p2.y - l2.p1.y * l2.p2.x) * (l1.p1.x - l1.p2.x);
	double y = (l1.p1.x * l1.p2.y - l1.p1.y * l1.p2.x) * (l2.p1.y - l2.p2.y) - (l2.p1.x * l2.p2.y - l2.p1.y * l2.p2.x) * (l1.p1.y - l1.p2.y);

	return { x / denom , y / denom };
}


int n;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	double x1, y1, x2, y2;
	x1 = y1 = -10;
	x2 = y2 = 10;
	int ans = 1;

	vector<Line>square, lines;
	square.push_back({ {x1, y1},{x1, y2} });
	square.push_back({ {x1, y1},{x2, y1} });
	square.push_back({ {x2, y2},{x1, y2} });
	square.push_back({ {x2, y2},{x2, y1} });

	cin >> n;

	while (n--) {
		Line l1;
		cin >> l1.p1.x >> l1.p1.y >> l1.p2.x >> l1.p2.y;

		if (is_cross_square(square, l1) != 2) {
			continue;
		}
		int cross_point = 0;

		for (auto& l2 : lines) {
			if (is_crossed(l1, l2)) {
				Point cp = get_intersection(l1, l2);

				if (cp.x > -10 && cp.x<10 && cp.y>-10 && cp.y < 10) {
					cross_point++;
				}
			}
		}

		ans += cross_point + 1;
		lines.push_back(l1);
	}
	cout << ans;
}
