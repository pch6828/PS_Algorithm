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

bool ccw(Point x, Point p1, Point p2) {
	Vector v1 = { p1.x - p2.x, p1.y - p2.y };
	Vector v2 = { x.x - p2.x, x.y - p2.y };

	double c = cross(v1, v2);

	return c > 0;
}

int n;
double l, wall_size;
vector<Point>points;

bool cmp1(Point p1, Point p2) {
	if (p1.y == p2.y) {
		return p1.x < p2.x;
	}
	return p1.y < p2.y;
}

bool cmp2(Point p1, Point p2) {
	Point q1 = { p1.x - points[0].x, p1.y - points[0].y };
	Point q2 = { p2.x - points[0].x, p2.y - points[0].y };
	if (q1.y * q2.x != q1.x * q2.y) {
		return q1.y * q2.x < q1.x* q2.y;
	}
	return cmp1(p1, p2);
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> l;

	while (n--) {
		double a, b;
		cin >> a >> b;

		points.push_back({ a, b });
	}

	sort(points.begin(), points.end(), cmp1);
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
	vector<Point>wall;
	while (!st.empty()) {
		wall.push_back(points[st.top()]);
		st.pop();
	}

	wall_size = dist(wall.front(), wall.back());

	for (int i = 0; i < wall.size() - 1; i++) {
		wall_size += dist(wall[i], wall[i + 1]);
	}

	wall_size += l * PI * 2;
	
	cout.precision(20);
	cout << wall_size;
}
