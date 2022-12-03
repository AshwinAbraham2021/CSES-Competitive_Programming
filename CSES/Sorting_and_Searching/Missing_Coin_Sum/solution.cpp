/*
 * AUTHOR: ASHWIN ABRAHAM
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    multiset<ll> coins;
    set<ll> unq_coins;
    for(int i = 0; i<n; ++i)
    {
        ll x;
        cin >> x;
        coins.insert(x);
        unq_coins.insert(x);
    }
    if(coins.count(1) == 0)
    {
        cout << "1\n";
        return 0;
    }
    ll max_consec_from0 = coins.count(1);
    for(auto x : unq_coins)
    {
        if(x == 1) continue;
        if(x > max_consec_from0 + 1)
        {
            cout << max_consec_from0 + 1 << '\n';
            return 0;
        }
        // 1, 2, ... m
        //      x, x + 1 ... x + m
        //                  2x, 2x + 1 ... 2x + m
        //                        ...
        //                          nx, nx + 1, ... nx + m
        // No number between 1, nx + m is missed (because x <= m + 1)
        max_consec_from0 += x*coins.count(x);
    }
    cout << max_consec_from0 + 1 << '\n';
}