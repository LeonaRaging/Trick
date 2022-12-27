#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define db(val) "[" #val " = " << (val) << "] "

const int maxn = 2500;

int x, y, m, t, mt[maxn], vis[maxn];
bool used[maxn]; 
vector<int> adj[maxn];

bool try_kuhn(int u) {
	if (vis[u] != t)
		vis[u] = t;
	else return 0;
	for (int v : adj[u]) {
		if (!mt[v] || try_kuhn(mt[v])) {
			mt[v] = u;
			return 1;
		}
	}
	return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> x >> y >> m;
    for (int i = 1, u, v; i <= m; i++) {
    	cin >> u >> v; v += x;
    	adj[u].pb(v);
    }
    for (int u = 1; u <= x; u++) {
    	for (int v : adj[u])
    		if (!mt[v]) {
    			mt[v] = u;
    			used[u] = 1;
    			break;
    		}
    }
    for (int u = 1; u <= x; u++) {
    	if (used[u]) continue;
    	t = u;
    	try_kuhn(u);
    }
    int res = 0;
    for (int u = x + 1; u <= x + y; u++)
    	if (mt[u]) res++;
    cout << res;
}

