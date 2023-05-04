struct line {
	int a, b;
	line(int a = 0, int b = 0):
		a(a), b(b) {}
};

int f(line d, int x) {
	return d.a * x + d.b;
}

struct seg_tree {
	vector<line> t;
	seg_tree() {
		t.resize(4 * maxn);
	}
	void update(line val, int l = 1, int r = maxn - 1, int v = 1, int tl = 1, int tr = maxn - 1) {
		if (tl > r || tr < l) return;
		int m = (tl + tr) / 2;
		if (tl >= l && tr <= r) {
			bool lef = f(val, l) > f(t[v], l);
			bool mid = f(val, m) > f(t[v], m);
			if (mid) swap(t[v], val);
			if (tl == tr) return;
			if (lef != mid) update(val, l, r, 2 * v, tl, m);
			else update(val, l, r, 2 * v + 1, m + 1, tr);
		}
		else {
			update(val, l, r, 2 * v, tl, m);
			update(val, l, r, 2 * v + 1, m + 1, tr);
		}
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
