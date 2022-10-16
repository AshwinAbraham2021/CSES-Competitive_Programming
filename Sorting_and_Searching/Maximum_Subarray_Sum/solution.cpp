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
    bool all_neg = true;
    ll max_el, max_sub_curr, max_sub;
    cin >> max_el;
    if(max_el >= 0) all_neg = false;
    max_sub_curr = max_el;
    max_sub = max_sub_curr > 0 ? max_sub_curr : 0;
    for(int i = 1; i<n; ++i)
    {
        ll x;
        cin >> x;
        if(x >= 0) all_neg = false;
        max_el = x > max_el ? x : max_el;
        max_sub_curr = max_sub_curr <= 0 ? x : x + max_sub_curr ;
        max_sub = max_sub > max_sub_curr ? max_sub : max_sub_curr;
    }
    if(all_neg) cout << max_el << '\n';
    else cout << max_sub << '\n';
}