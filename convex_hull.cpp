using T = long long;

struct pt {
	T x, y;
	pt(T x = 0, T y = 0): x(x), y(y) {}
	pt operator - (pt o) {return pt(x - o.x, y - o.y);}
};

T cross(pt p, pt q) {return p.x * q.y - p.y * q.x;}

T orient(pt a, pt b, pt c) {return cross(b - a, c - a);}

vector<pt> convexhull(vector<pt> &p, int n) {
	sort(p.begin(), p.end(),[](pt a, pt b) {
		if (a.x != b.x) return a.x < b.x;
		return a.y < b.y;
	});
	vector<pt> hull;
	hull.push_back(p[0]);
	for (int i = 1; i < n; i++) {
		while (hull.size() >= 2 && orient(hull[hull.size() - 2], hull.back(), p[i]) >= 0)
			hull.pop_back();
		hull.push_back(p[i]);
	}
	for (int i = n - 2; i >= 0; i--) {
		while (hull.size() >= 2 && orient(hull[hull.size() - 2], hull.back(), p[i]) >= 0)
			hull.pop_back();
		hull.push_back(p[i]);
	}
	if (n > 1) hull.pop_back();
	return hull;
}
