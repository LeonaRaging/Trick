int low[nmax];
int num[nmax];
int child[nmax];
bool vis[nmax];
bool arti[nmax];
bool bridge[nmax];
int cnt = 0;
void dfs_bridge_ap(int u)
{
     low[u] = n + 1;
     num[u] = ++cnt;
     for(auto v : a[u])
     {
         if(!vis[v.se])
         {
             vis[v.se] = 1;
             if(!num[v.fi])
             {
                child[u]++;
                dfs_bridge_ap(v.fi);
                low[u] = min(low[u], low[v.fi]);
                if(low[v.fi] > num[u])
                    bridge[v.se] = 1;
                if(low[v.fi] >= num[u])
                    arti[u] = 1;
             }
             else
                 low[u] = min(low[u], num[v.fi]);
         }
     }
}
