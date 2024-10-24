ll mul(ll a, ll b, ll mod)
{
    a %= mod;
    b %= mod;
    ll temp = (long double)a * b / mod;
    return ((a * b - temp * mod) % mod + mod) % mod;
}
