using T = double;

struct pt {
	T x, y;
	pt operator - (pt o) {return {x - o.x, y - o.y};}
	pt (T x = 0, T y = 0): x(x), y(y) {}
};

T dot(pt p, pt q) {return p.x * q.x + p.y * q.y;}

T cross(pt p, pt q) {return p.x * q.y - p.y * q.x;}

T orient(pt a, pt b, pt c) {return cross(b - a, c - a);}

bool properInter(pt a, pt b, pt c, pt d) {
	T oa = orient(c, d, a),
	  ob = orient(c, d, b),
	  oc = orient(a, b, c),
	  od = orient(a, b, d);
	return oa * ob < 0 && oc * od < 0;
}

bool inDisk(pt a, pt b, pt p) {
	return dot(a - p, b - p) <= 0;
}

bool onSegment(pt a, pt b, pt p) {
	return orient(a, b, p) == 0 && inDisk(a, b, p);
}

bool inter(pt a, pt b, pt c, pt d) {
	if (properInter(a, b, c, d)) return 1;
	if (onSegment(a, b, c) || onSegment(a, b, d) || onSegment(c, d, a) || onSegment(c, d, b))
		return 1;
	return 0;
}
