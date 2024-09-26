#include<bits/stdc++.h>
using namespace std;

#define double long double

const double EPS = 1e-11;

int n, m;
double a[1005][1005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	if (fopen(".INP", "r")) {
		freopen(".INP", "r", stdin);
		freopen(".OUT", "w", stdout);
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
		a[i][n + i] = 1;
	}
	for (int col = 0; col < n; col++) {
		int sel = col;
		for (int row = col; row < n; row++)
			if (abs(a[row][col]) > abs(a[sel][col]))
				sel = row;
		if (abs(a[sel][col]) < EPS) return cout << "not exist", 0;
		if (sel != col)
			for (int i = 0; i < 2 * n; i++)
				swap(a[col][i], a[sel][i]);
		for (int row = 0; row < n; row++) if (row != col) {
			double val = a[row][col] / a[col][col];
			for (int i = 0; i < 2 * n; i++)
				a[row][i] -= val * a[col][i];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 2 * n; j++)
				clog << a[i][j] << ' ';
			clog << '\n';
		}
		clog << '\n';
	}
	for (int col = 0; col < n; col++) {
		double val = a[col][col];	
		for (int i = 0; i < 2 * n; i++)
			a[col][i] /= val;
	}
	for (int i = 0; i < n; i++) {
		for (int j = n; j < 2 * n; j++)
			cout << a[i][j] << ' ';
		cout << '\n';
	}
	cout << '\n';
}
