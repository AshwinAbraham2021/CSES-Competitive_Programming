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

    ll x;
    cin >> x;
    int n;
    cin >> n;

    set<ll> lights;
    ll p;
    cin >> p;
    lights.insert(p);
    multiset<ll> lengths;
    lengths.insert(p);
    lengths.insert(x - p);
    cout << (p > x - p ? p : x - p);
    for(int i = 1; i < n; ++i)
    {
        cin >> p;
        auto it = lights.lower_bound(p);
        if(it == lights.begin())
        {
            ll new_len1 = p, new_len2 = *it - p;
            auto itr = lengths.find(*it);
            lengths.erase(itr);
            lengths.insert(new_len1);
            lengths.insert(new_len2);
        }
        else if(it == lights.end())
        {
            ll new_len1 = p - *prev(it), new_len2 = x - p;
            auto itr = lengths.find(x - *prev(it));
            lengths.erase(itr);
            lengths.insert(new_len1);
            lengths.insert(new_len2);
        }
        else
        {
            ll new_len1 = p - *prev(it), new_len2 = *it - p;
            auto itr = lengths.find(*it - *prev(it));
            lengths.erase(itr);
            lengths.insert(new_len1);
            lengths.insert(new_len2);
        }
        lights.insert(p);
        cout << ' ' << *prev(lengths.end());
    }
    cout << '\n';
}