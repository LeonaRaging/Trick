#include <bits/stdc++.h>
using namespace std;

#define db(val) "[" #val " = " << (val) << "] "

const int maxn = 1e5 + 4;

const double EPS = 1e-9;
const int INF = 2;

int gauss (vector < vector<double> > a, vector<double> & ans) {
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;

    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i)
            if (abs (a[i][col]) > abs (a[sel][col]))
                sel = i;
        if (abs (a[sel][col]) < EPS)
            continue;
        for (int i=col; i<=m; ++i)
            swap (a[sel][i], a[row][i]);
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row) {
                double c = a[i][col] / a[row][col];
                for (int j=col; j<=m; ++j)
                    a[i][j] -= a[row][j] * c;
            }
        ++row;
        for (int i = 0; i < n; i++)
        	for (int j = 0; j <= m; j++)
        		clog << fixed << setprecision(2) << a[i][j] << (j == m ? '\n' : ' ');
        clog << '\n';
    }

    ans.assign (m, 0);
    for (int i=0; i<m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m] / a[where[i]][i];
    for (int i=0; i<n; ++i) {
        double sum = 0;
        for (int j=0; j<m; ++j)
            sum += ans[j] * a[i][j];
        if (abs (sum - a[i][m]) > EPS)
            return 0;
    }

    for (int i=0; i<m; ++i)
        if (where[i] == -1)
            return INF;
    return 1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<double>> a(n, vector<double>(m, 0));
    for (int i = 0; i < n; i++)
    	for (int j = 0; j < m; j++)
    		cin >> a[i][j];
    vector<double> ans;
    gauss(a, ans);
    for (auto x : ans) cout << fixed << setprecision(2) << x << ' ';
}

