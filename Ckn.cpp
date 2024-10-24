ll gt[nmax], inv[nmax];
ll Ckn(int k, int n, ll mod)
{
    if(k > n)
        return 0;
    ll temp = mul(inv[k], inv[n - k], mod);
    return mul(gt[n], temp, mod);
}
