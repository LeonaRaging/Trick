struct Matrix {
	int r, c;
	vector<vector<int>> a;
	Matrix (int r = 0, int c = 0): r(r), c(c) {
		a.resize(r + 4);
		for (int i = 0; i <= r; i++)
			a[i].resize(c + 4);
	}
};

Matrix Mul(Matrix A, Matrix B) {
	int r = A.r, c = B.c, k = A.c;
	Matrix C(r, c);
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			for (int t = 1; t <= k; t++)
				C.a[i][j] = (C.a[i][j] + A.a[i][t] * B.a[t][j]);
	return C;
}

Matrix Pow(Matrix A, ll b) {
	if (b == 1) return A;
	Matrix C = Pow(A, b / 2);
	C  = Mul(C, C);
	if (b & 1) C = Mul(C, A);
	return C;
}
