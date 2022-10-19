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
vector<int> adj[maxn + 10];
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
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            edges.pb({i, j});
    shuffle(edges.begin(), edges.end(), mt);
    vector<pair<int,int>> res;
    for (auto it : edges)
        if (ds.join(it.fi, it.se))
            res.pb({it.fi, it.se});
    cout << n << '\n';
    for (auto i : res) cout << i.fi << ' ' << i.se << '\n';
}
