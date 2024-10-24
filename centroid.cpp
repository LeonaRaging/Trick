struct Centroid_Decomposition {
    int sz[maxn];
    int dfs(int u, int p) {
        sz[u] = 1;
        for (int v : adj[u])
            if (v != p && !used[v])
                sz[u] += dfs(v, u);
        return sz[u];
    }
    int Centroid(int u, int p, int tot) {
        for (int v : adj[u])
            if (v != p && !used[v] && sz[v] > tot / 2)
                return Centroid(v, u, tot);
        return u;
    }
    void build(int u, int p, int dep) {
        int c = Centroid(u, 0, dfs(u, 0));
        cen_dep[c] = dep;
        Solve(c, 0, 0, dep);
        used[c] = 1;
        par[c] = p;
        for (int v : adj[c]) 
            if (!used[v])
                build(v, c, dep + 1);
    }
} Cen;
