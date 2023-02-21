struct Node {
	int nxt[26], go[26], link;
	bool leaf;
	Node() {
		memset(nxt, 0, sizeof nxt);
		memset(go, 0, sizeof go);
		leaf = false; link = 0;
	}
};

vector<Node> t(1);

void add_string(string s) {
	int v = 0;
	for (int i = 0; i < (int)s.size(); i++) {
		int c = s[i] - 'a';
		if (!t[v].nxt[c]) {
			t[v].nxt[c] = t.size();
			t.emplace_back();
		}
		v = t[v].nxt[c];
	}
	t[v].leaf = 1;
}

void push_links() {
	queue<int> q; q.push(0);
	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (int c = 0; c < 26; c++) {
			int u = t[v].nxt[c];
			if (u) {
				t[u].link = v ? t[t[v].link].go[c] : 0;
				t[v].go[c] = u;
				q.push(u);
			}
			else t[v].go[c] = t[t[v].link].go[c];
		}
	}
}
