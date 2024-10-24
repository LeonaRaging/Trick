 int n, tin[maxn], head[maxn], chain[maxn], h[maxn], sz[maxn], par[maxn], len[maxn], mx[maxn];
vector<int> adj[maxn];

void dfs(int u, int p) {
    sz[u] = 1;
    for (int v : adj[u]) if (v != p) {
        h[v] = h[u] + 1;
        par[v] = u;
        dfs(v, u);
        sz[u] += sz[v];
    }
}
 
void hld(int u) {
    tin[u] = ++tin[0];
    pos[tin[0]] = u;
    chain[u] = chain[0];
    len[chain[u]]++;
    if (!head[chain[u]]) head[chain[u]] = u;
    int mx = 0;
    for (int v : adj[u])
        if (v != par[u] && sz[v] > sz[mx])
            mx = v;
    if (mx) hld(mx);
    for (int v : adj[u])
        if (v != par[u] && v != mx) {
            chain[0]++;
            hld(v);
        }
}

int get(int u, int v) {
    int res = 0;
    while (chain[u] != chain[v]) {
        if (h[head[chain[u]]] < h[head[chain[v]]])
            swap(u, v);
        int s = head[chain[u]];
        u = par[head[chain[u]]];
    }
    if (h[u] < h[v]) swap(u, v);
    return res;
}
