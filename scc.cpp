int n, m, res, tin[maxn], low[maxn];
bool vis[maxn];
vector<int> adj[maxn];
stack<int> st;

void dfs(int u) {
	st.push(u);
	tin[u] = low[u] = ++tin[0];
	for (int v : adj[u]) {
		if (vis[v]) continue;
		if (!tin[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		}
		else low[u] = min(low[u], tin[v]);
	}
	if (low[u] == tin[u]) {
		res++;
		int v = - 1;
		while (v != u) {
			v = st.top();
			vis[v] = 1;
			st.pop();
		}
	}
}
