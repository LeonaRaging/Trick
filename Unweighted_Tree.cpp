#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define int long long
#define pb push_back
#define db(val) "[" #val " = " << (val) << "] "
using namespace std;
const ll mod = 20;
const int maxn = 20;
const int INF = 10;

struct Dsu {
    vector<int> par, Rank;
    void init(int n) {
        par.resize(n + 1);
        Rank.resize(n + 1);
        for (int i = 1; i <= n; i++) par[i] = i, Rank[i] = 1;
    }
    int find(int x) {
        if (x != par[x]) par[x] = find(par[x]);
        return par[x];
    }
    bool join(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return 0;
        if (Rank[u] < Rank[v]) swap(u, v);
        Rank[u] += Rank[v];
        par[v] = u;
        return 1;
    }
} ds;

int n, par[maxn + 10], a[maxn + 10];
set<int> adj[maxn + 10];
vector<pair<int,int>> edges;

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

int get(int l, int r) {
    return l + mt() % (r - l + 1);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen(".INP", "r", stdin);
    //freopen(".OUT", "w", stdout);
    edges.clear();
    for (int i = 1; i <= n; i++) adj[i].clear(), par[i] = 0;
    n = 10;
    ds.init(n);
    while(1) {
        int u = mt() % n + 1;
        int v = mt() % n + 1;
        if (u > v) swap(u, v);
        if (ds.join(u, v)) {
            adj[u].insert(v);
            adj[v].insert(u);
            edges.pb({u, v});
        }
        if (ds.Rank[ds.find(1)] == n) break;
    }
    cout << n << '\n';
    for (auto it : edges) {
        int u, v; tie(u, v) = it;
        cout << u << ' ' << v << '\n';
    }
}
