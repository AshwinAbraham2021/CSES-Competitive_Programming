#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N;
    cin >> N;
    vector<ll> a(N);
    for(ll i = 0; i < N; ++i)
    {
        cin >> a[i];
    }
    ll num_op = 0;
    for(ll i = 0; i < N; ++i)
    {
        ll val;
        cin >> val;
        if(val < a[i])
        {
            cout << "-1\n";
            return 0;
        }
        num_op += (val - a[i]);
    }
    cout << num_op << '\n';
}