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

    int n, m;
    cin >> n >> m;
    multiset<ll> tickets;
    for(int i = 0; i<n; ++i)
    {
        ll x;
        cin >> x;
        tickets.insert(-x); // insert negated values of ticket prices, to use std::lower_bound
    }
    for(int i = 0; i<m; ++i)
    {
        ll max_p;
        cin >> max_p;
        auto iter = tickets.lower_bound(-max_p);
        if(iter == tickets.end()) cout << -1 << '\n';
        else
        {
            cout << -(*iter) << '\n';
            tickets.erase(iter);
        }
    }
}