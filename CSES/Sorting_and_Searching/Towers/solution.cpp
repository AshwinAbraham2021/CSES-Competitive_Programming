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

    multiset<ll> tower_sizes;
    ll x;
    cin >> x;
    tower_sizes.insert(x);
    for(int i = 1; i < n; ++i)
    {
        cin >> x;
        auto it = tower_sizes.upper_bound(x);
        if(it == tower_sizes.end())
        {
            tower_sizes.insert(x);
        }
        else
        {
            tower_sizes.erase(it);
            tower_sizes.insert(x);
        }
    }
    cout << tower_sizes.size() << '\n';
}