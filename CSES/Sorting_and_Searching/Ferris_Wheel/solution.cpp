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
    ll x;
    cin >> n >> x;
    vector<pair<ll, bool>> weights(n);
    for(int i = 0; i<n; ++i)
    {
        ll x;
        cin >> x;
        weights[i] = pair<ll, bool>(x, false); // second element checks whether it has been picked or not
    }

    sort(weights.begin(), weights.end());
    int num_gondolas = 0;
    int lptr = 0;
    int rptr = n-1;
    while(lptr < rptr)
    {
        if(weights[lptr].first + weights[rptr].first > x) --rptr;
        else
        {
            weights[lptr].second = true;
            weights[rptr].second = true;
            ++lptr;
            --rptr;
            ++num_gondolas;
        }
    }
    for(int i = 0; i<n; ++i)
    {
        if(!weights[i].second) ++num_gondolas;
    }
    cout << num_gondolas << '\n';
}