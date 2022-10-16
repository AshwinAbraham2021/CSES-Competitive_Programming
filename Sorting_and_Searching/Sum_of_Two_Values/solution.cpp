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
    vector<pair<ll, int>> arr(n);
    for(int i = 0; i<n; ++i)
    {
        cin >> arr[i].first;
        arr[i].second = 1+i;
    }

    sort(arr.begin(), arr.end());

    int lptr = 0, rptr = n-1;
    while(lptr < rptr)
    {
        if(arr[lptr].first + arr[rptr].first > x) --rptr;
        else if(arr[lptr].first + arr[rptr].first < x) ++lptr;
        else
        {
            if(arr[lptr].second < arr[rptr].second) cout << arr[lptr].second << ' ' << arr[rptr].second << '\n';
            else cout << arr[rptr].second << ' ' << arr[lptr].second << '\n';
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";
}