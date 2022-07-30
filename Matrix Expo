struct Matrix {
    int n, m;
    vector<vector<ll>> a;
    void init() {
        a.resize(n + 1);
        for (int i = 1; i <= n; i++) a[i].resize(m + 1);
    }
};

Matrix Mul(Matrix A, Matrix B)
{
    int n = A.n, m = B.m, k = A.m;
    Matrix C; C.n = n; C.m = m; C.init();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int t = 1; t <= k; t++)
                C.a[i][j] = (C.a[i][j] + (A.a[i][t] * B.a[t][j]) % mod) % mod;
    return C;
}

Matrix Pow(Matrix A, ll b)
{
    if (b == 1) return A;
    Matrix C = Pow(A, b / 2);
    C = Mul(C, C);
    if (b % 2 != 0) C = Mul(C, A);
    return C;
}
