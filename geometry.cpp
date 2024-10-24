#include<bits/stdc++.h>
using namespace std;

using T = double;

struct pt {
	T x, y;
	pt operator + (pt o) {return {x + o.x, y + o.y};}
	pt operator - (pt o) {return {x - o.x, y - o.y};}
	pt operator * (T d) {return {x * d, y * d};}
	pt operator / (T d) {return {x / d, y / d};}
	bool operator == (pt a) {return x == a.x && y == a.y;}
	bool operator != (pt a) {return x != a.x && y != a.y;}
	pt (T x = 0, T y = 0): x(x), y(y) {}
};

ostream& operator << (ostream& os, pt p) {
	return os << "(" << p.x << "," << p.y << ")";
}

T sq(pt p) {return p.x * p.x + p.y * p.y;}

double abs(pt p) {return sqrt(sq(p));}

T dot(pt p, pt q) {return p.x * q.x + p.y * q.y;}

T cross(pt p, pt q) {return p.x * q.y - p.y * q.x;}

pt perp(pt p) {return {-p.y, p.x};}

struct line {
	pt v; T c;
	line(pt v, T c): v(v), c(c) {}
	line (T a, T b, T c): v({b, -a}), c(c) {}
	line(pt p, pt q): v(q - p), c(cross(v, p)) {}
	T side(pt p) {return cross(v, p) - c;}
	double dist(pt p) {return abs(side(p)) / abs(v);}
	line perpThrough(pt p) {return {p, p + perp(v)};}
	bool cmpProj(pt p, pt q) {
		return dot(v, p) < dot(v, q);
	}
};

bool isPerp(pt v, pt w) {return dot(v, w) == 0;}

double angle(pt v, pt w) {
	double cosTheta = dot(v, w) / abs(v) / abs(w);
	return acos(max(-1.0, min(1.0, cosTheta)));
}

T orient(pt a, pt b, pt c) {return cross(b - a, c - a);}

bool inAngle(pt a, pt b, pt c, pt p) {
	if (orient(a, b, c) < 0) swap(b, c);
	return orient(a, b, p) >= 0 && orient(a, c, p) <= 0;
}

double orientedAngle(pt a, pt b, pt c) {
	if (orient(a, b, c) >= 0)
		return angle(b - a, c - a);
	return 360 - angle(b - a, c - a);
}

bool isConvex(vector<pt> p) {
	bool hasPos = 0, hasNeg = 0;
	for (int i = 0, n = p.size(); i < n; i++) {
		T o = orient(p[i], p[(i + 1) % n], p[(i + 2) % n]);
		if (o > 0) hasPos = true;
		if (o < 0) hasNeg = true;
	}
	return !(hasPos && hasNeg);
}

bool half(pt p) {
	return p.y > 0 || (p.y == 0 && p.x < 0);
}

void polarSort(vector<pt> &v) {
	sort(v.begin(), v.end(), [](pt v, pt w) {
		return make_tuple(half(v), 0) <
			   make_tuple(half(w), cross(v, w));
	});
}

bool inter(line l1, line l2, pt &out) {
	T d = cross(l1.v, l2.v);
	if (d == 0) return 0;
	out = (l2.v * l1.c - l1.v * l2.c) / d;
	return 1;
}

line bisector(line l1, line l2, bool interior) {
	double sign = interior ? 1 : -1;
	return {l2.v / abs(l2.v) + l1.v / abs(l1.v) * sign,
			l2.c / abs(l2.v) + l1.c / abs(l1.v) * sign};
}

bool properInter(pt a, pt b, pt c, pt d, pt &out) {
	T oa = orient(c, d, a),
	  ob = orient(c, d, b),
	  oc = orient(a, b, c),
	  od = orient(a, b, d);
	if (oa * ob < 0 && oc * od < 0) {
		out = (a * ob - b * oa) / (ob - oa);
		return true;
	}
	return false;
}

bool inDisk(pt a, pt b, pt p) {
	return dot(a - p, b - p) <= 0;
}

bool onSegment(pt a, pt b, pt p) {
	return orient(a, b, p) == 0 && inDisk(a, b, p);
}

vector<pt> inters(pt a, pt b, pt c, pt d) {
	pt out;
	if (properInter(a, b, c, d, out)) return {out};
	vector<pt> s;
	if (onSegment(c, d, a)) s.push_back(a);
	if (onSegment(c, d, b)) s.push_back(b);
	if (onSegment(a, b, c)) s.push_back(c);
	if (onSegment(a, b, d)) s.push_back(d);
	return s;
}

double segPoint(pt a, pt b, pt p) {
	if (a != b) {
		line l(a, b);
		if (l.cmpProj(a, p) && l.cmpProj(p, b))
			return l.dist(p);
	}
	return min(abs(p - a), abs(p - b));
}

double segSeg(pt a, pt b, pt c, pt d) {
	pt dummy;
	if (properInter(a, b, c, d, dummy))
		return 0;
	return min({segPoint(a, b, c), segPoint(a, b, d),
				segPoint(c, d, a), segPoint(c, d, b)});
}

double areaPolygon(vector<pt> p) {
	double area = 0.0;
	for (int i = 0, n = p.size(); i < n; i++) {
		area += cross(p[i], p[(i + 1) % n]);
	}
	return abs(area) / 2.0;
}

bool above(pt a, pt p) { return p.y >= a.y;}

bool crossesRay(pt a, pt p, pt q) {
	return (above(a, q) - above(a, p)) * orient(a, p, q) > 0;
}

bool inPolygon(vector<pt> p, pt a, bool strict = true) {
	int numCrossings = 0;
	for (int i = 0, n = p.size(); i < n; i++) {
		if (onSegment(p[i], p[(i + 1) % n], a))
			return !strict;
		numCrossings += crossesRay(a, p[i], p[(i + 1) % n]);	
	}
	return numCrossings & 1;
}

int main() {
}
