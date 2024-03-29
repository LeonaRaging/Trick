struct Edge {
    int u, v, flow, capa, cost;
    Edge (int _u, int _v, int _capa, int _cost) {
        u = _u; v = _v; capa = _capa; cost = _cost; flow = 0;
    }
};

int inq[N], dis[N], trace[N];
vector<int> adj[N];
vector<Edge> edges;

void addedge(int u, int v, int w, int c) {
    adj[u].pb(edges.size());
    edges.pb(Edge(u, v, w, c));
    adj[v].pb(edges.size());
    edges.pb(Edge(v, u, 0, -c));
}

bool FindPath(int src, int snk) {
    memset(inq, false, sizeof inq);
    memset(dis, 63, sizeof dis);
    queue<int> q;
    q.push(src);
    dis[src] = 0; inq[src] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        inq[u] = 0;
        for (auto idx : adj[u]) {
            int v = edges[idx].v, w = edges[idx].cost;
            if (edges[idx].flow < edges[idx].capa && dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                trace[v] = idx;
                if (!inq[v]) {
                    inq[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return (dis[snk] != dis[N - 1]);
}

int MinCost(int src, int snk) {
    int flow = 0, cost = 0;
    while (FindPath(src, snk)) {
        int delta = INF;
        for (int u = snk; u != src; u = edges[trace[u]].u)
            delta = min(delta, edges[trace[u]].capa - edges[trace[u]].flow);
        for (int u = snk; u != src; u = edges[trace[u]].u) {
            edges[trace[u]].flow += delta;
            edges[trace[u] ^ 1].flow -= delta;
            cost += delta * edges[trace[u]].cost;
        }
        flow += delta;
    }
    return cost;
}
