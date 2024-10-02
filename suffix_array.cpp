string s;
int n, gap, pos[maxn], tmp[maxn], sa[maxn], lcp[maxn];

bool sufCmp(int i, int j) {
	if (pos[i] != pos[j]) return pos[i] < pos[j];
	i += gap, j += gap;
	return (i < n && j < n ? pos[i] < pos[j] : i > j);
}

void buildSA() {
	n = s.size();
	for (int i = 0; i < n; i++)
		sa[i] = i, pos[i] = s[i];
	for (gap = 1;; gap *= 2) {
		sort(sa, sa + n, sufCmp);
		for (int i = 0; i < n - 1; i++)
			tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
		for (int i = 0; i < n; i++)
			pos[sa[i]] = tmp[i];
		if (tmp[n - 1] == n - 1) break;
	}
}

void buildLCP() {
	for (int i = 0, k = 0; i < n; i++) if (pos[i] != n - 1) {
		for (int j = sa[pos[i] + 1]; s[i + k] == s[j + k];)
			k++;
		lcp[pos[i]] = k;
		if (k) k--;
	}
}
