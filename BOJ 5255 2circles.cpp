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
#define MOD 1000000007
#define MXH 21
#define SIZE 50005

const double PI = acos(-1);

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> cpx;
typedef vector<cpx> vec;

#define double long double

typedef struct {
	double x, y;
}Point;

typedef Point Vector;

typedef struct {
	Point p1, p2;
}Line;

inline bool equals(double a, double b) { return abs(a - b) < 1e-9; }

double cross(Vector a, Vector b) {
	double res = a.x * b.y - a.y * b.x;
	return (res > 0 ? 1 : (res < 0 ? -1 : 0));
}

double dot(Vector a, Vector b) {
	return a.x * b.x + a.y * b.y;
}

double dist(Point p1, Point p2) {
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

bool ccw(Point x, Point p1, Point p2) {
	Vector v1 = { p1.x - p2.x, p1.y - p2.y };
	Vector v2 = { x.x - p2.x, x.y - p2.y };

	double c = cross(v1, v2);

	return c > 0;
}

Point start, a, b;

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

vector<Point> get_convex_hull(vector<Point>& points) {
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

bool chk(Point p1, Point p2, Point p3, Point p4) {
	Vector v1 = { p2.x - p1.x, p2.y - p1.y };
	Vector v2 = { p4.x - p3.x, p4.y - p3.y };

	return cross(v1, v2) <= 0;
}

double RotatingCalipers(vector<Point>ch) {
	sort(ch.begin(), ch.end(), cmp1);
	start = ch[0];
	sort(ch.begin() + 1, ch.end(), cmp2);
	reverse(ch.begin(), ch.end());
	int pt = 0;
	double ans = 0;
	for (int i = 0; i < ch.size(); i++) {
		while (pt + 1 < ch.size() && chk(ch[i], ch[i + 1], ch[pt], ch[pt + 1])) {
			ans = max(ans, dist(ch[i], ch[pt]));
			pt++;
		}
		ans = max(ans, dist(ch[i], ch[pt]));
	}
	return ans;
}

bool line_intersect(Line& l1, Line& l2, Point& v) {
	Vector v1 = { l1.p2.x - l1.p1.x, l1.p2.y - l1.p1.y };
	Vector v2 = { l2.p2.x - l2.p1.x, l2.p2.y - l2.p1.y };
	double det = v2.x * v1.y - v1.x * v2.y;

	if (equals(det, 0)) {
		return false;
	}

	double s = ((l2.p1.y - l1.p1.y) * v2.x - (l2.p1.x - l1.p1.x) * v2.y) / det;
	v.x = l1.p1.x + v1.x * s;
	v.y = l1.p1.y + v1.y * s;
	return true;
}

bool bad(Line& a, Line& b, Line& c) {
	Point v;
	if (!line_intersect(a, b, v)) {
		return false;
	}
	double crs = (c.p2.x - c.p1.x) * (v.y - c.p1.y) - (c.p2.y - c.p1.y) * (v.x - c.p1.x);
	return crs < 0 || equals(crs, 0);
}

int lsgn(const Line& a) {
	if (a.p1.y == a.p2.y) {
		return a.p1.x > a.p2.x;
	}
	return a.p1.y > a.p2.y;
}

bool cmp3(const Line& a, const Line& b) {
	if (lsgn(a) != lsgn(b)) {
		return lsgn(a) < lsgn(b);
	}
	return (a.p2.x - a.p1.x) * (b.p2.y - b.p1.y) - (a.p2.y - a.p1.y) * (b.p2.x - b.p1.x) > 0;
}

vector<Point>half_plane_intersection(vector<Line>& ln) {
	sort(ln.begin(), ln.end(), cmp3);
	deque<Line>dq;

	for (auto l : ln) {
		while (dq.size() >= 2 && bad(dq[dq.size() - 2], dq.back(), l)) {
			dq.pop_back();
		}
		while (dq.size() >= 2 && bad(dq[0], dq[1], l)) {
			dq.pop_front();
		}
		if (dq.size() < 2 || !bad(dq.back(), l, dq[0])) {
			dq.push_back(l);
		}
	}
	vector<Point>res;
	if (dq.size() >= 3) {
		for (int i = 0; i < dq.size(); i++) {
			int j = (i + 1) % dq.size();
			Point v;
			if (!line_intersect(dq[i], dq[j], v)) {
				continue;
			}
			res.push_back(v);
		}
	}
	return res;
}

int n;
vector<Vector>dir;
vector<Line>line;
vector<Point>points;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cout << fixed;
	cout.precision(3);

	cin >> n;
	while (n--) {
		double a, b;
		cin >> a >> b;
		points.push_back({ a, b });
	}

	for (int i = 0; i < points.size(); i++) {
		Line l = { points[i], points[(i + 1) % points.size()] };
		Vector v = { l.p2.x - l.p1.x, l.p2.y - l.p1.y };
		double nv = dist(l.p1, l.p2);
		v.x /= nv;
		v.y /= nv;

		line.push_back(l);
		dir.push_back({ -v.y, v.x });
	}
	ll l = 0, r = 200000000000;
	double ans = 0;
	while (l < r) {
		ll mid = (l + r) / 2;
		double d = (double)mid / 10000.0;
		vector<Line>ln;
		for (int i = 0; i < line.size(); i++) {
			Point p1 = line[i].p1, p2 = line[i].p2;
			p1.x += d * dir[i].x;
			p1.y += d * dir[i].y;
			p2.x += d * dir[i].x;
			p2.y += d * dir[i].y;

			ln.push_back({ p1, p2 });
		}

		auto result = half_plane_intersection(ln);
		if (result.size()) {
			double r_ = RotatingCalipers(result);

			if (r_ >= 2 * d) {
				l = mid + 1;
				ans = max(ans, d);
			}
			else {
				r = mid - 1;
			}
		}
		else {
			r = mid - 1;
		}
	}
	cout << (double)ans << "\n";
}
