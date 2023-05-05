const int maxn = 5e5 + 4;

struct Node {
	int x, L, R;
	Node(int x = maxn): x(x) {}
};

int num;

struct seg_tree {
	vector<Node> t;
	seg_tree() {
		t.resize(12e6);
	}
	int update(int pos, int val, int v, int l = 1, int r = maxn - 1) {
		if (l == r) {
			t[++num] = val;
			return num;
		}
		int m = (l + r) / 2, cur = ++num;
		if (pos <= m) {
			t[cur].L = update(pos, val, t[v].L, l, m);
			t[cur].R = t[v].R;
		}
		else {
			t[cur].L = t[v].L;
			t[cur].R = update(pos, val, t[v].R, m + 1, r);
		}
		t[cur].x = min(t[t[cur].L].x, t[t[cur].R].x);
		return cur;
	}
	int get(int l, int r, int v, int tl = 1, int tr = maxn - 1) {
		if (tl > r || tr < l) return maxn;
		if (tl >= l && tr <= r) return t[v].x;
		int m = (tl + tr) / 2;
		return min(get(l, r, t[v].L, tl, m), get(l, r, t[v].R, m + 1, tr));
	}
} IT;
