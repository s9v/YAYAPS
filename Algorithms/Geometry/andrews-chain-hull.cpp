/*
 * Andrew's Monotone Chain Algorithm
 * Finding Convex Hull
 * 
 * (c) 2013 Sylap Aliyev <sylapaliyev@gmail.com>
 * 17/12/2013
 * */

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <stack>
#include <deque>
#define  DBG(X)		cerr << #X << " : " << X << "\n"
using namespace std;

class Point {
	public:
		double x, y;
		
		Point(double x = 0, double y = 0) : x(x), y(y) {}
};

class Vector {
	public:
		double x, y;
		
		Vector(Point origin, Point point) : x(point.x-origin.x), y(point.y-origin.y) {}
		double operator ^(Vector other) {
			return x*other.y - other.x*y;
		}
};

const int MAXN = 1e5;
int n;
Point p[MAXN];
deque<Point> hull;

bool cmp(const Point &a, const Point &b) { return a.x < b.x || (a.x == b.x && a.y < b.y); }

void andrey(int n, Point *p,  hull) {
	sort(p, p+n, cmp);
	
	
}

int main() {
	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> p[i].x >> p[i].y;
	
	andrey(n, p, hull);
	
	return 0;
}
