struct line {
	int a, b;
	line(int a = 0, int b = 0): a(a), b(b) {}
};

int f(line d, int x) {
	return d.a * x + d.b;
}

struct seg_tree {
	vector<line> t;
	seg_tree() {
		t.resize(4 * maxn);
	}
	void update(line val, int v = 1, int l = 1, int r = maxn - 1) {
		int m = (l + r) / 2;
		bool lef = f(val, l) > f(t[v], l);
		bool mid = f(val, m) > f(t[v], m);
		if (mid) swap(t[v], val);
		if (l == r) return;
		if (lef != mid) update(val, 2 * v, l, m);
		else update(val, 2 * v + 1, m + 1, r);
	}
	int get(int pos, int v = 1, int l = 1, int r = maxn - 1) {
		int res = f(t[v], pos);
		if (l == r) return res;
		int m = (l + r) / 2;
		if (pos <= m) res = max(res, get(pos, 2 * v, l, m));
		else res = max(res, get(pos, 2 * v + 1, m + 1, r));
		return res;
	}
} IT;
