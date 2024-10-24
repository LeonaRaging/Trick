int h[nmax], up[nmax][25];
vector<int> a[nmax];
void dfs(int u)
{
    for(int v : a[u])
    {
        if(v == up[u][0])
            continue;
        h[v] = h[u] + 1;
        up[v][0] = u;
        for(int j = 1; j < 20; j++)
            up[v][j] = up[up[v][j - 1]][j - 1];
        dfs(v);
    }
}
int lca(int u, int v)
{
    if(h[u] != h[v])
    {
        if(h[u] < h[v])
            swap(u, v);
        int dist = h[u] - h[v];
        for(int j = 0; (1 << j) <= dist; j++)
            if(dist >> j & 1)
               u = up[u][j];
    }
    if(u == v)
        return u;
    int dist = log2(h[u]);
    for(int j = dist; j >= 0; j--)
    {
        if(up[u][j] != up[v][j])
        {
           u = up[u][j];
           v = up[v][j];
        }
    }
    return up[u][0];
}
