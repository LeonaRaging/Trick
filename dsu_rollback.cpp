struct DisjointSet {
    int par[maxn], Rank[maxn];
    stack<int> st;
    void init(int n) {
        for (int i = 1; i <= n; i++)
            par[i] = i, Rank[i] = 1;
    }
    int find(int x) {
        while (x != par[x]) x = par[x];
        return x;
    }
    bool join(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return 0;
        if (Rank[u] < Rank[v]) swap(u, v);
        num--;
        Rank[u] += Rank[v];
        par[v] = u;
        st.push(v);
        return 1;
    }
    void rollback(int sz) {
        while (SZ(st) > sz) {
            int v = st.top(); st.pop();
            Rank[par[v]] -= Rank[v];
            num++;
            par[v] = v;
        }
    }
} Dsu;
