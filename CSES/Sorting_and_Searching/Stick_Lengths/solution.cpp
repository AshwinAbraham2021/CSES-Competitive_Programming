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
    vector<ll> p(n);

    for(int i = 0; i<n; ++i) cin >> p[i];

    sort(p.begin(), p.end());

    ll min_cost = 0;
    for(int i = 0; i<n; ++i)
    {
        min_cost += abs(p[i] - p[n/2]);
    }
    cout << min_cost << '\n';
}