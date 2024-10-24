int sz[nmax];
int h[nmax];
int par[nmax];
int idx[nmax];
int top[nmax];
int ptr = 0;
int tree[nmax * 4];
void update(int node, int l, int r, int idx, int val)
{
     if(l == r)
     {
         tree[node] = val;
         return;
     }
     int mid = (l + r) >> 1;
     if(idx <= mid)
        update(node * 2, l, mid, idx, val);
     else
        update(node * 2 + 1, mid + 1, r, idx, val);
     tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}
int get(int node, int l, int r, int u, int v)
{
    if(r < u || l > v || u > v)
        return 0;
    if(l >= u && r <= v)
        return tree[node];
    int mid = (l + r) >> 1;
    return max(get(node * 2, l, mid, u, v), get(node * 2 + 1, mid + 1, r, u, v));
}
void dfs_build(int u)
{
     sz[u] = 1;
     for(int v : a[u])
     {
         if(v != par[u])
         {
             h[v] = h[u] + 1;
             par[v] = u;
             dfs_build(v);
             sz[u] += sz[v];
         }
     }
}
void dfs_hld(int u, int lst)
{
     idx[u] = ++ptr;
     top[u] = lst;
     update(1, 1, n, idx[u], c[u]);
     int max_sz = 0, heavy = -1;
     for(int v : a[u])
     {
         if(v != par[u] && sz[v] > max_sz)
         {
            max_sz = sz[v];
            heavy = v;
         }
     }
     if(heavy == -1)
        return;
     dfs_hld(heavy, lst);
     for(int v : a[u])
     {
         if(v != par[u] && v != heavy)
            dfs_hld(v, v);
     }
}
int query(int u, int v)
{
    int res = 0;
    while(top[u] != top[v])
    {
          if(h[top[u]] < h[top[v]])
             swap(u, v);
          res = max(res, get(1, 1, n, idx[top[u]], idx[u]));
          u = par[top[u]];
    }
    if(h[u] > h[v])
        swap(u, v);
    res = max(res, get(1, 1, n, idx[u], idx[v]));
    return res;
}
