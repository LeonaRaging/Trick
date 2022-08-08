#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define int long long
#define pb push_back
#define db(val) "[" #val " = " << (val) << "] "
using namespace std;
const ll mod = 20;
const int maxn = 10;
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

void dfs(int u, int p) {
	par[u] = p;
	for (auto v : adj[u]) {
		if (v == p) continue;
		dfs(v, u);
	}
}

bool ok() {
	if (n == 0) return false;
	for (int i = 1; i <= n; i++) if (i < par[i]) return false;
	return true;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(".INP", "r", stdin);
	//freopen(".OUT", "w", stdout);
 	mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
 		edges.clear();
 		for (int i = 1; i <= n; i++) adj[i].clear(), par[i] = 0;
	 	n = mt() % maxn + 1;
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
	 		int cnt = 0, x = ds.find(1);
	 		for (int i = 1; i <= n; i++) if (ds.find(i) == x) cnt++;
	 		if (cnt == n) break;
	 	}
	 	dfs(1, 0);
	 	cout << n << '\n';
	 	for (int i = 1; i <= n; i++) {
	 		int x = mt() % INF;
	 		a[i] = x;
	 		// cout << a[i] << ' ' << par[i] << '\n';
	 	}
	 	for (auto it : edges) {
	 		int u, v; tie(u, v) = it;
	 		cout << u << ' ' << v << '\n';
	 		// cout << u << ' ' << v << ' ' << (par[u] == v ? a[u] : a[v]) << '\n';
	 	}
}

