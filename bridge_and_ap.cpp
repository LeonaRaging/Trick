struct Edge {
	int u, v;
	bool used, bridge;
	int get(int x) {return u ^ v ^ x;}
	Edge(int u = 0, int v = 0): u(u), v(v) {
		used = bridge = false;
	}
};

int n, m, root, tin[maxn], low[maxn], Point[maxn];
vector<Edge> edges;
vector<int> adj[maxn];

void dfs(int u) {
	int child = 0;
	tin[u] = low[u] = ++tin[0];
	for (int i : adj[u]) if (!edges[i].used) {
		edges[i].used = 1;
		int v = edges[i].get(u);
		if (!tin[v]) {
			dfs(v);
			child++;
			low[u] = min(low[u], low[v]);
			edges[i].bridge = low[v] > tin[u];
			if (u == root) Point[u] = child > 1;
			else Point[u] |= low[v] >= tin[u];
		}
		else low[u] = min(low[u], tin[v]);
	}
}
