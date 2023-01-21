#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

constexpr ll MOD_NUM = 1'000'000'007;

ll facts[100'001];

ll fact(ll n)
{
    ll i = n;
    for(; facts[i] == 0; --i);
    for(ll j = i + 1; j <= n; ++j) facts[j] = (j*facts[j - 1]) % MOD_NUM;
    return facts[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    facts[0] = 1;

    int t;
    cin >> t;

    for(int i = 0; i < t; ++i)
    {
        ll n;
        cin >> n;
        cout << ((n*(n - 1) % MOD_NUM) * fact(n)) % MOD_NUM << '\n';
    }
}