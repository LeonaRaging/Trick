#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 4;

int n, m, idg[maxn], vis[maxn];
set<int> adj[maxn];
 
void dfs(int u)
{
    vis[u] = 1;
    for (auto v : adj[u]) {
        if (!vis[v]) dfs(v);
    }
}
 
bool has_euler()
{
    for (int i = 1; i <= n; i++) if (idg[i] % 2 != 0) return false;
    dfs(1); 
    for (int i = 1; i <= n; i++) if (!vis[i] and idg[i]) {
        return false;
    }
    return true;
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
        idg[u]++; idg[v]++;
    }
    if (!has_euler()) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    stack<int> st; st.push(1); vector<int> res;
    while (!st.empty())
    {
        int u = st.top();
        if (adj[u].empty()) {
            res.push_back(u);
            st.pop();
        }
        else {
            int v = *adj[u].begin();
            adj[u].erase(v);
            adj[v].erase(u);
            idg[u]--; idg[v]--;
            st.push(v);
        }
    }
    for (auto i : res) cout << i << ' ';
