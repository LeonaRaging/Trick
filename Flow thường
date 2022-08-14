struct Edge {
    int u, v, flow, capa;
    Edge (int _u, int _v, int _capa) {
        u = _u; v = _v; capa = _capa; flow = 0;
    }
};
 
int trace[N];
bool vis[N];
vector<Edge> edges;
vector<int> adj[N];
 
void addedge(int u, int v, int w) {
    adj[u][v] = edges.size();
    edges.pb(Edge(u, v, w));
    adj[v][u] = edges.size();
    edges.pb(Edge(v, u, 0));
}
 
int FindPath(int s, int t) {
    memset(vis, false, sizeof vis);
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int id : adj[u]) {
            if (edges[id].flow < edges[id].capa && !vis[edges[id].v]) {
                q.push(edges[id].v);
                vis[edges[id].v] = 1;
                trace[edges[id].v] = id;
            }
        }
    }
    return vis[t];
}
 
int MaxFlow(int s, int t) {
    int res = 0;
    while (FindPath(s, t)) {
        int delta = INF;
        for (int u = t; u != s; u = edges[trace[u]].u) {
            delta = min(delta, edges[trace[u]].capa - edges[trace[u]].flow);
        }
        for (int u = t; u != s; u = edges[trace[u]].u) {
            edges[trace[u]].flow += delta;
            edges[trace[u] ^ 1].flow -= delta;
        }
        res += delta;
    }
    return res;
}
