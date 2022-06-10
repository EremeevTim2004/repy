#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point {
	double x, y;

	point(double x, double y) {
		this -> x = x;
		this -> y = y;
	}
};

bool operator < (point a, point b) {
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool operator > (point a, point b) {
	return b < a;
}

bool cw (point a, point b, point c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw (point a, point b, point c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

vector<point> convex_hull(vector<point> &a) {
	
	if (a.size() == 1)  return a;
	
	sort(a.begin(), a.end());
	
	point p1 = a[0],  p2 = a.back();
	
	vector<point> up, down;
	up.push_back (p1);
	down.push_back (p1);
	
	for (size_t i = 1;i < a.size(); i++) {

		if (i == a.size() - 1 || cw(p1, a[i], p2)) {
			while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], a[i]))
				up.pop_back();
			up.push_back (a[i]);
		}
		if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
			while (down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], a[i]))
				down.pop_back();
			down.push_back (a[i]);
		}
	}

	a.clear();
	
	for (size_t i=0; i<up.size(); ++i)
		a.push_back (up[i]);
	
	for (size_t i=down.size()-2; i>0; --i)
		a.push_back (down[i]);

	reverse(a.begin(), a.end());

	return a;

}

void print(vector<point> &points) {
	for (int i = 0; i < points.size(); i++) {
		cout << "(" << points[i].x << ", " << points[i].y << "), ";
	}
	cout << endl;
}

int main() {

	vector<point> points;

	points.push_back(point(0, 0));
	points.push_back(point(0, 2));
	points.push_back(point(1, 1));
	points.push_back(point(4, 2));
	points.push_back(point(4, 0));

	vector<point> res = convex_hull(points);

	print(res);

	return 0;
}
